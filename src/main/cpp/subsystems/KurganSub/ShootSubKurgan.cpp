// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/KurganSub/ShootSubKurgan.h"

ShootSubKurgan::ShootSubKurgan() = default;

// This method will be called once per scheduler run
void ShootSubKurgan::Periodic() {}

void ShootSubKurgan::Init()
{
    m_rightShootOne.SetInverted(true);
    m_rightShootTwo.SetInverted(true);
}

void ShootSubKurgan::ShootMotor(double speed)
{
    m_leftShootOne.Set(speed);
    m_leftShootTwo.Set(speed);
    m_rightShootOne.Set(speed);
    m_rightShootTwo.Set(speed);
}
