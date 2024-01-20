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

    ConfigureButtonBindings();
}

void RobotContainerC418::Init()
{
    m_pDriveSub->Init();
    m_pLoadSub->Init();
    m_pShootSub->Init();

    m_pDriveSub->SetDefaultCommand(DriveCommand(m_pDriveSub, &m_driverController, DriveSubBase::RC_STYLE).ToPtr()); // m_pDriveCMD
}

void RobotContainerC418::ConfigureButtonBindings()
{
    // Load
    m_driverController.A().WhileTrue(LoadCommand(m_pLoadSub, &m_driverController, 1.0, LoaderSubBase::intake).ToPtr()); // m_aButton.WhenHeld(m_pLoadIntakeCMD);
    m_driverController.B().WhileTrue(LoadCommand(m_pLoadSub, &m_driverController, 1.0, LoaderSubBase::intake).ToPtr()); // m_bButton.WhenHeld(m_pLoadUpperCMD);
    m_driverController.X().WhileTrue(LoadCommand(m_pLoadSub, &m_driverController, 1.0, LoaderSubBase::lower).ToPtr()); // m_xButton.WhenHeld(m_pLoadLowerCMD);
    m_driverController.Y().WhileTrue(LoadCommand(m_pLoadSub, &m_driverController).ToPtr()); // m_yButton.WhenHeld(m_pLoadAllCMD);
    // Shoot
    m_driverController.RightTrigger().WhileTrue(ShootCommand(m_pShootSub, &m_driverController).ToPtr()); // m_rightTrigger.WhenHeld(m_pShootCMD);
}
