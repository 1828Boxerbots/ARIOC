// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

class TurretSubBase : public frc2::SubsystemBase {
 public:
  TurretSubBase();

  // Positive Speed - Clockwise | Negative Speed - CounterClockwise
  void MoveTurret(double speed);

  virtual void Init() {}
  virtual void TurretMotor(double speed) {}

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
