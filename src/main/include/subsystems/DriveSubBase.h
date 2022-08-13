// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

class DriveSubBase : public frc2::SubsystemBase 
{
 public:
  DriveSubBase();

  void Periodic() override;

  virtual void Init() = 0;

  virtual void LeftMotor(double speed) = 0;

  virtual void RightMotor(double speed) = 0;

  void MoveTank(double left, double right);

  void MoveArcade(double x, double y);

  void MoveRC (double up, double right);

 private:


};
