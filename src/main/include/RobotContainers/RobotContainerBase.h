// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <frc2/command/Command.h>
#include <frc2/command/button/CommandXboxController.h>
//#include <frc2/command/button/button.h> // no such file or directory in 2024
#include "Constants.h"
#include "subsystems/DriveSubBase.h"
#include "subsystems/LoaderSubBase.h"
#include "subsystems/ShootSubBase.h"
#include "subsystems/TurretSubBase.h"
#include "commands/LoadCommand.h"
#include "commands/DriveCommand.h"
#include "commands/ShootCommand.h"
#include "commands/TurretCommand.h"

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

  virtual void Init() = 0;

  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandXboxController m_driverController{USB_CONTROLLER};
  frc2::CommandXboxController m_driverController2{USB_CONTROLLER2};

  // Subsystems
  DriveSubBase *m_pDriveSub = nullptr;
  LoaderSubBase *m_pLoadSub = nullptr;
  ShootSubBase *m_pShootSub = nullptr;
  TurretSubBase *m_pTurretSub = nullptr;

 protected:
  virtual void ConfigureButtonBindings();

};
