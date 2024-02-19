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

    ConfigureButtonBindings();
}

void RobotContainerKurgan::Init()
{
    m_pDriveSub->Init();
    m_pLoadSub->Init();
    m_pShootSub->Init();

    m_pDriveSub->SetDefaultCommand(DriveCommand(m_pDriveSub, &m_driverController, DriveSubBase::RC_STYLE, 1.0).ToPtr()); // m_pDriveCMD
}

void RobotContainerKurgan::ConfigureButtonBindings()
{
    m_driverController.X().WhileTrue(LoadCommand(m_pLoadSub, &m_driverController, -1.0, LoaderSubBase::intake).ToPtr()); // m_xButton.WhenHeld(m_pEjectCMD);
    m_driverController.Y().WhileTrue(LoadCommand(m_pLoadSub, &m_driverController, 1.0, LoaderSubBase::intake).ToPtr()); // m_yButton.WhenHeld(m_pLoadIntakeCMD);
    m_driverController.RightTrigger().WhileTrue(ShootCommand(m_pShootSub, &m_driverController).ToPtr()); // m_rightTrigger.WhenHeld(m_pShootCMD);
}
