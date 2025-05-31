
#ifndef MESSAGE_21_H
#define MESSAGE_21_H

#include <Arduino.h>
#include "Libsqru/utils/AISUtils.h"

struct AISMessage21 {
  uint8_t message_id = 21;          // 6 bits
  uint8_t repeat_indicator;         // 2 bits
  uint32_t mmsi;                    // 30 bits
  uint8_t aid_type;                 // 5 bits
  String name;                      // 120 bits (20 chars)
  bool position_accuracy;           // 1 bit
  float longitude;                  // 28 bits
  float latitude;                   // 27 bits
  uint16_t dimension_to_bow;        // 9 bits
  uint16_t dimension_to_stern;      // 9 bits
  uint8_t dimension_to_port;        // 6 bits
  uint8_t dimension_to_starboard;   // 6 bits
  uint8_t epfd_type;                // 4 bits
  uint8_t utc_second;               // 6 bits
  bool off_position;                // 1 bit
  uint8_t regional;                 // 8 bits
  bool raim_flag;                   // 1 bit
  bool virtual_aton_flag;           // 1 bit
  bool assigned_mode_flag;          // 1 bit
  uint8_t spare;                    // 1 bit
};

String encodeMessage21(const AISMessage21& msg);

#endif
