// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

class ClimbSubBase : public frc2::SubsystemBase 
{
 public:
  ClimbSubBase();

  void Periodic() override;

  virtual void Init() {}

  virtual void ClimbMotor(double speed) {}

  void Climb(double speed); 

 private:
};
