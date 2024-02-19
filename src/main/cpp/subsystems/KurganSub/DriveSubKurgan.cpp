// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/KurganSub/DriveSubKurgan.h"

DriveSubKurgan::DriveSubKurgan() = default;

// This method will be called once per scheduler run
void DriveSubKurgan::Periodic() {}

void DriveSubKurgan::Init()
{
    m_rightMotorOne.SetInverted(true);
    m_rightMotorTwo.SetInverted(true);
}

void DriveSubKurgan::LeftMotor(double speed)
{
    // note: slow down left motor, since right motor is reversed (so it moves slower)
    if (speed > 0.0)
    {
        speed = speed * 0.75;
    }
    m_leftMotorOne.Set(speed);
    m_leftMotorTwo.Set(speed);
}

void DriveSubKurgan::RightMotor(double speed)
{
    m_rightMotorOne.Set(speed);
    m_rightMotorTwo.Set(speed);
}
