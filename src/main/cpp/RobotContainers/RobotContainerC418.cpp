// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainers/RobotContainerC418.h"

RobotContainerC418::RobotContainerC418() 
{
    // Subsystems
    m_pDriveSub = new DriveSubC418;
    m_pLoadSub = new LoaderSubC418;
    m_pShootSub = new ShootSubC418;

    // Commands
    m_pDriveCMD = new DriveCommand(m_pDriveSub, &m_controllerOne, DriveSubBase::RC_STYLE);
    // Load CMDs
    m_pLoadAllCMD = new LoadCommand(m_pLoadSub, &m_controllerOne);
    m_pLoadIntakeCMD = new LoadCommand(m_pLoadSub, &m_controllerOne, 1.0, LoaderSubBase::intake);
    m_pLoadLowerCMD = new LoadCommand(m_pLoadSub, &m_controllerOne, 1.0, LoaderSubBase::lower);
    m_pLoadUpperCMD = new LoadCommand(m_pLoadSub, &m_controllerOne, 1.0, LoaderSubBase::upper);
    //Shoot CMD
    m_pShootCMD = new ShootCommand(m_pShootSub, &m_controllerOne);

    ConfigureButtonBindings();
}

void RobotContainerC418::Init()
{
    m_pDriveSub->Init();
    m_pLoadSub->Init();
    m_pShootSub->Init();

    m_pDriveSub->SetDefaultCommand(*m_pDriveCMD);
}

void RobotContainerC418::ConfigureButtonBindings()
{
    // Load
    SetAButton();
    SetBButton();
    SetXButton();
    SetYButton();
    // Shoot
    SetRightTrigger();
}

void RobotContainerC418::SetAButton()
{
    m_aButton.WhenHeld(m_pLoadIntakeCMD);
}

void RobotContainerC418::SetBButton()
{
    m_bButton.WhenHeld(m_pLoadUpperCMD);
}

void RobotContainerC418::SetXButton()
{
    m_xButton.WhenHeld(m_pLoadLowerCMD);
}

void RobotContainerC418::SetYButton()
{
    m_yButton.WhenHeld(m_pLoadAllCMD);
}

void RobotContainerC418::SetRightTrigger()
{
    m_rightTrigger.WhenHeld(m_pShootCMD);
}