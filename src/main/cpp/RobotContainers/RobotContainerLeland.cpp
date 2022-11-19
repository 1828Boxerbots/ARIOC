// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainers/RobotContainerLeland.h"

RobotContainerLeland::RobotContainerLeland()
{
    // Subsystems
    m_pDriveSub = new DriveSubLeland;
    m_pLoadSub = new LoaderSubLeland;
    m_pShootSub = new ShootSubLeland;

    // Commands
    m_pDriveCMD = new DriveCommand(m_pDriveSub, &m_controllerOne, DriveSubBase::RC_STYLE);
    //Load CMDs
    m_pLoadAllCMD = new LoadCommand(m_pLoadSub, &m_controllerOne);
    m_pLoadIntakeCMD = new LoadCommand(m_pLoadSub, &m_controllerOne, 1.0, LoaderSubBase::intake);
    m_pLoadLowerCMD = new LoadCommand(m_pLoadSub, &m_controllerOne, 1.0, LoaderSubBase::lower);
    //m_pLoadUpperCMD = new LoadCommand(m_pLoadSub, &m_controllerOne, 1.0, LoaderSubBase::upper);
    //Shoot CMD
    m_pShootCMD = new ShootCommand(m_pShootSub, &m_controllerOne);

    ConfigureButtonBindings();
}

void RobotContainerLeland::Init()
{
    m_pDriveSub->Init();
    m_pLoadSub->Init();
    m_pShootSub->Init();

    m_pDriveSub->SetDefaultCommand(*m_pDriveCMD);
}

void RobotContainerLeland::ConfigureButtonBindings()
{
    // Load
    SetAButton();
    SetBButton();
    SetXButton();
    SetYButton();
    // Shoot
    SetRightTrigger();
}

void RobotContainerLeland::SetAButton()
{
    m_aButton.WhenHeld(m_pLoadIntakeCMD);
}

void RobotContainerLeland::SetBButton()
{
    //m_bButton.WhenHeld(m_pLoadUpperCMD);
}

void RobotContainerLeland::SetXButton()
{
    m_xButton.WhenHeld(m_pLoadLowerCMD);
}

void RobotContainerLeland::SetYButton()
{
    m_yButton.WhenHeld(m_pLoadAllCMD);
}

void RobotContainerLeland::SetRightTrigger()
{
    m_rightTrigger.WhenHeld(m_pShootCMD);
}