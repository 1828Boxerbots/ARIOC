// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

class ArmSubBase : public frc2::SubsystemBase {
 public:
  ArmSubBase();

  // Positive speed - arm up | Negative speed - arm down
  void MoveArm(double speed);

  virtual void ArmMotor(double speed) {}
  virtual void Init() {}

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
