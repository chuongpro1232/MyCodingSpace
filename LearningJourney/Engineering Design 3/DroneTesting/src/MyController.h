/*
Two-way communication for espnow
You need to know:
- The MAC address of the other board
- The data that you are sending
- no more than 250 bytes (approx. 62 float number)
*/

#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>

// ******************************************
// Variable declaration
// ******************************************
// Insert the MAC address of the other board

uint8_t broadcastAddress[] = {0x48, 0xE7, 0x29, 0x9E, 0x30, 0xFC};

// Define the incoming data, RECEIVED into this board
typedef struct struct_msg_Receive
{
  int right_x_val;
  int right_y_val;
  bool switch1;
  bool switch2;
  int Receive_PotValue;
} struct_msg_Receive;

// Declare the structure
struct_msg_Receive Receive_Data;

// Variable for espnow communication
esp_now_peer_info_t peerInfo;

// Serial
unsigned long time_prev_serial = 0;

// extern int x_val = Receive_Data.right_x_val;
// extern int y_val = Receive_Data.right_y_val;
// extern bool switch1 = Receive_Data.switch1;
// extern bool switch2 = Receive_Data.switch2;
double potValue, x_val, y_val;
bool switch1, switch2;

// ******************************************
// Function declaration
// ******************************************
void StoreControllerData();
void OnDataReceive(const uint8_t *mac, const uint8_t *incomingData, int len);
float floatMap(float, float, float, float, float);
void espnow_initialize();

// ******************************************
// void setup
// ******************************************
void Init_Controller()
{
  Serial.begin(115200);
  espnow_initialize();
}

void Run_Controller()
{
  if (micros() - time_prev_serial >= 20000)
  {
    time_prev_serial = micros();
    StoreControllerData();
  }
}

// ******************************************
// Function definition
// ******************************************

void StoreControllerData()
{
  // potValue = 100;
  potValue = Receive_Data.Receive_PotValue;
  x_val = Receive_Data.right_x_val;
  y_val = Receive_Data.right_y_val;
  switch1 = Receive_Data.switch1;
  switch2 = Receive_Data.switch2;
}
// void StoreCpntrollerData()
// {
//   Serial.print(micros() / 1000);
//   Serial.println();
//   Serial.print("Joystick data: ");
//   Serial.print("\t");
//   Serial.print(Receive_Data.right_x_val);
//   Serial.print("\t");
//   Serial.print(Receive_Data.right_y_val);
//   Serial.println("\nSwitch data: ");
//   Serial.print("Switch 1:");
//   Serial.print(Receive_Data.switch1);
//   Serial.print("\t");
//   Serial.print("Switch 2:");
//   Serial.print(Receive_Data.switch2);
//   Serial.println("");
//   Serial.print("Potentiometer data: ");
//   Serial.print(Receive_Data.Receive_PotValue);
//   Serial.println();
// }

// ******************************************
void OnDataReceive(const uint8_t *mac, const uint8_t *incomingData, int len)
{
  // debugging serial
  //Serial.print(micros() / 1000);
  // Serial.println("\tData received!");
  // Serial.println(Receive_Data);
  // You must copy the incoming data to the local variables
  memcpy(&Receive_Data, incomingData, sizeof(Receive_Data));
}

// ******************************************
float floatMap(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// ******************************************
void espnow_initialize()
{
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK)
  {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_recv_cb(OnDataReceive);

  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  // Add peer
  if (esp_now_add_peer(&peerInfo) != ESP_OK)
  {
    Serial.println("Failed to add peer");
    return;
  }
}