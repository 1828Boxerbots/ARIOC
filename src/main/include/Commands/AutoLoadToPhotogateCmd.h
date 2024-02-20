// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/LoaderSubBase.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class AutoLoadToPhotogateCmd
    : public frc2::CommandHelper<frc2::Command, AutoLoadToPhotogateCmd> 
{
  public:
    AutoLoadToPhotogateCmd(LoaderSubBase *pLoad, double speed = 1.0);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

  private:
    bool m_isFinished = false;

    LoaderSubBase *m_pLoad = nullptr;
    double m_speed = 0.0;
};
