// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubBase.h"

DriveSubBase::DriveSubBase() = default;

// This method will be called once per scheduler run
    void DriveSubBase::Periodic() 
{
}

    void DriveSubBase::MoveTank(double left, double right)
{
    LeftMotor(left);
    RightMotor(right);
}

    void DriveSubBase::MoveArcade(double x, double y)
{
    double left = y + x;
    double right = y - x;

    MoveTank(left, right);
}

void DriveSubBase::MoveRC(double up, double right)
{
    
}