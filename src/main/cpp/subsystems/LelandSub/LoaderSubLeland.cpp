// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LelandSub/LoaderSubLeland.h"
#include "Util.h"

LoaderSubLeland::LoaderSubLeland() = default;

// This method will be called once per scheduler run
void LoaderSubLeland::Periodic() {}

void LoaderSubLeland::Init()
{   
    m_lowerLoaderMotor.SetInverted(true);

    LoadIntake(0);
    LoadLower(0);
    //LoadUpper(0);
}

void LoaderSubLeland::LoadIntake(double speed)
{
    m_intakeMotor.Set(speed);
    Util::Log("Leland Intake", speed);
}

void LoaderSubLeland::LoadLower(double speed)
{
    m_lowerLoaderMotor.Set(speed);
    Util::Log("Leland Lower", speed);
}

// void LoaderSubLeland::LoadUpper(double speed)
// {
//     m_upperLoaderMotor.Set(speed);
//     Util::Log("Leland Upper", speed);
// }
