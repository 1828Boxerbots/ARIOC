// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/DriveCommand.h"

DriveCommand::DriveCommand(DriveSubBase *pDriveSub, frc::XboxController *pController, DriveSubBase::DriveStyles style) 
{
  m_pDriveSub = pDriveSub;
  m_pController = pController;
  m_style = style;

  // Use addRequirements() here to declare subsystem dependencies.

  AddRequirements(pDriveSub);
}

// Called when the command is initially scheduled.
void DriveCommand::Initialize() 
{
  m_pDriveSub->Init();
  m_pDriveSub->SetDrive(m_style);
}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute() 
{
  m_left = m_pController->GetLeftY();
  m_right = m_pController->GetRightY();
  double x = m_pController->GetLeftX();
  double y = m_pController->GetLeftY();
   
  if (m_pDriveSub == nullptr or m_pController == nullptr)
  {
   return;
  }


  
  switch (m_style)
  {
    case DriveSubBase::DriveStyles::TANK_STYLE:

    m_pDriveSub->MoveTank(-m_left, -m_right); 

    break;

    case DriveSubBase::DriveStyles::ARCADE_STYLE:

    m_pDriveSub->MoveArcade(x,-y);

    break;

    case DriveSubBase::DriveStyles::RC_STYLE:

    m_pDriveSub->MoveRC(x, m_right);

    break;

    default:

    m_pDriveSub->MoveTank(0.0, 0.0);

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
