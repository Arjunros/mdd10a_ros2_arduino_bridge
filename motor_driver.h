/***************************************************************
   Motor driver function definitions - ARJUN R 
   *************************************************************/

#ifdef L298_MOTOR_DRIVER
  //below can be changed
  #define LEFT_MOTOR_ENABLE 12
  #define LEFT_MOTOR_FORWARD 9
  #define LEFT_MOTOR_BACKWARD 10
  #define RIGHT_MOTOR_FORWARD 5
  #define RIGHT_MOTOR_BACKWARD 6
  #define RIGHT_MOTOR_ENABLE 11
  
#elif defined(MDD10A_MOTOR_DRIVER)
  // MDD10A Motor Driver Pin Definitions
  #define LEFT_MOTOR_PWM 3
  #define LEFT_MOTOR_DIRECTION 4
  #define RIGHT_MOTOR_PWM 5
  #define RIGHT_MOTOR_DIRECTION 6

#endif

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);
