// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "subsystems/LoaderSubBase.h"
#include "Constants.h"
#include <frc/motorcontrol/Victor.h>

class LoaderSubLeland : public LoaderSubBase
{
 public:
  LoaderSubLeland();

  void Periodic() override;

  void Init();
  void LoadIntake(double speed) override;
  void LoadLower(double speed) override;
  //void LoadUpper(double speed) override;

 private:
  frc::Victor m_intakeMotor{PWM_INTAKE_LELAND};
  frc::Victor m_lowerLoaderMotor{PWM_LOWERINNER_LELAND};
  //frc::Victor m_upperLoaderMotor{PWM_UPPERINNER_LELAND};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
