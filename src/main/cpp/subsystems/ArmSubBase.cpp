// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ArmSubBase.h"

ArmSubBase::ArmSubBase() = default;

// This method will be called once per scheduler run
void ArmSubBase::Periodic() {}

void ArmSubBase::MoveArm(double speed)
{
    ArmMotor(speed);
}
