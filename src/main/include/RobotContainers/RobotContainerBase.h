// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include "Constants.h"
#include "subsystems/DriveSubBase.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainerBase
{
 public:
  RobotContainerBase();

  virtual frc2::Command* GetAutonomousCommand();

  virtual void Init() = 0;

  virtual void SetDrive() = 0;

  virtual void SetAButton() {};
  virtual void SetBButton() {};
  virtual void SetXButton() {};
  virtual void SetYButton() {};
  virtual void SetStartButton() {};
  virtual void SetBackButton() {};
  virtual void SetLeftBumper() {};
  virtual void SetRightBumper() {};
  virtual void SetLeftTrigger() {};
  virtual void SetRightTrigger() {};


  protected:
  frc::XboxController m_controllerOne {0};
  frc::XboxController m_controllerTwo {1};

 private:

  void ConfigureButtonBindings();
};
