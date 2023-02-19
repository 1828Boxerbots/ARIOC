// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/TurretCommand.h"

TurretCommand::TurretCommand(TurretSubBase *pTurretSub, frc::XboxController *pController, double scale)
{
  m_pTurretSub = pTurretSub;
  m_pController = pController;
  m_scale = scale;

  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_pTurretSub);
}

// Called when the command is initially scheduled.
void TurretCommand::Initialize() 
{

}

// Called repeatedly when this Command is scheduled to run
void TurretCommand::Execute() 
{
  // if pointers or scale are invalid, do nothing
  if (m_pController == nullptr or m_pTurretSub == nullptr or m_scale == 0.0)
  {
    return; // do nothing
  }

  // reverse
  if(m_pController->GetRightBumper())
  {
      m_pTurretSub->MoveTurret(-m_pController->GetLeftTriggerAxis() * m_scale);
  }
  else
  {
      m_pTurretSub->MoveTurret(m_pController->GetLeftTriggerAxis() * m_scale);
  }
}

// Called once the command ends or is interrupted.
void TurretCommand::End(bool interrupted) 
{
  // if pointers or scale are invalid, do nothing
  if (m_pController != nullptr)
  {
      m_pTurretSub->MoveTurret(0.0);
  }


}

// Returns true when the command should end.
bool TurretCommand::IsFinished() 
{
  return false;
}
