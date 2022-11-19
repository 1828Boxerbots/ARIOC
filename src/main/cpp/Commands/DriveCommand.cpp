// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/DriveCommand.h"
#include "Util.h"

DriveCommand::DriveCommand(DriveSubBase *pDriveSub, frc::XboxController *pController, DriveSubBase::DriveStyles style,
                            double scale, double deadZone) 
{
  // Required Parameters
  m_pDriveSub = pDriveSub;
  m_pController = pController;
  m_style = style;

  // Non-Required Parameters
  m_scale = scale;
  m_deadZone = deadZone;

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
  if (m_pDriveSub == nullptr or m_pController == nullptr)
  {
    return;
  }

  // Reading Stick values and checking deadzone of those valus before setting a scale
  m_leftY = CheckDeadZone(-m_pController->GetLeftY()) * m_scale;
  m_rightY = CheckDeadZone(-m_pController->GetRightY()) * m_scale;
  m_leftX = CheckDeadZone(m_pController->GetLeftX()) * m_scale;
  m_rightX = CheckDeadZone(m_pController->GetRightX()) * m_scale; 
  
  Util::Log("LeftY", m_leftY);

  double moveAngle = atan2(m_leftY, m_leftX);
  double movePower = hypot(m_leftX, m_leftY);

  switch (m_style)
  {
    case DriveSubBase::DriveStyles::TANK_STYLE:
      m_pDriveSub->MoveTank(m_leftY, m_rightY); 
    break;

    case DriveSubBase::DriveStyles::ARCADE_STYLE:
      m_pDriveSub->MoveArcade(m_leftX, m_leftY);
    break;

    case DriveSubBase::DriveStyles::RC_STYLE:
      m_pDriveSub->MoveArcade(m_rightX, m_leftY);
    break;

    case DriveSubBase::DriveStyles::MECANUM_STYLE:
      m_pDriveSub->MoveMecanum(moveAngle, m_rightX, movePower);
    break;

    default:
      m_pDriveSub->MoveTank(0.0, 0.0);
    break;
  }
}

double DriveCommand::CheckDeadZone(double stickInput)
{
  if(stickInput > -m_deadZone && stickInput < m_deadZone)
  {
    return 0.0;
  }

  return stickInput;
}

// Called once the command ends or is interrupted.
void DriveCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveCommand::IsFinished() 
{
  return m_IsFinished;
}
