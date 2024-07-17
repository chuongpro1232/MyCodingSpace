#include <Arduino.h>
#include <ESP32Servo.h>

// ================================================================
// Variable declaration
// ================================================================
#define MAX_SIGNAL 2000 // Parameter required for the ESC definition
#define MIN_SIGNAL 1000 // Parameter required for the ESC definition

// Define the ESC signal pins for each motor
#define MOTOR_PIN_1 18    // Pin 13 attached to the ESC signal pin for Motor 1
#define MOTOR_PIN_2 19    // Pin 14 attached to the ESC signal pin for Motor 2
#define MOTOR_PIN_3 32    // Pin 15 attached to the ESC signal pin for Motor 3
#define MOTOR_PIN_4 33    // Pin 16 attached to the ESC signal pin for Motor 4

Servo ESC_1, ESC_2, ESC_3, ESC_4; // Define the ESCs for each motor
//int CtrlPWM_1, CtrlPWM_2, CtrlPWM_3, CtrlPWM_4; // Control Signal. Varies between [0 - 180]
extern double motor_1, motor_2, motor_3, motor_4; 

void SerialDataPrint();  // Function to print data on the serial monitor
void Init_Serial();      // Function to init the serial monitor
void WaitForKeyStroke(); // Function to interact with the serial monitor
void Wait2Seconds(); // Function to wait for 2 seconds
// void SerialDataWrite();  

void Init_MotorPin()
{
  Init_Serial();                                     // Initialize the serial communication
  ESC_1.attach(MOTOR_PIN_1, MIN_SIGNAL, MAX_SIGNAL); // Initialize the ESC for Motor 1
  ESC_2.attach(MOTOR_PIN_2, MIN_SIGNAL, MAX_SIGNAL); // Initialize the ESC for Motor 2
  ESC_3.attach(MOTOR_PIN_3, MIN_SIGNAL, MAX_SIGNAL); // Initialize the ESC for Motor 3
  ESC_4.attach(MOTOR_PIN_4, MIN_SIGNAL, MAX_SIGNAL); // Initialize the ESC for Motor 4

  // Serial.println();
  // Serial.println("Calibration step 1. Disconnect the battery.");
  // Serial.println("Press any key to continue.");
  // Wait2Seconds();
  
  // ESC_1.writeMicroseconds(MAX_SIGNAL); // Sending MAX_SIGNAL tells the ESC to enter calibration mode for Motor 1
  // ESC_2.writeMicroseconds(MAX_SIGNAL); // Sending MAX_SIGNAL tells the ESC to enter calibration mode for Motor 2
  // ESC_3.writeMicroseconds(MAX_SIGNAL); // Sending MAX_SIGNAL tells the ESC to enter calibration mode for Motor 3
  // ESC_4.writeMicroseconds(MAX_SIGNAL); // Sending MAX_SIGNAL tells the ESC to enter calibration mode for Motor 4

  // Serial.println();
  // Serial.println("Calibration step 2. Connect the battery.");
  // Serial.println("Wait for two short bips.");
  // Serial.println("Press any key to continue.");
  // Wait2Seconds();

  // ESC_1.writeMicroseconds(MIN_SIGNAL); // Sending MIN_SIGNAL tells the ESC the calibration value for Motor 1
  // ESC_2.writeMicroseconds(MIN_SIGNAL); // Sending MIN_SIGNAL tells the ESC the calibration value for Motor 2
  // ESC_3.writeMicroseconds(MIN_SIGNAL); // Sending MIN_SIGNAL tells the ESC the calibration value for Motor 3
  // ESC_4.writeMicroseconds(MIN_SIGNAL); // Sending MIN_SIGNAL tells the ESC the calibration value for Motor 4

  // Serial.println();
  // Serial.println("Wait for 4 short bips, and one long bip.");
  // Serial.println("Press any key to finish.");
  // Wait2Seconds();
}

void Run_Motor()
{
  // Send the commands to the ESCs for each motor
  ESC_1.write(motor_1);
  ESC_2.write(motor_2);
  ESC_3.write(motor_3);
  ESC_4.write(motor_4);

  //SerialDataPrint(); // Print data on the serial monitor for debugging
  //SerialDataWrite();
}

// ================================================================
void WaitForKeyStroke()
{
  while (!Serial.available())
    ;
  while (Serial.available())
    Serial.read();
}

// ================================================================
void Wait2Seconds()
{
  delay(4000); // Wait for 2 seconds
}

// ================================================================
// void SerialDataWrite()
// {
//     static String received_chars; 
//     while (Serial.available())
//     {
//         char inChar = (char)Serial.read();
//         received_chars += inChar;
//         if (inChar == '\n')
//         {
//             motor_1 = received_chars.toInt();
//             motor_2 = received_chars.toInt();
//             motor_3 = received_chars.toInt();
//             motor_4 = received_chars.toInt();
//             received_chars =  "";
//         }
//     }
// }
// ================================================================
// void SerialDataPrint()
// {
//   if (micros() - time_prev >= 20000)
//   {
//     time_prev = micros();
//     Serial.print(millis());
//     Serial.print("\t");
//     Serial.print(CtrlPWM_1);
//     Serial.print("\t");
//     Serial.print(CtrlPWM_2);
//     Serial.print("\t");
//     Serial.print(CtrlPWM_3);
//     Serial.print("\t");
//     Serial.println(CtrlPWM_4);
//   }
// }
