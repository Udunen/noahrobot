#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "tasks/teleop.h"
#include "constants.h"
#include "subsystems.h"

using namespace pros;

void opcontrol_initialize() {}

static void drivebase_controls(Controller &controller) {
    drivebase->errorDrive(
        controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y),
        controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X));
}

static void intake_controls(Controller &controller) {
    if (controller.get_digital(E_CONTROLLER_DIGITAL_L1)) {
        intake->forward();
    } else if (controller.get_digital(E_CONTROLLER_DIGITAL_L2)) {
        intake->reverse();
    } else {
        intake->stop();
    }
}

static void conveyor_controls(Controller &controller) {
    if (controller.get_digital(E_CONTROLLER_DIGITAL_R1)) {
        conveyor->forward();
    } else if (controller.get_digital(E_CONTROLLER_DIGITAL_R2)) {
        conveyor->reverse();
    } else {
        conveyor->stop();
    }
}

static void arm_controls(Controller &controller) {
    if (controller.get_digital(E_CONTROLLER_DIGITAL_UP)) {
        arm->forward();
    } else if (controller.get_digital(E_CONTROLLER_DIGITAL_DOWN)) {
        arm->reverse();
    } else {
        arm->stop();
    }
}

static void clamp_controls(Controller &controller) {
    if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) {
        clamp->toggle();
    }
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    Controller controller(pros::E_CONTROLLER_MASTER);

    while (true) {
        lcd::print(0, "X: %f", drivebase->getPose().x);
        lcd::print(1, "Y: %f", drivebase->getPose().y);
        lcd::print(2, "Theta: %f", drivebase->getPose().theta);
        lcd::print(3, "IMU: %f", drivebase->getIMU().get_heading());
        controller.print(0, 0, "Theta: %f", drivebase->getPose().theta);


        drivebase_controls(controller);
        intake_controls(controller);
        clamp_controls(controller);
        conveyor_controls(controller);
        arm_controls(controller);

        pros::delay(constants::TELEOP_POLL_TIME);
    }
}
