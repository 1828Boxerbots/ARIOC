// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainers/RobotContainerKurgan.h"

RobotContainerKurgan::RobotContainerKurgan()
{
    // Subsystems
    m_pDriveSub = new DriveSubKurgan;
    m_pLoadSub = new LoaderSubKurgan;
    m_pShootSub = new ShootSubKurgan;

    // Commands
    m_pDriveCMD = new DriveCommand(m_pDriveSub, &m_controllerOne, DriveSubBase::RC_STYLE, 0.5);
    m_pLoadIntakeCMD = new LoadCommand(m_pLoadSub, &m_controllerOne, 1.0, LoaderSubBase::intake);
    m_pEjectCMD = new LoadCommand(m_pLoadSub, &m_controllerOne, -1.0, LoaderSubBase::intake);
    m_pShootCMD = new ShootCommand(m_pShootSub, &m_controllerOne);
    ConfigureButtonBindings();
}

void RobotContainerKurgan::Init()
{
    m_pDriveSub->Init();
    m_pLoadSub->Init();
    m_pShootSub->Init();

    m_pDriveSub->SetDefaultCommand(*m_pDriveCMD);
}

void RobotContainerKurgan::ConfigureButtonBindings()
{
    SetXButton();
    SetYButton();
    SetRightTrigger();
}

void RobotContainerKurgan::SetXButton()
{
    // Eject
    m_xButton.WhenHeld(m_pEjectCMD);
}

void RobotContainerKurgan::SetYButton()
{
    // Load
    m_yButton.WhenHeld(m_pLoadIntakeCMD);
}

void RobotContainerKurgan::SetRightTrigger()
{
    // Shoot
    m_rightTrigger.WhenHeld(m_pShootCMD);
}
