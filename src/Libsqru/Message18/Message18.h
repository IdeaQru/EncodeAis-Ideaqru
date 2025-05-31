#ifndef MESSAGE_18_H
#define MESSAGE_18_H

#include <Arduino.h>
#include "Libsqru/utils/AISUtils.h"

struct AISMessage18 {
  uint8_t message_id = 18;    // 6 bits
  uint8_t repeat_indicator;   // 2 bits
  uint32_t mmsi;              // 30 bits
  uint8_t reserved;           // 8 bits
  uint16_t sog;               // 10 bits (Speed Over Ground * 10)
  bool position_accuracy;     // 1 bit
  float longitude;            // 28 bits
  float latitude;             // 27 bits
  uint16_t cog;               // 12 bits (Course Over Ground * 10)
  uint16_t heading;           // 9 bits (True Heading)
  uint8_t utc_second;         // 6 bits
  uint8_t regional;           // 2 bits
  bool cs_flag;               // 1 bit (Carrier Sense)
  bool display_flag;          // 1 bit
  bool dsc_flag;              // 1 bit
  bool band_flag;             // 1 bit
  bool msg22_flag;            // 1 bit
  bool assigned_flag;         // 1 bit
  bool raim_flag;             // 1 bit
  uint32_t radio_status;      // 20 bits
};

String encodeMessage18(const AISMessage18& msg);

#endif
