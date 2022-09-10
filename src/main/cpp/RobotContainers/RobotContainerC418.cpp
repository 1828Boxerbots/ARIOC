// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainers/RobotContainerC418.h"

RobotContainerC418::RobotContainerC418() 
{
    // Subsystems
    m_pDriveSub = new DriveSubC418;
    m_pLoadSub = new LoaderSubC418;

    // Commands
    m_pDriveCMD = new DriveCommand(m_pDriveSub, &m_controllerOne, DriveSubBase::RC_STYLE);
    m_pLoadAllCMD = new LoadCommand(m_pLoadSub, &m_controllerOne);

    ConfigureButtonBindings();
}

void RobotContainerC418::Init()
{
    m_pDriveSub->Init();
    m_pLoadSub->Init();

    m_pDriveSub->SetDefaultCommand(*m_pDriveCMD);

}

void RobotContainerC418::ConfigureButtonBindings()
{
    SetXButton();
}

void RobotContainerC418::SetXButton()
{
    m_xButton.WhenHeld(m_pLoadAllCMD);
}

frc2::Command* RobotContainerC418::GetAutonomousCommand()
{
    return nullptr;
}