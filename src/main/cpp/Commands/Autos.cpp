// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Autos.h"

#include <units/length.h>
#include <frc2/command/Commands.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/ParallelCommandGroup.h>

#include "commands/AutoTimedForwardCmd.h"
#include "commands/AutoForwardCmd.h"
#include "commands/AutoTurnCmd.h"
#include "commands/AutoVisionAlignCmd.h"
#include "commands/AutoShootCmd.h"
#include "commands/AutoLoadCmd.h"
#include "commands/AutoLoadToPhotogateCmd.h"
#include "commands/AutoTimerCmd.h"


frc2::CommandPtr autos::House(DriveSubBase *pDrive)  
{
    units::inch_t floorDist = 120.0_in * std::sqrt(2.0);
  return frc2::SequentialCommandGroup
    (
        AutoForwardCmd(pDrive, (double)(units::meter_t)120.0_in, 1.0), // left wall
        AutoTurnCmd(pDrive, 45.0, 0.5),
        AutoForwardCmd(pDrive, (double)(units::meter_t)120.0_in, 1.0),
        AutoTurnCmd(pDrive, 90.0+45.0, 0.5), // top of roof
        AutoForwardCmd(pDrive, (double)(units::meter_t)120.0_in, 1.0),
        AutoTurnCmd(pDrive, 45.0+90.0+45.0, 0.5),
        AutoForwardCmd(pDrive, (double)(units::meter_t)120.0_in, 1.0), // right wall
        AutoTurnCmd(pDrive, 90.0+45.0+90.0+45.0, 0.5),
        AutoForwardCmd(pDrive, (double)(units::meter_t)floorDist, 1.0), // floor
        AutoTurnCmd(pDrive, 90.0+90.0+45.0+90.0+45.0, 0.5) // starting point
    ).ToPtr();
}
frc2::CommandPtr autos::TimedHouse(DriveSubBase *pDrive)  
{
  return frc2::SequentialCommandGroup
    (
        AutoTimedForwardCmd(pDrive, 0.5_s, 1.0), // left wall
        AutoTurnCmd(pDrive, 45.0, 0.5),
        AutoTimedForwardCmd(pDrive, 0.5_s, 1.0),
        AutoTurnCmd(pDrive, 90.0+45.0, 0.5), // top of roof
        AutoTimedForwardCmd(pDrive, 0.5_s, 1.0),
        AutoTurnCmd(pDrive, 45.0+90.0+45.0, 0.5),
        AutoTimedForwardCmd(pDrive, 0.5_s, 1.0), // right wall
        AutoTurnCmd(pDrive, 90.0+45.0+90.0+45.0, 0.5),
        AutoTimedForwardCmd(pDrive, 0.4_s, 1.0), // floor
        AutoTurnCmd(pDrive, 90.0+90.0+45.0+90.0+45.0, 0.5) // starting point
    ).ToPtr();
}

frc2::CommandPtr MovePassedLine(DriveSubBase *pDrive)
{
  return frc2::SequentialCommandGroup
    (
        AutoForwardCmd(pDrive, (double)2.5_m)
    ).ToPtr();
}

frc2::CommandPtr Pos1(DriveSubBase *pDrive, LoaderSubBase *pLoader, ShootSubBase *pShoot, VisionSubBase *pVision)
{
  return frc2::SequentialCommandGroup
    (
        AutoVisionAlignCmd(pDrive, pVision, 10.0, 0.5),
        AutoLoadToPhotogateCmd(pLoader, 1.0), // prepare game-object to shoot
        AutoShootCmd(pShoot, pLoader, 1.0), // turn on shooter & load, then stop both

        AutoTurnCmd(pDrive, 170.0, 1.0), // turn around (to face next game object)
        frc2::ParallelCommandGroup
        (
          AutoLoadToPhotogateCmd(pLoader, 1.0), // prepare game-object to shoot
          AutoForwardCmd(pDrive, (double)3.5_m, 1.0) // drive over note
        ),
        AutoForwardCmd(pDrive, (double)-3.5_m, 1.0),
        AutoTurnCmd(pDrive, -170.0, 1.0), // turn around (to face same target)
        AutoShootCmd(pShoot, pLoader, 1.0), // turn on shooter & load, then stop both
        AutoForwardCmd(pDrive, (double)3.5_m, -1.0) // drive over line

    ).ToPtr();
}

frc2::CommandPtr Pos2(DriveSubBase *pDrive, LoaderSubBase *pLoader, ShootSubBase *pShoot, VisionSubBase *pVision)
{
  return frc2::SequentialCommandGroup
    (
        AutoForwardCmd(pDrive, (double)(units::meter_t)120.0_in)
    ).ToPtr();
}

frc2::CommandPtr Pos3(DriveSubBase *pDrive, LoaderSubBase *pLoader, ShootSubBase *pShoot, VisionSubBase *pVision)
{
  return frc2::SequentialCommandGroup
    (
        AutoForwardCmd(pDrive, (double)(units::meter_t)120.0_in)
    ).ToPtr();
}
