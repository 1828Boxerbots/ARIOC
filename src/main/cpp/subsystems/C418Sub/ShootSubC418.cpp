// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/C418Sub/ShootSubC418.h"

ShootSubC418::ShootSubC418() = default;

// This method will be called once per scheduler run
void ShootSubC418::Periodic() 
{
}

void ShootSubC418::Init()
{
    m_shooterMotor.SetInverted(true);

    ShootMotor(0);
}

void ShootSubC418::ShootMotor(double speed)
{
    m_shooterMotor.Set(speed);
}
