// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "../ShootSubBase.h"
#include "Constants.h"
#include <frc/motorcontrol/Victor.h>

class ShootSubKurgan : public ShootSubBase {
 public:
  ShootSubKurgan();

  void Init() override;
  void ShootMotor(double speed) override;

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  frc::Victor m_leftShootOne{PWM_LEFTSHOOT_ONE_KURGAN};
  frc::Victor m_leftShootTwo{PWM_LEFTSHOOT_TWO_KURGAN};
  frc::Victor m_rightShootOne{PWM_RIGHTSHOOT_ONE_KURGAN};
  frc::Victor m_rightShootTwo{PWM_RIGHTSHOOT_TWO_KURGAN};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
