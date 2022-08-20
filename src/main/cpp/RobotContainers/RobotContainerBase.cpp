// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainers/RobotContainerBase.h"

RobotContainerBase::RobotContainerBase()
{
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
}

void RobotContainerBase::ConfigureButtonBindings() 
{
  // Configure your button bindings here
}

frc2::Command* RobotContainerBase::GetAutonomousCommand() 
{
  // An example command will be run in autonomous
  return nullptr;
}
