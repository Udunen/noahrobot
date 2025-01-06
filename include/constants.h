#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "pros/abstract_motor.hpp"
#include <array>
#include <cstdint>
#include "lemlib/chassis/chassis.hpp"

namespace constants
{
    // using namespace pros;

    namespace drivebase
    {
        // front, middle, back
        inline constexpr std::array<int8_t, 3> LEFT_PORTS = {
            -3,
            -4,
            -7
        };

        // front, middle, back
        inline constexpr std::array<int8_t, 3> RIGHT_PORTS = {
            11,
            12,
            13
        };

        inline constexpr double DRIVETRAIN_WIDTH = 12;
        inline constexpr int IMU_PORT = 5;

        inline constexpr auto CHASSIS_INTERNAL_GEARSET = pros::v5::MotorGears::green;

        // lateral PID controller
        inline const lemlib::ControllerSettings LATERAL_CONTROLLER(
            10,   // proportional gain (kP)
            0,   // integral gain (kI)
            3,   // derivative gain (kD)
            0,   // anti windup
            0,   // small error range, in inches
            0, // small error range timeout, in milliseconds
            0,   // large error range, in inches
            0, // large error range timeout, in milliseconds
            0   // maximum acceleration (slew)
        );

        // angular PID controller
        inline const lemlib::ControllerSettings ANGULAR_CONTROLLER(
            10, // proportional gain (kP) - 10/12
            0, // integral gain (kI)
            75,// derivative gain (kD) - 75/80
            3, // 3, // anti windup
            1, // 1, // small error range, in degrees
            100, // 100, // small error range timeout, in milliseconds
            3, // 3, // large error range, in degrees
            500, // 500, // large error range timeout, in milliseconds
            0  // maximum acceleration (slew)
        );

        inline pros::MotorGroup LEFT_MOTORS({LEFT_PORTS[0],
                                             LEFT_PORTS[1],
                                             LEFT_PORTS[2]},
                                            CHASSIS_INTERNAL_GEARSET);

        inline pros::MotorGroup RIGHT_MOTORS({RIGHT_PORTS[0],
                                              RIGHT_PORTS[1],
                                              RIGHT_PORTS[2]},
                                             CHASSIS_INTERNAL_GEARSET);

        inline pros::Imu IMU(IMU_PORT);

        // drivetrain settings
        inline lemlib::Drivetrain DRIVETRAIN(
            &LEFT_MOTORS,               // left motor group
            &RIGHT_MOTORS,              // right motor group
            DRIVETRAIN_WIDTH,           // 10 inch track width
            lemlib::Omniwheel::NEW_325, // using new 3.25" omnis
            360,                        // drivetrain rpm is 360
            2                           // horizontal drift is 2 (for now)
        );

        inline lemlib::OdomSensors SENSORS(
            nullptr, // vertical tracking wheel 1
            nullptr, // vertical tracking wheel 2, set to nullptr as we are using two wheel
            nullptr, // horizontal tracking wheel 1
            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
            &IMU     // inertial sensor
        );

        inline constexpr int DEFAULT_TIMEOUT = 5000;
    }

    namespace intake
    {
        inline constexpr int INTAKE_PORT = -6;
        inline constexpr int INTAKE_VOLTAGE = 12000; // mV
        // uses basic motors, which doesn't requre gearset to be configured in code
    }

    namespace conveyor
    {
        inline constexpr int CONVEYOR_PORT = -9;
        inline constexpr int CONVEYOR_VOLTAGE = 12000; // mV
        // uses basic motors, which doesn't requre gearset to be configured in code
    }

    namespace arm
    {
        inline constexpr int ARM_PORT = 14;
        inline constexpr auto ARM_INTERNAL_GEARSET = pros::v5::MotorGears::red;
        inline constexpr int ARM_VOLTAGE = 12000; // mV
        inline constexpr int ROTATION_SENSOR_PORT = 10;
    }

    namespace clamp
    {
        inline constexpr char PORT = 'A';
    }

    inline constexpr double TELEOP_POLL_TIME = 10.0; // ms

}
#endif