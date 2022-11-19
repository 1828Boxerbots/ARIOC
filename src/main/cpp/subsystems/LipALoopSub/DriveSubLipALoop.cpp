// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LipALoopSub/DriveSubLipALoop.h"

DriveSubLipALoop::DriveSubLipALoop() = default;

// This method will be called once per scheduler run
void DriveSubLipALoop::Periodic() {}

void DriveSubLipALoop::Init()
{
    m_topLeft.SetInverted(true);
    m_topRight.SetInverted(false);
    m_bottomLeft.SetInverted(true);
    m_bottomRight.SetInverted(false);
}

void DriveSubLipALoop::TopLeftMotor(double speed)
{
    m_topLeft.Set(speed);
}

void DriveSubLipALoop::TopRightMotor(double speed)
{
    m_topRight.Set(speed);
}

void DriveSubLipALoop::BottomLeftMotor(double speed)
{
    m_bottomLeft.Set(speed);
}

void DriveSubLipALoop::BottomRightMotor(double speed)
{
    m_bottomRight.Set(speed);
}