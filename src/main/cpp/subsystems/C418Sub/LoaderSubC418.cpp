// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/C418Sub/LoaderSubC418.h"

LoaderSubC418::LoaderSubC418() = default;

// This method will be called once per scheduler run
void LoaderSubC418::Periodic() 
{
}

void LoaderSubC418::Init()
{
    m_upperLoaderMotor.SetInverted(false);
    m_lowerLoaderMotor.SetInverted(true);
}

void LoaderSubC418::LoadIntake(double speed)
{
    m_intakeMotor.Set(speed);
}

void LoaderSubC418::LoadLower(double speed)
{
    m_lowerLoaderMotor.Set(speed);
}

void LoaderSubC418::LoadUpper(double speed)
{
    m_upperLoaderMotor.Set(speed);
}