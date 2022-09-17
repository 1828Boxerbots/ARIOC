// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ShootCommand.h"

ShootCommand::ShootCommand(ShootSubBase *pShootSub, frc::XboxController *pController, double scale)
{
  m_pShootSub = pShootSub;
  m_pController = pController;
  m_scale = scale;

  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_pShootSub);
}

// Called when the command is initially scheduled.
void ShootCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ShootCommand::Execute()
{
  if(m_pController->GetLeftBumper())
  {
    m_pShootSub->Shoot(-(m_pController->GetRightTriggerAxis() * m_scale));
  }
  else
  {
    m_pShootSub->Shoot(m_pController->GetRightTriggerAxis() * m_scale);
  }
}

// Called once the command ends or is interrupted.
void ShootCommand::End(bool interrupted)
{
  m_pShootSub->Shoot(0.0);
}

// Returns true when the command should end.
bool ShootCommand::IsFinished()
{
  return false;
}
