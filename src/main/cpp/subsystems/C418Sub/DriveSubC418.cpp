// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/C418Sub/DriveSubC418.h"

DriveSubC418::DriveSubC418() = default;

// This method will be called once per scheduler run
void DriveSubC418::Periodic() 
{
}

void DriveSubC418::Init()
{

    m_rightMotor.SetInverted (true);
    m_leftMotor.SetInverted (false);
    LeftMotor(0);
    RightMotor(0);
}

void DriveSubC418::LeftMotor(double speed)
{
    m_leftMotor.Set(speed);
}

void DriveSubC418::RightMotor(double speed)
{
    m_rightMotor.Set(speed);
}


