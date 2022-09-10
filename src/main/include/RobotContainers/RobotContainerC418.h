// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "RobotContainers/RobotContainerBase.h"
#include "Commands/DriveCommand.h"
#include "subsystems/C418Sub/DriveSubC418.h"
#include "subsystems/DriveSubBase.h"

class RobotContainerC418 : public RobotContainerBase
{
 public:
  RobotContainerC418();

   void Init() override;

   frc2::Command* GetAutonomousCommand() override;

  private:
  void ConfigureButtonBindings() override;

  DriveCommand *m_pDriveCMD = nullptr;
};
