// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LoaderSubBase.h"

LoaderSubBase::LoaderSubBase() = default;

// This method will be called once per scheduler run
void LoaderSubBase::Periodic()
{ 
    static int heartbeat = 0;
    Util::Log("Heartbeat", heartbeat++, "LoaderSubBase");
}

void LoaderSubBase::Load(double speed, LoadMotors motor)
{
    switch (motor)
    {
    case LoadMotors::all:
        LoadIntake(speed);
        LoadLower(speed);
        LoadUpper(speed);
        break;
    case LoadMotors::upper:
        LoadUpper(speed);
        break;
    case LoadMotors::lower:
        LoadLower(speed);
        break;
    case LoadMotors::intake:
        LoadIntake(speed);
        break;
    default:
        Util::SendErrorAndCode("LoaderSubBase::Load switch went to default", 01);
        break;
    }
}

frc2::CommandPtr LoaderSubBase::SetLoaderSpeed(double speed)
{
    m_speed = speed;
    return RunOnce([this] { LoadAtSpeed(); });
}
