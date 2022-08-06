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

  virtual void Init() {}

  virtual void LeftMotor(double speed) {}

  virtual void RightMotor(double speed) {}

  void MoveTank(double left, double right);

  void MoveArcade(double x, double y);

 private:


};
