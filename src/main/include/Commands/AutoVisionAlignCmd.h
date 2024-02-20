// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveSubBase.h"
#include "subsystems/VisionSubBase.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class AutoVisionAlignCmd
    : public frc2::CommandHelper<frc2::Command, AutoVisionAlignCmd> 
{
  public:
    AutoVisionAlignCmd(DriveSubBase *pDrive, VisionSubBase *pVision, double deadzone, double speed);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;
  
  private:
    DriveSubBase *m_pDrive = nullptr;
    VisionSubBase *m_pVision = nullptr;
    double m_deadzone = 0.0;
    double m_speed = 0.0;

    bool m_isFinished = false;
};
