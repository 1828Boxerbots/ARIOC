// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "RobotContainers/RobotContainerBase.h"
#include "subsystems/C418Sub/DriveSubC418.h"
#include "subsystems/C418Sub/LoaderSubC418.h"
#include "subsystems/C418Sub/ShootSubC418.h"

class RobotContainerC418 : public RobotContainerBase
{
 public:
  RobotContainerC418();

  void Init() override;

  virtual void ConfigureButtonBindings() override;

};
