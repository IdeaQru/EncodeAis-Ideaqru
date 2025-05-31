#include "Message24A.h"

String encodeMessage24A(const AISMessage24A& msg) {
  uint8_t bits[21] = {0}; // 168 bits = 21 bytes
  writeBits(bits, msg.message_id, 0, 6);
  writeBits(bits, msg.repeat_indicator, 6, 2);
  writeBits(bits, msg.mmsi, 8, 30);
  writeBits(bits, msg.part_number, 38, 2);
  encodeStringToBits(msg.ship_name, bits, 40, 20);
  
  char payload[29];
  bitsToAISString(bits, 168, payload);
  return createNMEAMessage(payload);
}
