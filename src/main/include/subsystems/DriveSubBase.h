// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <units/math.h>
#include "Util.h"

class DriveSubBase : public frc2::SubsystemBase 
{
 public:

 enum DriveStyles
 {
   TANK_STYLE,
   ARCADE_STYLE,
   RC_STYLE,
   MECANUM_STYLE
 };

 void SetDrive(DriveStyles style);

  DriveSubBase();

  void Periodic() override;

  virtual void Init() = 0;

  // Normal Motors
  virtual void LeftMotor(double speed) {}
  virtual void RightMotor(double speed) {}

  // Mecanum Motors
  virtual void TopLeftMotor(double speed) {}
  virtual void TopRightMotor(double speed) {}
  virtual void BottomLeftMotor(double speed) {}
  virtual void BottomRightMotor(double speed) {}

  void MoveTank(double left, double right);
  void MoveArcade(double x, double y);

  void MoveMecanum(double angle, double pivot, double power);

 private:

 protected:

   DriveStyles m_driveStyles = RC_STYLE;

};
