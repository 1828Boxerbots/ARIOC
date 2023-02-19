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

    // Commands
    m_pDriveCMD = new DriveCommand(m_pDriveSub, &m_controllerOne, DriveSubBase::RC_STYLE);
    //Load CMDs
    m_pLoadAllCMD = new LoadCommand(m_pLoadSub, &m_controllerOne);
    //m_pLoadIntakeCMD = new LoadCommand(m_pLoadSub, &m_controllerOne, 1.0, LoaderSubBase::intake);
    //m_pLoadLowerCMD = new LoadCommand(m_pLoadSub, &m_controllerOne, 1.0, LoaderSubBase::lower);
    //m_pLoadUpperCMD = new LoadCommand(m_pLoadSub, &m_controllerOne, 1.0, LoaderSubBase::upper);
    //Shoot CMD
    m_pShootCMD = new ShootCommand(m_pShootSub, &m_controllerOne);

    //Turret
    m_pTurretCMD = new TurretCommand(m_pTurretSub, &m_controllerOne);

    ConfigureButtonBindings();
}

void RobotContainerRocky::Init()
{
    m_pDriveSub->Init();
    m_pLoadSub->Init();
    m_pShootSub->Init();

    m_pDriveSub->SetDefaultCommand(*m_pDriveCMD);
}

void RobotContainerRocky::ConfigureButtonBindings()
{
    // Load
    SetAButton();
    SetBButton();
    SetXButton();
    SetYButton();
    // Shoot
    SetRightTrigger();
    // Turret
    SetLeftTrigger();
}

void RobotContainerRocky::SetAButton()
{
    m_aButton.WhenHeld(m_pLoadIntakeCMD);
}

void RobotContainerRocky::SetBButton()
{
    //m_bButton.WhenHeld(m_pLoadUpperCMD);
}

void RobotContainerRocky::SetXButton()
{
    m_xButton.WhenHeld(m_pLoadLowerCMD);
}

void RobotContainerRocky::SetYButton()
{
    m_yButton.WhenHeld(m_pLoadAllCMD);
}

void RobotContainerRocky::SetRightTrigger()
{
    m_rightTrigger.WhenHeld(m_pShootCMD);
}
void RobotContainerRocky::SetLeftTrigger()
{
    m_leftTrigger.WhenHeld(m_pTurretCMD);
}
