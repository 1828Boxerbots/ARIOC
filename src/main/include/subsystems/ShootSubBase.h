// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h>

class ShootSubBase : public frc2::SubsystemBase 
{
    public:
        ShootSubBase();

        virtual void Init() = 0;

        void Shoot(double speed);

        void Periodic() override;

        frc2::CommandPtr SetShooter(double speed);

    private:
        virtual void ShootMotor(double speed) = 0;
        void SetShootSpeed() { Shoot(m_speed); }
        double m_speed = 1.0;
};
