// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "RobotContainers/RobotContainerBase.h"
#include "subsystems/LelandSub/DriveSubLeland.h"
#include "subsystems/LelandSub/LoaderSubLeland.h"
#include "subsystems/LelandSub/ShootSubLeland.h"

class RobotContainerLeland : public RobotContainerBase
{
 public:
  RobotContainerLeland();

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
