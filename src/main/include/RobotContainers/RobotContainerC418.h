// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "RobotContainers/RobotContainerBase.h"
#include "subsystems/C418Sub/DriveSubC418.h"
#include "subsystems/C418Sub/LoaderSubC418.h"
#include "subsystems/C418Sub/ShootSubC418.h"
#include "commands/LoadCommand.h"
#include "commands/DriveCommand.h"

class RobotContainerC418 : public RobotContainerBase
{
 public:
  RobotContainerC418();

  void Init() override;

  frc2::Command* GetAutonomousCommand() override;

  void SetAButton() override;
  void SetBButton() override;
  void SetXButton() override;
  void SetYButton() override;
  
  void SetRightTrigger() override;

  private:
  void ConfigureButtonBindings() override;
};
