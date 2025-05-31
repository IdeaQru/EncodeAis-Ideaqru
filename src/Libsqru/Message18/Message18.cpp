#include "Message18.h"

String encodeMessage18(const AISMessage18& msg) {
  uint8_t bits[21] = {0}; // 168 bits = 21 bytes
  writeBits(bits, msg.message_id, 0, 6);
  writeBits(bits, msg.repeat_indicator, 6, 2);
  writeBits(bits, msg.mmsi, 8, 30);
  writeBits(bits, msg.reserved, 38, 8);
  writeBits(bits, msg.sog, 46, 10);
  writeBits(bits, msg.position_accuracy ? 1 : 0, 56, 1);
  int32_t lng_enc = (int32_t)round(msg.longitude * 600000.0);
  writeBits(bits, lng_enc, 57, 28, true);
  int32_t lat_enc = (int32_t)round(msg.latitude * 600000.0);
  writeBits(bits, lat_enc, 85, 27, true);
  writeBits(bits, msg.cog, 112, 12);
  writeBits(bits, msg.heading, 124, 9);
  writeBits(bits, msg.utc_second, 133, 6);
  writeBits(bits, msg.regional, 139, 2);
  writeBits(bits, msg.cs_flag ? 1 : 0, 141, 1);
  writeBits(bits, msg.display_flag ? 1 : 0, 142, 1);
  writeBits(bits, msg.dsc_flag ? 1 : 0, 143, 1);
  writeBits(bits, msg.band_flag ? 1 : 0, 144, 1);
  writeBits(bits, msg.msg22_flag ? 1 : 0, 145, 1);
  writeBits(bits, msg.assigned_flag ? 1 : 0, 146, 1);
  writeBits(bits, msg.raim_flag ? 1 : 0, 147, 1);
  writeBits(bits, msg.radio_status, 148, 20);
  
  char payload[29];
  bitsToAISString(bits, 168, payload);
  return createNMEAMessage(payload);
}
