
/*
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/LoadIntakeCommand.h"

LoadIntakeCommand::LoadIntakeCommand(LoaderSubBase *pLoaderBase, frc::XboxController *pController, double speed = 0.5) 
{
  m_pLoaderBase = pLoaderBase;
  m_pController = pController;
  m_speed = speed;

  // Use addRequirements() here to declare subsystem dependencies.

  AddRequirements(m_pLoaderBase);
}

// Called when the command is initially scheduled.
void LoadIntakeCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void LoadIntakeCommand::Execute() 
{

}

// Called once the command ends or is interrupted.
void LoadIntakeCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool LoadIntakeCommand::IsFinished() 
{
  return m_IsFinished;
}
*/