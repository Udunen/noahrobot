#ifndef __SUBSYSTEMS_CONVEYOR_H__
#define __SUBSYSTEMS_CONVEYOR_H__

#include "pros/motor_group.hpp"
#include "constants.h"

using namespace constants::conveyor;

class Conveyor : public pros::Motor
{
    public:
        Conveyor() : pros::Motor(CONVEYOR_PORT) {}
        inline void forward() { this->move_voltage(CONVEYOR_VOLTAGE); }
        inline void reverse() { this->move_voltage(-CONVEYOR_VOLTAGE); }
        inline void stop() { this->move_voltage(0); }
};

#endif