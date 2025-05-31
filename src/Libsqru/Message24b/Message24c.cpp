#include "Message24B.h"

String encodeMessage24B(const AISMessage24B& msg) {
  uint8_t bits[21] = {0}; // 168 bits = 21 bytes
  writeBits(bits, msg.message_id, 0, 6);
  writeBits(bits, msg.repeat_indicator, 6, 2);
  writeBits(bits, msg.mmsi, 8, 30);
  writeBits(bits, msg.part_number, 38, 2);
  writeBits(bits, msg.ship_type, 40, 8);
  encodeStringToBits(msg.vendor_id, bits, 48, 7);
  encodeStringToBits(msg.callsign, bits, 90, 7);
  writeBits(bits, msg.dim_bow, 132, 9);
  writeBits(bits, msg.dim_stern, 141, 9);
  writeBits(bits, msg.dim_port, 150, 6);
  writeBits(bits, msg.dim_starboard, 156, 6);
  writeBits(bits, msg.spare, 162, 6);
  
  char payload[29];
  bitsToAISString(bits, 168, payload);
  return createNMEAMessage(payload);
}
