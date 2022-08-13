// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/RockySub/ShootSubRocky.h"

ShootSubRocky::ShootSubRocky() = default;

// This method will be called once per scheduler run
void ShootSubRocky::Periodic() 
{
}

void ShootSubRocky::Init()
{
    m_shooterMotor.Set(0);
}

void ShootSubRocky::ShootMotor(double speed)
{
    m_shooterMotor.Set(speed);
}