#ifndef __SUBSYSTEMS_H__
#define __SUBSYSTEMS_H__

#include "subsystems/drivebase.h"
#include "subsystems/intake.h"
#include "subsystems/clamp.h"
#include "subsystems/arm.h"
#include "subsystems/conveyor.h"

inline Drivebase *drivebase = nullptr;
inline Intake *intake = nullptr;
inline Clamp *clamp = nullptr;
inline Arm *arm = nullptr;
inline Conveyor *conveyor = nullptr;

// Initialize the subsystems
inline void subsystems_initialize()
{
    drivebase = new Drivebase();
    drivebase->calibrateChassis(false);
    intake = new Intake();
    arm = new Arm();
    clamp = new Clamp();
    conveyor = new Conveyor();
}

#endif
