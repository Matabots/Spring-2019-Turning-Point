#ifndef ROBOT_HPP
#define ROBOT_HPP
#include "main.h"

extern Controller master;

extern Motor right_front;
extern Motor right_back;
extern Motor left_front;
extern Motor left_back;

extern Motor intake_right;
extern Motor intake_left;

extern Motor Catapult_right;
extern Motor Catapult_left;

extern Motor lift_right;
extern Motor lift_left;

extern ADIDigitalIn catapult_lim;

extern void setup_bot();

#endif
