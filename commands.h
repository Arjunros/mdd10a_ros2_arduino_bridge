/* Define single-letter commands that will be sent by the PC over the
   serial link.
*/

#ifndef COMMANDS_H
#define COMMANDS_H

#define READ_ENCODERS  'e'
#define MOTOR_SPEEDS   'm'
#define MOTOR_RAW_PWM  'o'
#define RESET_ENCODERS 'r'
#define UPDATE_PID     'p'
#define LEFT            0
#define RIGHT           1

#endif
