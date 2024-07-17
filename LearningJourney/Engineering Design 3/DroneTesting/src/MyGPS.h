#include <Arduino.h>
#include <TinyGPSPlus.h>
// #include <MySerial.h>
// ================================================================
// Variable declaration
// ================================================================
#define RXD2 16
#define TXD2 17
TinyGPSPlus gps;
// ================================================================
// Function Declaration
// ================================================================

void Get_GPSData(); // Get the GPS data
void displayInfo(); // Display info from the GPS
// ================================================================
// Setup function
// ================================================================
void Init_GPS()
{
    Init_Serial();
    Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
}
// ================================================================
// Loop function
// ================================================================
void run_GPS()
{
    Get_GPSData();
}
void Get_GPSData()
{
    while (Serial2.available() > 0)
        if (gps.encode(Serial2.read()))
            displayInfo();
}
// ==============================================================
void displayInfo()
{
    // Serial.println("Start of GPS");
    if (gps.location.isValid())
    {
        Serial.print(gps.location.lat(), 6);
        Serial.print(F(","));
        Serial.print(gps.location.lng(), 6);
        Serial.print(F(","));
    }
    else
    {
        Serial.print("0.000000");
        Serial.print(",");
        Serial.print("0.000000");
        Serial.print(",");
    }
    if (gps.altitude.isValid())
    {
        Serial.print(gps.altitude.meters());
        // Serial.print(F("m"));
        Serial.print(F(","));
    }
    else
    {
        Serial.print("0.000000");
        Serial.print(",");
    }
    Serial.print(F(" Date/Time: "));
    if (gps.date.isValid())
    {
        Serial.print(gps.date.month());
        // Serial.print(F("/"));
        Serial.print(",");
        Serial.print(gps.date.day());
        // Serial.print(F("/"));
        Serial.print(",");
        Serial.print(gps.date.year());
        Serial.print(",");
    }
    else
    {
        Serial.print("0");
        Serial.print(",");
        Serial.print("0");
        Serial.print(",");
        Serial.print("0");
        Serial.print(",");
    }
    // Serial.print(F(" "));
    if (gps.time.isValid())
    {
        if (gps.time.hour() < 10)
            Serial.print(F("0"));
        Serial.print(gps.time.hour());
        Serial.print(",");
        if (gps.time.minute() < 10)
            Serial.print(F("0"));
        Serial.print(gps.time.minute());
        Serial.print(",");
        if (gps.time.second() < 10)
            Serial.print(F("0"));
        Serial.print(gps.time.second());
        Serial.print(",");
        if (gps.time.centisecond() < 10)
            Serial.print(F("0"));
        Serial.print(gps.time.centisecond());
    }
    else
    {
        Serial.print("00");
        Serial.print(",");
        Serial.print("00");
        Serial.print(",");
        Serial.print("00");
        Serial.print(",");
        Serial.print("00");
    }
    Serial.println();
}