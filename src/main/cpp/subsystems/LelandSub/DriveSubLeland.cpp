// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LelandSub/DriveSubLeland.h"

DriveSubLeland::DriveSubLeland() = default;

// This method will be called once per scheduler run
void DriveSubLeland::Periodic() {}

void DriveSubLeland::Init()
{

    m_rightMotor.SetInverted (true);
    m_leftMotor.SetInverted (false);
    LeftMotor(0);
    RightMotor(0);
}

void DriveSubLeland::LeftMotor(double speed)
{
    m_leftMotor.Set(speed);
}

void DriveSubLeland::RightMotor(double speed)
{
    m_rightMotor.Set(speed);
}
