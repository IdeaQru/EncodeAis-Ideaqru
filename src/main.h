#include <Arduino.h>
#include <Libsqru/AISMessages.h>

void setupTrial()
{
    Serial.begin(115200);
    delay(1000);
    Serial.println("AIS Messages Library Test");
    Serial.println("=========================");
    Serial.println();

    // Test Message 1 (Position Report Class A)
    Serial.println("Testing AIS Message 1 (Position Report Class A):");
    AISMessage1_2_3 msg1;
    msg1.message_id = 1;
    msg1.repeat_indicator = 0;
    msg1.mmsi = 123456789;
    msg1.nav_status = 0; // Under way using engine
    msg1.rot = 0;
    msg1.sog = 50; // 5.0 knots
    msg1.position_accuracy = true;
    msg1.longitude = 106.8456;
    msg1.latitude = -6.2088;
    msg1.cog = 900; // 90.0 degrees
    msg1.heading = 90;
    msg1.utc_second = 30;
    msg1.maneuver = 0;
    msg1.raim_flag = false;
    msg1.radio_status = 0;
    String nmea1 = encodeMessage1_2_3(msg1);
    Serial.println("Message 1 NMEA: " + nmea1);
    Serial.println();

    // Test Message 2 (Position Report Class A - Similar to 1)
    Serial.println("Testing AIS Message 2 (Position Report Class A):");
    AISMessage1_2_3 msg2;
    msg2.message_id = 2;
    msg2.repeat_indicator = 0;
    msg2.mmsi = 123456789;
    msg2.nav_status = 1; // At anchor
    msg2.rot = 0;
    msg2.sog = 0; // 0.0 knots
    msg2.position_accuracy = true;
    msg2.longitude = 106.8456;
    msg2.latitude = -6.2088;
    msg2.cog = 0;
    msg2.heading = 0;
    msg2.utc_second = 30;
    msg2.maneuver = 0;
    msg2.raim_flag = false;
    msg2.radio_status = 0;
    String nmea2 = encodeMessage1_2_3(msg2);
    Serial.println("Message 2 NMEA: " + nmea2);
    Serial.println();

    // Test Message 3 (Position Report Class A - Similar to 1)
    Serial.println("Testing AIS Message 3 (Position Report Class A):");
    AISMessage1_2_3 msg3;
    msg3.message_id = 3;
    msg3.repeat_indicator = 0;
    msg3.mmsi = 123456789;
    msg3.nav_status = 5; // Moored
    msg3.rot = 0;
    msg3.sog = 0; // 0.0 knots
    msg3.position_accuracy = true;
    msg3.longitude = 106.8456;
    msg3.latitude = -6.2088;
    msg3.cog = 0;
    msg3.heading = 0;
    msg3.utc_second = 30;
    msg3.maneuver = 0;
    msg3.raim_flag = false;
    msg3.radio_status = 0;
    String nmea3 = encodeMessage1_2_3(msg3);
    Serial.println("Message 3 NMEA: " + nmea3);
    Serial.println();
    Serial.println("Testing AIS Message 8 (Binary Broadcast Message):");
    AISMessage8 msg8;
    msg8.repeat_indicator = 0;
    msg8.mmsi = 123456789;
    msg8.spare = 0;
    msg8.dac = 1; // International application
    msg8.fi = 30; // Example functional ID (meteorological data)
    msg8.temperature = 31.7;
    msg8.humidity = 20;
    msg8.wind_speed = 1.7;
    msg8.voltage = 12.0;
    msg8.latitude = -7.22;
    msg8.longitude = 112.22;
    msg8.minutes = 900; // 15:00 UTC (15 * 60)
    String nmea8 = encodeMessage8(msg8);
    Serial.println("Message 8 NMEA: " + nmea8);
    Serial.println();

    // Test Message 14 (Safety Related Broadcast Message)
    Serial.println("Testing AIS Message 14 (Safety Related Broadcast Message):");
    AISMessage14 msg14;
    msg14.repeat_indicator = 0;
    msg14.mmsi = 123456789;
    msg14.spare = 0;
    msg14.safety_text = "WARNING fiqru";
    String nmea14 = encodeMessage14(msg14);
    Serial.println("Message 14 NMEA: " + nmea14);
    Serial.println();
    // Test Message 18 (Position Report Class B)
    Serial.println("Testing AIS Message 18 (Position Report Class B):");
    AISMessage18 msg18;
    msg18.repeat_indicator = 0;
    msg18.mmsi = 987654321;
    msg18.reserved = 0;
    msg18.sog = 30; // 3.0 knots
    msg18.position_accuracy = false;
    msg18.longitude = 106.8456;
    msg18.latitude = -6.2088;
    msg18.cog = 450; // 45.0 degrees
    msg18.heading = 45;
    msg18.utc_second = 15;
    msg18.regional = 0;
    msg18.cs_flag = false;
    msg18.display_flag = false;
    msg18.dsc_flag = false;
    msg18.band_flag = false;
    msg18.msg22_flag = false;
    msg18.assigned_flag = false;
    msg18.raim_flag = false;
    msg18.radio_status = 0;
    String nmea18 = encodeMessage18(msg18);
    Serial.println("Message 18 NMEA: " + nmea18);
    Serial.println();

    // Test Message 21 (Aids-to-Navigation Report)
    Serial.println("Testing AIS Message 21 (Aids-to-Navigation Report):");
    AISMessage21 msg21;
    msg21.repeat_indicator = 0;
    msg21.mmsi = 123456789;
    msg21.aid_type = 1; // Reference point
    msg21.name = "LIGHTHOUSE ALPHA";
    msg21.position_accuracy = true;
    msg21.longitude = 106.8456;
    msg21.latitude = -6.2088;
    msg21.dimension_to_bow = 10;
    msg21.dimension_to_stern = 5;
    msg21.dimension_to_port = 3;
    msg21.dimension_to_starboard = 3;
    msg21.epfd_type = 1; // GPS
    msg21.utc_second = 30;
    msg21.off_position = false;
    msg21.regional = 0;
    msg21.raim_flag = false;
    msg21.virtual_aton_flag = false;
    msg21.assigned_mode_flag = false;
    msg21.spare = 0;
    String nmea21 = encodeMessage21(msg21);
    Serial.println("Message 21 NMEA: " + nmea21);
    Serial.println();

    // Test Message 24A (Static Data Report Part A)
    Serial.println("Testing AIS Message 24A (Static Data Report Part A):");
    AISMessage24A msg24a;
    msg24a.repeat_indicator = 0;
    msg24a.mmsi = 123456789;
    msg24a.ship_name = "MV EXAMPLE";
    String nmea24a = encodeMessage24A(msg24a);
    Serial.println("Message 24A NMEA: " + nmea24a);
    Serial.println();

    // Test Message 24B (Static Data Report Part B)
    Serial.println("Testing AIS Message 24B (Static Data Report Part B):");
    AISMessage24B msg24b;
    msg24b.repeat_indicator = 0;
    msg24b.mmsi = 123456789;
    msg24b.ship_type = 70; // Cargo ship
    msg24b.vendor_id = "VENDORanjing";
    msg24b.callsign = "CALLanjing";
    msg24b.dim_bow = 50;
    msg24b.dim_stern = 20;
    msg24b.dim_port = 10;
    msg24b.dim_starboard = 10;
    msg24b.spare = 0;
    String nmea24b = encodeMessage24B(msg24b);
    Serial.println("Message 24B NMEA: " + nmea24b);
    Serial.println();

    Serial.println("Test Complete. Please verify the NMEA messages with an AIS decoder.");
}