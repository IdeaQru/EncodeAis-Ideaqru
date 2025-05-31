#include "Message14.h"

String encodeMessage14(const AISMessage14& msg) {
  // Maximum text length is 161 characters (968 bits / 6 bits per char)
  uint16_t textLength = msg.safety_text.length();
  if (textLength > 161) {
    textLength = 161;
  }
  uint16_t totalBits = 40 + (textLength * 6); // 40 bits header + text bits
  uint16_t byteCount = (totalBits + 7) / 8; // Round up to nearest byte
  
  uint8_t bits[byteCount] = {0}; // Buffer for bits
  writeBits(bits, msg.message_id, 0, 6);
  writeBits(bits, msg.repeat_indicator, 6, 2);
  writeBits(bits, msg.mmsi, 8, 30);
  writeBits(bits, msg.spare, 38, 2);
  encodeStringToBits(msg.safety_text, bits, 40, textLength);
  
  uint16_t charCount = (totalBits + 5) / 6; // Number of 6-bit characters for payload
  char payload[charCount + 1]; // +1 for null terminator
  bitsToAISString(bits, totalBits, payload);
  return createNMEAMessage(payload);
}
