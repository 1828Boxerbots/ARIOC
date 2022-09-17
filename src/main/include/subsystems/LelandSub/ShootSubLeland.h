// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "subsystems/ShootSubBase.h"
#include <frc/motorcontrol/Victor.h>
#include "Constants.h"

class ShootSubLeland : public ShootSubBase
{
 public:
  ShootSubLeland();

  void Periodic() override;

  void Init() override;
  void ShootMotor(double speed) override;

 private:
  frc::Victor m_shooterMotor{PWM_SHOOTER_LELAND};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
