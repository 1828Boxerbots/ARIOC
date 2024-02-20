// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>

#include "subsystems/DriveSubBase.h"
#include "subsystems/LoaderSubBase.h"
#include "subsystems/ShootSubBase.h"
#include "subsystems/VisionSubBase.h"

namespace autos 
{
  /**
   * Example static factory for an autonomous command.
   */
  frc2::CommandPtr House(DriveSubBase *pDrive);
  frc2::CommandPtr TimedHouse(DriveSubBase *pDrive);

  frc2::CommandPtr MovePassedLine(DriveSubBase *pDrive);
  frc2::CommandPtr Pos1(DriveSubBase *pDrive, LoaderSubBase *pLoader, ShootSubBase *pShoot, VisionSubBase *pVision);
  frc2::CommandPtr Pos2(DriveSubBase *pDrive, LoaderSubBase *pLoader, ShootSubBase *pShoot, VisionSubBase *pVision);
  frc2::CommandPtr Pos3(DriveSubBase *pDrive, LoaderSubBase *pLoader, ShootSubBase *pShoot, VisionSubBase *pVision);
}  // namespace autos
