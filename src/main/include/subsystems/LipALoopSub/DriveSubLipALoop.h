// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "subsystems/DriveSubBase.h"
#include "constants.h"
#include "Util.h"
#include <frc/motorcontrol/Victor.h>
#include <frc/ADIS16448_IMU.h>

class DriveSubLipALoop : public DriveSubBase
{
 public:
  DriveSubLipALoop();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void Init() override;

  // Mecanum Motors
  void TopLeftMotor(double speed) override;
  void TopRightMotor(double speed) override;
  void BottomLeftMotor(double speed) override;
  void BottomRightMotor(double speed) override;

  virtual bool IsImuAvailable() override { return true; }
  double GetIMUAngle() override;

 private:
  frc::Victor m_topLeft     {PWM_TOPLEFTDRIVE_LIPALOOP};
  frc::Victor m_topRight    {PWM_TOPRIGHTDRIVE_LIPALOOP};
  frc::Victor m_bottomLeft  {PWM_BOTTOMLEFTDRIVE_LIPALOOP};
  frc::Victor m_bottomRight {PWM_BOTTOMRIGHTDRIVE_LIPALOOP};

  frc::ADIS16448_IMU m_imu;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
