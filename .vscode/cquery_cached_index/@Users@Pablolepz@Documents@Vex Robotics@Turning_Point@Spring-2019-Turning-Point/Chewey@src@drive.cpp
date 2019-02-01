#include "main.h"

int liftTarDeg = lift_right.get_position();
int lFDriveTar = left_front.get_position();
int lBDriveTar = left_back.get_position();
int rFDriveTar = right_front.get_position();
int rBDriveTar = right_back.get_position();
int catapultTar = 0;

bool setLBrake = false;
bool setRBrake = false;
bool intakeOn = false;
int DEADZONE = 15;

void move_left_motors(int rpm)
{
  left_front.move(rpm);
  left_back.move(rpm);
}

void move_right_motors(int rpm)
{
  right_front.move(rpm);
  right_back.move(rpm);
}

void halt_left_motors()
{
  if (setLBrake)
  {
    //delay(100);
    lFDriveTar = left_front.get_position();
    lBDriveTar = left_back.get_position();
    setLBrake = false;
  }
  left_front.move_absolute(lFDriveTar, 0);
  left_back.move_absolute(lBDriveTar, 0);
}
void halt_right_motors()
{
  if (setRBrake)
  {
    //delay(100);
    rFDriveTar = right_front.get_position();
    rBDriveTar = right_back.get_position();
    setRBrake = false;
  }
  right_front.move_absolute(rFDriveTar, 0);
  right_back.move_absolute(rBDriveTar, 0);
}

void move_lift()
{
  if (master.get_digital(E_CONTROLLER_DIGITAL_R1) == 1)
  {
    lift_left.move_velocity(100);
    lift_right.move_velocity(100);
    liftTarDeg = lift_right.get_position();
  }
  else if (master.get_digital(E_CONTROLLER_DIGITAL_R2) == 1)
  {
    lift_left.move_velocity(-100);
    lift_right.move_velocity(-100);
    liftTarDeg = lift_right.get_position();
  }
  else
  {
    lift_left.move_absolute(liftTarDeg, 0);
    lift_right.move_absolute(liftTarDeg, 0);
  }

}

void run_intake()
{
  if (master.get_digital(E_CONTROLLER_DIGITAL_L1) == 1)
  {
    intake_left.move_velocity(130);
    intake_right.move_velocity(130);
  }
  else if (master.get_digital(E_CONTROLLER_DIGITAL_L2) == 1)
  {
    intake_left.move_velocity(-130);
    intake_right.move_velocity(-130);
  }
  else
  {
    intake_left.move_velocity(0);
    intake_right.move_velocity(0);
  }
}

void set_catapult()
{
  while(catapult_lim.get_value() != 1)
  {
    Catapult_right.move_velocity(40);
    Catapult_left.move_velocity(40);
  }
  catapultTar = Catapult_right.get_position();
  // Catapult_right.move_absolute(catapultTar, 0);
  // Catapult_left.move_absolute(catapultTar, 0);
  Catapult_right.move_velocity(0);
  Catapult_left.move_velocity(0);
}

void run_catapult()
{
  if (master.get_digital(E_CONTROLLER_DIGITAL_X) == 1)
  {
    Catapult_right.move_velocity(40);
    Catapult_left.move_velocity(40);
    delay(500);
    while (catapult_lim.get_value() != 0)
    {
      Catapult_right.move_velocity(40);
      Catapult_left.move_velocity(40);
    }
    Catapult_right.move_velocity(0);
    Catapult_left.move_velocity(0);
    delay(180);
    set_catapult();
  }
}

void cap_dunk()
{

}

void move_chassis() //continuous function
{
  if (abs(master.get_analog(ANALOG_LEFT_Y)) > DEADZONE)
  {
    setLBrake = true;
    move_left_motors(master.get_analog(ANALOG_LEFT_Y));
  }
  else
  {
    halt_left_motors();
  }
  if (abs(master.get_analog(ANALOG_RIGHT_Y)) > DEADZONE)
  {
    setRBrake = true;
    move_right_motors(master.get_analog(ANALOG_RIGHT_Y));
  }
  else
  {
    halt_right_motors();
  }
}

void run_drive()
{
  move_chassis();
  move_lift();
  run_intake();
  run_catapult();
}
