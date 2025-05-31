#include "Message1_2_3.h"

String encodeMessage1_2_3(const AISMessage1_2_3& msg) {
  uint8_t bits[21] = {0}; // 168 bits = 21 bytes
  writeBits(bits, msg.message_id, 0, 6);
  writeBits(bits, msg.repeat_indicator, 6, 2);
  writeBits(bits, msg.mmsi, 8, 30);
  writeBits(bits, msg.nav_status, 38, 4);
  writeBits(bits, msg.rot, 42, 8, true);
  writeBits(bits, msg.sog, 50, 10);
  writeBits(bits, msg.position_accuracy ? 1 : 0, 60, 1);
  int32_t lng_enc = (int32_t)round(msg.longitude * 600000.0);
  writeBits(bits, lng_enc, 61, 28, true);
  int32_t lat_enc = (int32_t)round(msg.latitude * 600000.0);
  writeBits(bits, lat_enc, 89, 27, true);
  writeBits(bits, msg.cog, 116, 12);
  writeBits(bits, msg.heading, 128, 9);
  writeBits(bits, msg.utc_second, 137, 6);
  writeBits(bits, msg.maneuver, 143, 2);
  writeBits(bits, msg.raim_flag ? 1 : 0, 145, 1);
  writeBits(bits, msg.radio_status, 146, 19);
  
  char payload[29];
  bitsToAISString(bits, 168, payload);
  return createNMEAMessage(payload);
}
