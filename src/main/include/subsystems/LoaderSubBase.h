// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

class LoaderSubBase : public frc2::SubsystemBase {
 public:
  LoaderSubBase();

  enum LoadMotors {intake, lower, upper, all};

  void Load(double speed, LoadMotors motor = LoadMotors::all);
  virtual void Init();
  virtual void LoadIntake(double speed);
  virtual void LoadLower(double speed);
  virtual void LoadUpper(double speed);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
