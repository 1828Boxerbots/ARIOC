// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Victor.h>
#include "../DriveSubBase.h"
#include "Constants.h"

class DriveSubKurgan : public DriveSubBase
{
 public:
  DriveSubKurgan();

  void Init() override;
  void LeftMotor(double speed) override;
  void RightMotor(double speed) override;

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  frc::Victor m_leftMotorOne{PWM_LEFTDRIVE_ONE_KURGAN};
  frc::Victor m_leftMotorTwo{PWM_LEFTDRIVE_TWO_KURGAN};
  frc::Victor m_rightMotorOne{PWM_RIGHTDRIVE_ONE_KURGAN};
  frc::Victor m_rightMotorTwo{PWM_RIGHTDRIVE_TWO_KURGAN};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
