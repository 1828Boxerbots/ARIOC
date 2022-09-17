// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LelandSub/ShootSubLeland.h"

ShootSubLeland::ShootSubLeland() = default;

// This method will be called once per scheduler run
void ShootSubLeland::Periodic() {}

void ShootSubLeland::Init()
{
    m_shooterMotor.SetInverted(false);

    ShootMotor(0);
}

void ShootSubLeland::ShootMotor(double speed)
{
    m_shooterMotor.Set(speed);
}