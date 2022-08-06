// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/TurretSubBase.h"

TurretSubBase::TurretSubBase() = default;

// This method will be called once per scheduler run
void TurretSubBase::Periodic() {}

// Positive Speed - Clockwise | Negative Speed - CounterClockwise
void TurretSubBase::MoveTurret(double speed)
{
    TurretMotor(speed);
}
