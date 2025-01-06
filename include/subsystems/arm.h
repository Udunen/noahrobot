#ifndef __SUBSYSTEMS_ARM_H__
#define __SUBSYSTEMS_ARM_H__

#include "pros/motor_group.hpp"
#include "constants.h"

using namespace constants::arm;

class Arm : public pros::Motor
{
    public:
        Arm() : pros::Motor(ARM_PORT) {}
        inline void forward() { this->move_voltage(ARM_VOLTAGE); }
        inline void reverse() { this->move_voltage(-ARM_VOLTAGE); }
        inline void stop() { this->move_voltage(0); }
};

#endif