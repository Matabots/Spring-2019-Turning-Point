#ifndef DRIVE_HPP
#define DRIVE_HPP
#include "main.h"

extern void move_left_motors(int rpm);
extern void move_right_motors(int rpm);
extern void halt_left_motors();
extern void halt_right_motors();
extern void move_lift();
extern void move_chassis();
extern void run_drive();

#endif
