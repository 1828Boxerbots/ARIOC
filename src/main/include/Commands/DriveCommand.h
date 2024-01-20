// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DriveSubBase.h"
#include <frc/XboxController.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class DriveCommand : public frc2::CommandHelper<frc2::Command, DriveCommand> 
{
 public:
  DriveCommand(DriveSubBase *pDriveSub, frc::XboxController *pController, DriveSubBase::DriveStyles style, double scale = 1.0, double deadZone = 0.1);

  void Initialize() override;

  void Execute() override;
  double CheckDeadZone(double stickInput);

  void End(bool interrupted) override;

  bool IsFinished() override;

    private:
    DriveSubBase* m_pDriveSub;
    frc::XboxController* m_pController;
    DriveSubBase::DriveStyles m_style;

    bool m_IsFinished = false;
    double m_deadZone = 0.1;
    double m_scale = 1.0;

    double m_leftY = 0.0;
    double m_rightY = 0.0;
    double m_leftX = 0.0;
    double m_rightX = 0.0;
};
