#ifndef __SUBSYSTEMS_INTAKE_H__
#define __SUBSYSTEMS_INTAKE_H__

#include "pros/motor_group.hpp"
#include "constants.h"

using namespace constants::intake;

class Intake : public pros::Motor
{
    public:
        Intake() : pros::Motor(INTAKE_PORT) {}
        inline void forward() { this->move_voltage(INTAKE_VOLTAGE); }
        inline void reverse() { this->move_voltage(-INTAKE_VOLTAGE); }
        inline void stop() { this->move_voltage(0); }
};

#endif