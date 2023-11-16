// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/KurganSub/ShootSubKurgan.h"

ShootSubKurgan::ShootSubKurgan() = default;

// This method will be called once per scheduler run
void ShootSubKurgan::Periodic() {}

void ShootSubKurgan::Init()
{
    //m_oneLeft.SetInverted(true);
    //m_threeLeft.SetInverted(true);
    //m_twoRight.SetInverted(true);
    m_fourRight.SetInverted(true);
}

void ShootSubKurgan::ShootMotor(double speed)
{
    m_oneLeft.Set(speed);
    m_threeLeft.Set(speed);
    m_twoRight.Set(speed);
    m_fourRight.Set(speed);
}
