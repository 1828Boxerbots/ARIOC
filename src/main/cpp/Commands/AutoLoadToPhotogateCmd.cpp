// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/AutoLoadToPhotogateCmd.h"

AutoLoadToPhotogateCmd::AutoLoadToPhotogateCmd(LoaderSubBase *pLoad, double speed) 
{
  m_pLoad = pLoad;
  m_speed = speed;

  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pLoad);
}

// Called when the command is initially scheduled.
void AutoLoadToPhotogateCmd::Initialize() 
{
  if (m_pLoad == nullptr)
  {
    m_isFinished = true;
    return;
  }

  if (m_pLoad->HasPhotogate() == false)
  {
    m_isFinished = true;
    return;
  }

  m_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void AutoLoadToPhotogateCmd::Execute() 
{
  if (m_pLoad == nullptr or m_isFinished == true)
  {
    m_isFinished = true;
    return;
  }
  
  m_pLoad->Load(m_speed, LoaderSubBase::all);
  m_isFinished = m_pLoad->IsAtPhotogate();
}

// Called once the command ends or is interrupted.
void AutoLoadToPhotogateCmd::End(bool interrupted) 
{
  // do NOT reset load speed
}

// Returns true when the command should end.
bool AutoLoadToPhotogateCmd::IsFinished() 
{
  return m_isFinished;
}
