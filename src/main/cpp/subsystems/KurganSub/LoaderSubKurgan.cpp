// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/KurganSub/LoaderSubKurgan.h"

LoaderSubKurgan::LoaderSubKurgan() = default;

// This method will be called once per scheduler run
void LoaderSubKurgan::Periodic() {}

void LoaderSubKurgan::Init()
{
    
}

void LoaderSubKurgan::LoadIntake(double speed)
{
    m_loadMotor.Set(speed);
}
