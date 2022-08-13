// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/RockySub/DriveSubRocky.h"

DriveSubRocky::DriveSubRocky() = default;

// This method will be called once per scheduler run
void DriveSubRocky::Periodic() 
{
}

void DriveSubRocky::Init()
{
    m_rightMotor.SetInverted(true);
    m_leftMotor.SetInverted(false);
    m_rightMotor.Set(0);
    m_leftMotor.Set(0);
}

void DriveSubRocky::RightMotor(double speed)
{
    m_rightMotor.Set(speed);
}

void DriveSubRocky::LeftMotor(double speed)
{
    m_leftMotor.Set(speed);
}