// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <frc/XBoxController.h>
#include "subsystems/TurretSubBase.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class TurretCommand
    : public frc2::CommandHelper<frc2::Command, TurretCommand> 
{
 public:
  TurretCommand(TurretSubBase *pTurretSub, frc::XboxController *pController, double scale =  1.0);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

private:
  TurretSubBase *m_pTurretSub = nullptr;
  frc::XboxController *m_pController = nullptr;
  double m_scale = 1.0;
};
