// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubBase.h"

DriveSubBase::DriveSubBase() = default;

void DriveSubBase::Periodic() 
{ 
    static int heartbeat = 0;
    Util::Log("Heartbeat", heartbeat++, "DriveSubBase");

    Util::Log("RobotAngle", GetRobotAngle(), "DriveSubBase");
    Util::Log("EncoderL", GetEncoderL(), "DriveSubBase");
    Util::Log("EncoderR", GetEncoderR(), "DriveSubBase");
    Util::Log("EncoderL-Raw", GetEncoderRawL(), "DriveSubBase");
    Util::Log("EncoderR-Raw", GetEncoderRawR(), "DriveSubBase");
}

double DriveSubBase::GetRobotAngle()
{
    return GetIMUAngle();
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

void DriveSubBase::MoveMecanum(double angle, double pivot, double power)
{
    double topLeft;
    double topRight;
    double bottomLeft;
    double bottomRight;

    double moveSin = sin(angle - M_PI/4);
    double moveCos = cos(angle - M_PI/4);
    double moveMax = units::math::max(fabs(moveSin), fabs(moveCos));
    // if(fabs(moveSin) > fabs(moveCos))
    // {
    //     moveMax = fabs(moveSin);
    // }
    // else
    // {
    //     moveMax = fabs(moveCos);
    // }

    // Set Power
    topLeft = power * moveCos/moveMax + pivot;
    topRight = power * moveSin/moveMax - pivot;
    bottomLeft = power * moveSin/moveMax + pivot;
    bottomRight = power * moveCos/moveMax - pivot;

    Util::Log("topLeft", topLeft, "DriveSubBase");
    Util::Log("bottomRight", bottomRight, "DriveSubBase");
    Util::Log("topRight", topRight, "DriveSubBase");

    // Limiting Power so it does not go above one
    // if((power + fabs(pivot)) > 1)
    // {
    //     topLeft /= power + pivot;
    //     topRight /= power + pivot;
    //     bottomLeft /= power + pivot;
    //     bottomRight /= power + pivot;
    // }

    TopLeftMotor(topLeft);
    TopRightMotor(topRight);
    BottomLeftMotor(bottomLeft);
    BottomRightMotor(bottomRight);
}

void DriveSubBase::SetDrive(DriveStyles style)
{
    m_driveStyles = style;
}
