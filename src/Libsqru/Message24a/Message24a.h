#ifndef MESSAGE_24A_H
#define MESSAGE_24A_H

#include <Arduino.h>
#include "Libsqru/utils/AISUtils.h"

struct AISMessage24A {
  uint8_t message_id = 24;    // 6 bits
  uint8_t repeat_indicator;   // 2 bits
  uint32_t mmsi;              // 30 bits
  uint8_t part_number = 0;    // 2 bits (0 for Part A)
  String ship_name;           // 120 bits (20 chars)
};

String encodeMessage24A(const AISMessage24A& msg);

#endif
