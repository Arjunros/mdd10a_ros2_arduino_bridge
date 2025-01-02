/***************************************************************
   Motor driver definitions
   
   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   *************************************************************/

#ifdef USE_BASE

#ifdef L298_MOTOR_DRIVER
  void initMotorController() {
    digitalWrite(RIGHT_MOTOR_ENABLE, HIGH);
    digitalWrite(LEFT_MOTOR_ENABLE, HIGH);
  }
  
  void setMotorSpeed(int i, int spd) {
    unsigned char reverse = 0;
  
    if (spd < 0) {
      spd = -spd;
      reverse = 1;
    }
    if (spd > 255) spd = 255;
    
    if (i == LEFT) { 
      if (reverse == 0) { 
        analogWrite(LEFT_MOTOR_FORWARD, spd); 
        analogWrite(LEFT_MOTOR_BACKWARD, 0); 
      } 
      else if (reverse == 1) { 
        analogWrite(LEFT_MOTOR_BACKWARD, spd); 
        analogWrite(LEFT_MOTOR_FORWARD, 0); 
      }
    } else /*if (i == RIGHT)*/ { 
      if (reverse == 0) { 
        analogWrite(RIGHT_MOTOR_FORWARD, spd); 
        analogWrite(RIGHT_MOTOR_BACKWARD, 0); 
      } 
      else if (reverse == 1) { 
        analogWrite(RIGHT_MOTOR_BACKWARD, spd); 
        analogWrite(RIGHT_MOTOR_FORWARD, 0); 
      } 
    }
  }
  
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }

#elif defined(MDD10A_MOTOR_DRIVER)

  // Initialize MDD10A motor controller
  void initMotorController() {
    pinMode(LEFT_MOTOR_PWM, OUTPUT);
    pinMode(LEFT_MOTOR_DIRECTION, OUTPUT);
    pinMode(RIGHT_MOTOR_PWM, OUTPUT);
    pinMode(RIGHT_MOTOR_DIRECTION, OUTPUT);

    // Initially stop the motors
    analogWrite(LEFT_MOTOR_PWM, 0);
    analogWrite(RIGHT_MOTOR_PWM, 0);
    digitalWrite(LEFT_MOTOR_DIRECTION, LOW);
    digitalWrite(RIGHT_MOTOR_DIRECTION, LOW);
  }
  
  // Set motor speed (positive for forward, negative for reverse)
  void setMotorSpeed(int i, int spd) {
    unsigned char reverse = 0;
  
    // If speed is negative, reverse the direction
    if (spd < 0) {
      spd = -spd;
      reverse = 1;
    }
    if (spd > 255) spd = 255;  // Max speed is 255
  
    if (i == LEFT) {
      if (reverse == 0) {
        digitalWrite(LEFT_MOTOR_DIRECTION, HIGH); // Forward
        analogWrite(LEFT_MOTOR_PWM, spd);
      } else {
        digitalWrite(LEFT_MOTOR_DIRECTION, LOW); // Reverse
        analogWrite(LEFT_MOTOR_PWM, spd);
      }
    } else if (i == RIGHT) {
      if (reverse == 0) {
        digitalWrite(RIGHT_MOTOR_DIRECTION, HIGH); // Forward
        analogWrite(RIGHT_MOTOR_PWM, spd);
      } else {
        digitalWrite(RIGHT_MOTOR_DIRECTION, LOW); // Reverse
        analogWrite(RIGHT_MOTOR_PWM, spd);
      }
    }
  }

  // Set speeds for both motors
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }

#else
  #error A motor driver must be selected!
#endif

#endif
