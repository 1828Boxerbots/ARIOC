// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShootSubBase.h"
#include "Util.h"

ShootSubBase::ShootSubBase() = default;

// This method will be called once per scheduler run
void ShootSubBase::Periodic() 
{
    static int heartbeat = 0;
    Util::Log("Heartbeat", heartbeat++, "ShootSubBase");
}

void ShootSubBase::Shoot(double speed)
{
    ShootMotor(speed);
}

frc2::CommandPtr ShootSubBase::SetShooter(double speed)
{
    m_speed = speed;
    return RunOnce([this] { SetShootSpeed(); });
}
