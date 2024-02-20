// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/AutoVisionAlignCmd.h"

AutoVisionAlignCmd::AutoVisionAlignCmd(DriveSubBase *pDrive, VisionSubBase *pVision, double deadzone, double speed) 
{
  m_pDrive = pDrive;
  m_pVision = pVision;
  m_deadzone = fabsf(deadzone);
  m_speed = fabs(speed);

  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pDrive);
  AddRequirements(pVision);
}

// Called when the command is initially scheduled.
void AutoVisionAlignCmd::Initialize() 
{
  if (m_pDrive == nullptr or m_pVision == nullptr)
  {
    m_isFinished = true;
    return;
  }

  m_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void AutoVisionAlignCmd::Execute() 
{
  if (m_pDrive == nullptr or m_pVision == nullptr)
  {
    m_isFinished = true;
    return;
  }

  if (m_pVision->GetYaw() > 0.0)
  {
    // turn right
    m_pDrive->MoveTank(m_speed, -m_speed);
  }
  else
  {
    // turn left
    m_pDrive->MoveTank(-m_speed, m_speed);
  }

  m_isFinished = (m_pVision->GetYaw() > -m_deadzone and m_pVision->GetYaw() < m_deadzone);
}

// Called once the command ends or is interrupted.
void AutoVisionAlignCmd::End(bool interrupted) 
{
  if (m_pDrive != nullptr)
  {
    m_pDrive->MoveTank(0.0, 0.0);
  }
}

// Returns true when the command should end.
bool AutoVisionAlignCmd::IsFinished() 
{
  return m_isFinished;
}
