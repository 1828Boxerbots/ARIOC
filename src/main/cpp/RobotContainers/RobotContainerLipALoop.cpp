// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainers/RobotContainerLipALoop.h"

RobotContainerLipALoop::RobotContainerLipALoop()
{
    m_pDriveSub = new DriveSubLipALoop;
}

void RobotContainerLipALoop::Init()
{
    m_pDriveSub->Init();
    m_pDriveSub->SetDefaultCommand(DriveCommand(m_pDriveSub, &m_driverController, DriveSubBase::MECANUM_STYLE, 0.4).ToPtr()); // m_pDriveCMD
}

void RobotContainerLipALoop::ConfigureButtonBindings()
{

}
