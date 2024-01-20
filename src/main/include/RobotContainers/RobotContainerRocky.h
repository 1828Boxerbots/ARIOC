// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "RobotContainers/RobotContainerBase.h"
#include "subsystems/RockySub/DriveSubRocky.h"
#include "subsystems/RockySub/LoaderSubRocky.h"
#include "subsystems/RockySub/ShootSubRocky.h"
#include "subsystems/RockySub/TurretSubRocky.h"


class RobotContainerRocky : public RobotContainerBase
{
 public:
  RobotContainerRocky();

  void Init() override;

 private:
  void ConfigureButtonBindings() override;
};
