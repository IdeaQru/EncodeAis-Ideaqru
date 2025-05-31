#ifndef MESSAGE_1_2_3_H
#define MESSAGE_1_2_3_H

#include <Arduino.h>
#include "Libsqru/utils/AISUtils.h"

struct AISMessage1_2_3 {
  uint8_t message_id;         // 6 bits (1, 2, or 3)
  uint8_t repeat_indicator;   // 2 bits
  uint32_t mmsi;              // 30 bits
  uint8_t nav_status;         // 4 bits
  int8_t rot;                 // 8 bits (Rate of Turn)
  uint16_t sog;               // 10 bits (Speed Over Ground * 10)
  bool position_accuracy;     // 1 bit
  float longitude;            // 28 bits
  float latitude;             // 27 bits
  uint16_t cog;               // 12 bits (Course Over Ground * 10)
  uint16_t heading;           // 9 bits (True Heading)
  uint8_t utc_second;         // 6 bits
  uint8_t maneuver;           // 2 bits
  bool raim_flag;             // 1 bit
  uint32_t radio_status;      // 19 bits
};

String encodeMessage1_2_3(const AISMessage1_2_3& msg);

#endif
