// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>

#include "RobotContainers/RobotContainerBase.h"
#include "RobotContainers/RobotContainerC418.h"
#include "RobotContainers/RobotContainerLeland.h"
#include "RobotContainers/RobotContainerKurgan.h"
#include "RobotContainers/RobotContainerLipALoop.h"
#include "RobotContainers/RobotContainerRocky.h"

class Robot : public frc::TimedRobot 
{
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  frc2::Command* m_autonomousCommand = nullptr;

  // ************************************************************
  // NOTE: uncomment correct line for robot you want to target.
  // ************************************************************
  // RobotContainerBase *m_pContainer = new RobotContainerC418;
  // RobotContainerBase *m_pContainer = new RobotContainerLeland;
  // RobotContainerBase *m_pContainer = new RobotContainerKurgan;
  // RobotContainerBase *m_pContainer = new RobotContainerLipALoop;
  RobotContainerBase *m_pContainer = new RobotContainerRocky;
};
