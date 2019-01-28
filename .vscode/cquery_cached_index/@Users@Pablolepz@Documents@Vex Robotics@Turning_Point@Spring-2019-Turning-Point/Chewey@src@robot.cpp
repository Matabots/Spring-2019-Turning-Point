#include "main.h"
#include "robot.hpp"
//robot.cpp/.hpp is for initialization of motors, remote, and sensors


Controller master(pros::E_CONTROLLER_MASTER);

Motor right_front(12,true);
Motor right_back(19,true);
Motor left_front(7,false);
Motor left_back(9,false);

Motor intake_right(3, false);
Motor intake_left(8, true);

Motor Catapult_right(6, false);
Motor Catapult_left(17, true);

Motor lift_right(18, true);
Motor lift_left(11, false);

ADIDigitalIn catapult_lim ('H');

void setup_bot()
{
  right_front.set_brake_mode(E_MOTOR_BRAKE_COAST);
  right_back.set_brake_mode(E_MOTOR_BRAKE_COAST);
  left_front.set_brake_mode(E_MOTOR_BRAKE_COAST);
  left_back.set_brake_mode(E_MOTOR_BRAKE_COAST);
  lift_right.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  lift_left.set_brake_mode(E_MOTOR_BRAKE_HOLD);
}
