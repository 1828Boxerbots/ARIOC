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
    ConfigureButtonBindings();
}

void RobotContainerLeland::Init()
{
    m_pDriveSub->Init();
    m_pLoadSub->Init();
    m_pShootSub->Init();

    m_pDriveSub->SetDefaultCommand(DriveCommand(m_pDriveSub, &m_driverController, DriveSubBase::RC_STYLE).ToPtr()); // m_pDriveCMD
}

void RobotContainerLeland::ConfigureButtonBindings()
{
    // Load
    m_driverController.A().WhileTrue(LoadCommand(m_pLoadSub, &m_driverController, 1.0, LoaderSubBase::intake).ToPtr()); //m_aButton.WhenHeld(m_pLoadIntakeCMD);
    //m_bButton.WhenHeld(m_pLoadUpperCMD);
    m_driverController.X().WhileTrue(LoadCommand(m_pLoadSub, &m_driverController, 1.0, LoaderSubBase::lower).ToPtr()); //m_xButton.WhenHeld(m_pLoadLowerCMD);
    m_driverController.Y().WhileTrue(LoadCommand(m_pLoadSub, &m_driverController).ToPtr()); //m_yButton.WhenHeld(m_pLoadAllCMD);
    // Shoot
    m_driverController.RightTrigger().WhileTrue(ShootCommand(m_pShootSub, &m_driverController).ToPtr()); //m_rightTrigger.WhenHeld(m_pShootCMD);
}
