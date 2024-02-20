// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "Constants.h"
#include "subsystems/DriveSubBase.h"
#include <frc/motorcontrol/victor.h>
#include <frc/Encoder.h>

class DriveSubC418 : public DriveSubBase
{
 public:
  DriveSubC418();

  void Periodic() override;

  void Init() override;
  void LeftMotor(double speed) override;
  void RightMotor(double speed) override;

  virtual bool IsEncodersAvailable() override { return true; }
  virtual double GetEncoderL() override;
  virtual double GetEncoderR() override;
  virtual double GetEncoderRawL() override;
  virtual double GetEncoderRawR() override;

 private:
  frc::Victor m_rightMotor {PWM_RIGHTDRIVE_C418};
  frc::Victor m_leftMotor {PWM_LEFTDRIVE_C418};

  frc::Encoder m_encoderR{DIO_ENCODER_A_RIGHT_C418, DIO_ENCODER_B_RIGHT_C418, false, frc::CounterBase::k4X};
  frc::Encoder m_encoderL{DIO_ENCODER_A_LEFT_C418,  DIO_ENCODER_B_LEFT_C418, true, frc::CounterBase::k4X};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
