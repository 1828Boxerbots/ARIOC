// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/RockySub/TurretSubRocky.h"

TurretSubRocky::TurretSubRocky() = default;

// This method will be called once per scheduler run
void TurretSubRocky::Periodic() 
{
}

void TurretSubRocky::Init()
{
    m_turretMotor.Set(0);
}

void TurretSubRocky::TurretMotor(double speed)
{
    m_turretMotor.Set(speed);
}