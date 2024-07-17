#include <Arduino.h>
#include <PID_v1.h>
// #include <MyController.h>
extern double potValue;
extern double x_val, y_val;
extern bool switch1, switch2;
extern double anglex, angley, gyrox, gyroy;
// ================================================================
// Variable declaration
// ================================================================
// The PID object is configured as follows:
// input = sensor, variable to be controller;
// output = pid output, command sent to the motors;
// setpoint = reference setpoint, the desired angle (usually 0deg to maintain an upward position)
// PID myPID(&input, &output, &setpoint, kp, ki, kd, DIRECT);

double pid_output = 0, motor_1 = 0, motor_2 = 0, motor_3 = 0, motor_4 = 0;
// Roll PID variables
double roll_pid_output = 0, roll_setpoint = 0;
double roll_kp = 1.0, roll_ki = 0.0, roll_kd = 0.0;
PID roll_PID(&angley, &roll_pid_output, &roll_setpoint, roll_kp, roll_ki, roll_kd, DIRECT);

// Pitch PID variables
double pitch_pid_output = 0, pitch_setpoint = 0;
double pitch_kp = 1.0, pitch_ki = 0.0, pitch_kd = 0.0;
PID pitch_PID(&anglex, &pitch_pid_output, &pitch_setpoint, pitch_kp, pitch_ki, pitch_kd, DIRECT);

// Roll Rate PID variables
double roll_rate_pid_output = 0, roll_rate_setpoint = 0;
double roll_rate_kp = 1.0, roll_rate_ki = 0.0, roll_rate_kd = 0.0;
PID roll_rate_PID(&gyroy, &roll_rate_pid_output, &roll_rate_setpoint, roll_rate_kp, roll_rate_ki, roll_rate_kd, DIRECT);

// Pitch Rate PID variables
double pitch_rate_pid_output = 0, pitch_rate_setpoint = 0;
double pitch_rate_kp = 1.0, pitch_rate_ki = 0.0, pitch_rate_kd = 0.0;
PID pitch_rate_PID(&gyrox, &pitch_rate_pid_output, &pitch_rate_setpoint, pitch_rate_kp, pitch_rate_ki, pitch_rate_kd, DIRECT);

void Compute_Roll_PID();
void Compute_Pitch_PID();
void Compute_PitchRate_PID();
void Compute_RollRate_PID();
void Check_Yaw_Motion();

// ================================================================
// Function Definition
// ================================================================
void Init_PID()
{
  roll_PID.SetMode(AUTOMATIC);
  pitch_PID.SetMode(AUTOMATIC);
  roll_rate_PID.SetMode(AUTOMATIC);
  pitch_rate_PID.SetMode(AUTOMATIC);

  roll_PID.SetOutputLimits(-127, 127);
  pitch_PID.SetOutputLimits(-127, 127);
  roll_rate_PID.SetOutputLimits(-127, 127);
  pitch_rate_PID.SetOutputLimits(-127, 127);
}
// ================================================================
void Compute_PID()
{
  Compute_Roll_PID();
  Compute_Pitch_PID();
  Compute_PitchRate_PID();
  Compute_RollRate_PID();
  // Check_Yaw_Motion();
}

void Compute_Roll_PID()
{
  roll_PID.Compute();
  // Adjust motors based on roll PID output

  //motor 1 => 4
  double joystick_y_value = y_val - 114;
  double joystick_x_value = x_val - 114;
  double speed_1 = potValue - joystick_y_value - joystick_x_value;
  double speed_2 = potValue + joystick_y_value - joystick_x_value;
  double speed_3 = potValue + joystick_y_value + joystick_x_value;
  double speed_4 = potValue - joystick_y_value + joystick_x_value;
  // double joystick_y_value = 0;

  // double joystick_x_value = x_val - 114;
  // double speed_1 = motor_1 + joystick_x_value;
  // double speed_2 = motor_2 + joystick_x_value;
  // double speed_3 = motor_3 - joystick_x_value;
  // double speed_4 = motor_4 - joystick_x_value;

  if (speed_1 <= -1)
  {
    speed_1 = potValue;
  } if (speed_2 <= -1)
  {
    speed_2 = potValue;
  } if (speed_3 <= -1)
  {
    speed_3 = potValue;
  } if(speed_4 <= -1){
    speed_4 = potValue;
  }

  // Serial.println();
  // Serial.print("Speed: ");
  // Serial.print(speed_1);
  // Serial.print("\t");
  // Serial.print(speed_2);
  // Serial.print("\t");
  // Serial.print(speed_3);
  // Serial.print("\t");
  // Serial.print(speed_4);

  motor_1 = map(speed_1 - roll_pid_output, 0, 500, 0, 500);
  motor_2 = map(speed_2 + roll_pid_output, 0, 500, 0, 500);
  motor_3 = map(speed_3 + roll_pid_output, 0, 500, 0, 500);
  motor_4 = map(speed_4 - roll_pid_output, 0, 500, 0, 500);

}

