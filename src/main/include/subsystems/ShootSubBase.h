// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

class ShootSubBase : public frc2::SubsystemBase 
{
 public:
  ShootSubBase();
  
  virtual void Init() {}

  virtual void ShootMotor(double speed) {}

  void Shoot(double speed);

  void Periodic() override;

 private:
  
};
