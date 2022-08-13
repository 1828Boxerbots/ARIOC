// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Victor.h>
#include "Constants.h"
#include "subsystems/LoaderSubBase.h"

class LoaderSubRocky : public LoaderSubBase 
{
 public:
  LoaderSubRocky();

  void Periodic() override;

  void Init() override;
  void LoadIntake(double speed) override;

 private:
  frc::Victor m_loaderMotor{PWM_LOADER_ROCKY};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
