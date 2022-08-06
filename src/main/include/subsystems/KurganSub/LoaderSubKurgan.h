// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Victor.h>
#include "../LoaderSubBase.h"
#include "Constants.h"

class LoaderSubKurgan : public LoaderSubBase {
 public:
  LoaderSubKurgan();

  void Init() override;
  void LoadIntake(double speed) override;

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  frc::Victor m_loadMotor{PWM_LOADER_KURGAN};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
