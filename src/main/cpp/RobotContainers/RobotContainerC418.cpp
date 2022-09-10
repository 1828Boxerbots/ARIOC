// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainers/RobotContainerC418.h"

RobotContainerC418::RobotContainerC418() 
{
    // Subsystems
    m_pDriveSub = new DriveSubC418;

    // Commands
    m_pDriveCMD = new DriveCommand(m_pDriveSub, &m_controllerOne, DriveSubBase::RC_STYLE);
}

void RobotContainerC418::Init()
{
    m_pDriveSub->SetDefaultCommand(*m_pDriveCMD);
    m_pDriveSub->Init();
}

void RobotContainerC418::ConfigureButtonBindings()
{

}

frc2::Command* RobotContainerC418::GetAutonomousCommand()
{
    return nullptr;
}