// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/DriveCommand.h"

DriveCommand::DriveCommand(DriveSubBase *pDriveBase, frc::XboxController *pController, DriveSubBase::DriveStyles style) 
{
  m_pDriveBase = pDriveBase;
  m_pController = pController;
  m_style = style;

  // Use addRequirements() here to declare subsystem dependencies.

  AddRequirements(pDriveBase);
}

// Called when the command is initially scheduled.
void DriveCommand::Initialize() 
{
  m_pDriveBase->Init();
  m_pDriveBase->SetDrive(m_style);
}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute() 
{
  switch (m_style)
  {
    case DriveSubBase::DriveStyles::TANK_STYLE:
    break;
  }
}

/*double DriveCommand::CheckDeadZone(double stickInput)
{
  if(stickInput > -m_deadZoneRange && stickInput < m_deadZoneRange)
  {
    return 0.0;
  }

  return stickInput;
}

*/
// Called once the command ends or is interrupted.
void DriveCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveCommand::IsFinished() 
{
  return m_IsFinished;
}
