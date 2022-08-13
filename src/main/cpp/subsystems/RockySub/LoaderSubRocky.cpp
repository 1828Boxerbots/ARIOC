// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/RockySub/LoaderSubRocky.h"

LoaderSubRocky::LoaderSubRocky() = default;

// This method will be called once per scheduler run
void LoaderSubRocky::Periodic() 
{
}

void LoaderSubRocky::Init()
{
    m_loaderMotor.Set(0);
}

void LoaderSubRocky::LoadIntake(double speed)
{
    m_loaderMotor.Set(speed);
}