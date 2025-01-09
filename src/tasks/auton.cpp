#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/llemu.hpp"
#include "subsystems.h"
#include "tasks/auton.h"
#include "constants.h"

using namespace pros;

pros::Controller controller(pros::E_CONTROLLER_MASTER);


enum class AutonMode
{
    VS,
    SKILLS,
    TEST
};

/*
 *  VS is 2v2 auton
 *  SKILLS is self explanitory
 *  TEST is testing any autons or tuning
 */
inline constexpr AutonMode MODE = AutonMode::TEST;

void autonomousTest()
{
    // drivebase->moveToPoint(0, 24, 5000, {}, false); // for calibrating lateral PID
    // drivebase->turnToHeading(180, 2500, {}, false); // for calibrating angular PID

    drivebase->moveToPoint(0, 24, DEFAULT_TIMEOUT);
    drivebase->turnThenMoveToPoint(-24, 0);
    drivebase->turnThenMoveToPoint(0, 0);
    drivebase->turnToHeading(0, DEFAULT_TIMEOUT);

    pros::delay(100);
    lcd::print(0, "X: %f", drivebase->getPose().x);
    lcd::print(1, "Y: %f", drivebase->getPose().y);
    lcd::print(2, "Theta: %f", drivebase->getPose().theta);
    lcd::print(3, "IMU: %f", drivebase->getIMU().get_heading());

    pros::delay(3000);
}

void autonomousSkills(){

}

void autonomousVS(){}

void autonomous()
{
    switch (MODE)
    {
    case AutonMode::TEST:
        return autonomousTest();
    case AutonMode::SKILLS:
        return autonomousSkills();
    case AutonMode::VS:
        return autonomousVS();
    default:
        break;
    }
};

void autonomous_initialize()
{
    drivebase->calibrateChassis(true);
    // set position to x:0, y:0, heading:0
    drivebase->setPose(0, 0, 0);
};