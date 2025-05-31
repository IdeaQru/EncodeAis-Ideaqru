#ifndef MESSAGE_24B_H
#define MESSAGE_24B_H

#include <Arduino.h>
#include "Libsqru/utils/AISUtils.h"

struct AISMessage24B {
  uint8_t message_id = 24;    // 6 bits
  uint8_t repeat_indicator;   // 2 bits
  uint32_t mmsi;              // 30 bits
  uint8_t part_number = 1;    // 2 bits (1 for Part B)
  uint8_t ship_type;          // 8 bits
  String vendor_id;           // 42 bits (7 chars)
  String callsign;            // 42 bits (7 chars)
  uint16_t dim_bow;           // 9 bits
  uint16_t dim_stern;         // 9 bits
  uint8_t dim_port;           // 6 bits
  uint8_t dim_starboard;      // 6 bits
  uint8_t spare;              // 6 bits
};

String encodeMessage24B(const AISMessage24B& msg);

#endif
