// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainers/RobotContainerRocky.h"

RobotContainerRocky::RobotContainerRocky()
{
    // Subsystems
    m_pDriveSub = new DriveSubRocky;
    m_pLoadSub = new LoaderSubRocky;
    m_pShootSub = new ShootSubRocky;
    m_pTurretSub = new TurretSubRocky;

    ConfigureButtonBindings();
}

void RobotContainerRocky::Init()
{
    m_pDriveSub->Init();
    m_pLoadSub->Init();
    m_pShootSub->Init();

    m_pDriveSub->SetDefaultCommand(DriveCommand(m_pDriveSub, &m_driverController, DriveSubBase::RC_STYLE).ToPtr()); //m_pDriveCMD
}

void RobotContainerRocky::ConfigureButtonBindings()
{
    // Load
    // -- //m_aButton.WhenHeld(m_pLoadIntakeCMD);
    // -- //m_bButton.WhenHeld(m_pLoadUpperCMD);
    // -- //m_xButton.WhenHeld(m_pLoadLowerCMD);
    m_driverController.Y().WhileTrue(LoadCommand(m_pLoadSub, &m_driverController).ToPtr()); //m_yButton.WhenHeld(m_pLoadAllCMD);
    // Shoot
    m_driverController.RightTrigger().WhileTrue(ShootCommand(m_pShootSub, &m_driverController).ToPtr()); //m_rightTrigger.WhenHeld(m_pShootCMD);
    // Turret
    m_driverController.LeftTrigger().WhileTrue(TurretCommand(m_pTurretSub, &m_driverController).ToPtr()); //m_leftTrigger.WhenHeld(m_pTurretCMD);
}
