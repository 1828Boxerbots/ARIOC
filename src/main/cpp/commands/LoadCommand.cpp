// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/LoadCommand.h"
#include "Util.h"

LoadCommand::LoadCommand(LoaderSubBase *pLoader, frc::XboxController *pController, double speed, LoaderSubBase::LoadMotors motor)
{
  m_pLoader = pLoader;
  m_pController = pController;
  m_speed = speed;
  m_motor = motor;

  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_pLoader);
}

// Called when the command is initially scheduled.
void LoadCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void LoadCommand::Execute()
{
    Util::Log("LoadCommand", heart++);

  if(m_pLoader == nullptr or m_pController == nullptr)
  {
    return;
  }


  // If we are pressing the left bumper the loader should be edjecting
  // therefore negative speed
  if(m_pController->GetLeftBumper() == true)
  {
    m_pLoader->Load(-m_speed, m_motor);
  }
  else
  {
    m_pLoader->Load(m_speed, m_motor);
  }
}

// Called once the command ends or is interrupted.
void LoadCommand::End(bool interrupted)
{
  m_pLoader->Load(0.0, m_motor);
}

// Returns true when the command should end.
bool LoadCommand::IsFinished() {
  return false;
}
