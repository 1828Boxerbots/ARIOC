// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <frc/XboxController.h>
#include "subsystems/LoaderSubBase.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class LoadCommand : public frc2::CommandHelper<frc2::Command, LoadCommand>
{
 public:
  LoadCommand(LoaderSubBase *pLoader, frc::XboxController *pController, double speed = 1.0,
              LoaderSubBase::LoadMotors motor = LoaderSubBase::LoadMotors::all);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
   bool m_isFinished = false;

   LoaderSubBase *m_pLoader = nullptr;
   frc::XboxController *m_pController = nullptr;
   double m_speed;
   LoaderSubBase::LoadMotors m_motor;   

   int heart = 0;
};

