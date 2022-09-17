// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Victor.h>
#include "Constants.h"
#include "subsystems/DriveSubBase.h"

class DriveSubLeland : public DriveSubBase 
{
 public:
  DriveSubLeland();

  void Periodic() override;

  void Init() override;
  void LeftMotor(double speed) override;
  void RightMotor(double speed) override;

 private:
  frc::Victor m_rightMotor {PWM_RIGHTDRIVE_LELAND};
  frc::Victor m_leftMotor {PWM_LEFTDRIVE_LELAND};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