void Compute_Pitch_PID()
{
  pitch_PID.Compute();
  // Adjust motors based on pitch PID output
  // double joystick_x_value = x_val - 114;
  // double speed_1 = motor_1 + joystick_x_value;
  // double speed_2 = motor_2 + joystick_x_value;
  // double speed_3 = motor_3 - joystick_x_value;
  // double speed_4 = motor_4 - joystick_x_value;

  // if (speed_1 < 0)
  // {
  //   speed_1 = potValue;
  // } else if (speed_2 < 0)
  // {
  //   speed_2 = potValue;
  // } else if (speed_3 < 0)
  // {
  //   speed_3 = potValue;
  // } else {
  //   speed_4 = potValue;
  // }
  // double joystick_x_value = 0;

  motor_1 = map(motor_1 - pitch_pid_output, 0, 500, 0, 500);
  motor_2 = map(motor_2 - pitch_pid_output, 0, 500, 0, 500);
  motor_3 = map(motor_3 + pitch_pid_output, 0, 500, 0, 500);
  motor_4 = map(motor_4 + pitch_pid_output, 0, 500, 0, 500);


  if(switch1 == true){
    motor_1 += 50;
    motor_3 += 50;
  } 

  if(switch2 == true){
    motor_2 += 50;
    motor_4 += 50;
  }
}

void Compute_RollRate_PID()
{
  roll_rate_PID.SetTunings(roll_rate_kp, roll_rate_ki, roll_rate_kd);
  roll_rate_PID.Compute();

  // Adjust motors based on roll rate PID output
  motor_1 -= roll_rate_pid_output;
  motor_2 += roll_rate_pid_output;
  motor_3 += roll_rate_pid_output;
  motor_4 -= roll_rate_pid_output; 
}

void Compute_PitchRate_PID()
{
  pitch_rate_PID.SetTunings(pitch_rate_kp, pitch_rate_ki, pitch_rate_kd);
  pitch_rate_PID.Compute();
  // Adjust motors based on pitch rate PID output
  motor_1 -= pitch_rate_pid_output;
  motor_2 -= pitch_rate_pid_output;
  motor_3 += pitch_rate_pid_output;
  motor_4 += pitch_rate_pid_output;
  // if (abs(gyrox) > 50)
  // {
  //   motor_1 = 0;
  //   motor_2 = 0;
  //   motor_3 = 0;
  //   motor_4 = 0;
  // }

  // if (abs(gyroy) > 50)
  // {
  //   motor_1 = 0;
  //   motor_2 = 0;
  //   motor_3 = 0;
  //   motor_4 = 0;
  // }


  // if (abs(anglex) > 50)
  // {
  //   motor_1 = 0;
  //   motor_2 = 0;
  //   motor_3 = 0;
  //   motor_4 = 0;
  // }

  // if (abs(angley) > 50)
  // {
  //   motor_1 = 0;
  //   motor_2 = 0;
  //   motor_3 = 0;  
  //   motor_4 = 0;
  // }
}

void Check_Yaw_Motion() {
  if(switch1 == true){
    motor_1 += 10;
    motor_3 += 10;
  } 

  if(switch2 == true){
    motor_2 += 10;
    motor_4 += 10;
  }
}
// ================================================================
