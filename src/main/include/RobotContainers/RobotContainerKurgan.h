// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "RobotContainerBase.h"

#include "subsystems/KurganSub/DriveSubKurgan.h"
#include "subsystems/KurganSub/LoaderSubKurgan.h"
#include "subsystems/KurganSub/ShootSubKurgan.h"

#include "Commands/LoadCommand.h"

class RobotContainerKurgan : public RobotContainerBase
{
 public:
  RobotContainerKurgan();

  void Init() override;

 private:
  void ConfigureButtonBindings() override;

  LoadCommand *m_pEjectCMD = nullptr;
};
