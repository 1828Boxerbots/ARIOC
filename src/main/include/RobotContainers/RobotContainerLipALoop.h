// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "RobotContainerBase.h"
#include "subsystems/LipALoopSub/DriveSubLipALoop.h"

class RobotContainerLipALoop : public RobotContainerBase
{
 public:
  RobotContainerLipALoop();

  void Init() override;

 private:
  void ConfigureButtonBindings() override;
};
