#ifndef MESSAGE_14_H
#define MESSAGE_14_H

#include <Arduino.h>
#include "Libsqru/utils/AISUtils.h"

struct AISMessage14 {
  uint8_t message_id = 14;    // 6 bits
  uint8_t repeat_indicator;   // 2 bits
  uint32_t mmsi;              // 30 bits
  uint8_t spare;              // 2 bits
  String safety_text;         // Up to 968 bits (161 characters in 6-bit ASCII)
};

String encodeMessage14(const AISMessage14& msg);

#endif
