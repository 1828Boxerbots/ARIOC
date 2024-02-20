// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/AutoShootCmd.h"

AutoShootCmd::AutoShootCmd(ShootSubBase *pShoot, LoaderSubBase *pLoader, double speed) 
{
  m_pShoot = pShoot;
  m_pLoader = pLoader;
  m_shooterSpeed = speed;

  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pShoot);
  AddRequirements(pLoader);
}

// Called when the command is initially scheduled.
void AutoShootCmd::Initialize() 
{
  if (m_pShoot == nullptr or m_pLoader == nullptr)
  {
    m_isFinished = true;
    return;
  }

  // stop loader
  m_pLoader->Load(0.0);
  m_pShoot->Shoot(m_shooterSpeed);

  // start timer, since shooter motor has started
  m_timer.Reset();
  m_timer.Start();
  
  m_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void AutoShootCmd::Execute() 
{
  if (m_pShoot == nullptr or m_pLoader == nullptr)
  {
    m_isFinished = true;
    return;
  }

  if (m_timer.Get() > 1.0_s) // keep shooter-motor on for 1 second
  {
    m_pLoader->Load(1.0);
  }
  m_isFinished = m_timer.Get() > 2.0_s; // load for 1 second
}

// Called once the command ends or is interrupted.
void AutoShootCmd::End(bool interrupted) 
{
  if (m_pShoot != nullptr and m_pLoader != nullptr)
  {
    // stop both shooter and loader motors
    m_pShoot->Shoot(0.0);
    m_pLoader->Load(0.0);
  }
}

// Returns true when the command should end.
bool AutoShootCmd::IsFinished() 
{
  return m_isFinished;
}
