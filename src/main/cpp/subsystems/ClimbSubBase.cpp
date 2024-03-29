// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ClimbSubBase.h"
#include "Util.h"

ClimbSubBase::ClimbSubBase() = default;

// This method will be called once per scheduler run
void ClimbSubBase::Periodic() 
{ 
    static int heartbeat = 0;
    Util::Log("Heartbeat", heartbeat++, "ClimbSubBase");
}

void ClimbSubBase::Climb(double speed)
{
    ClimbMotor(speed);
}
