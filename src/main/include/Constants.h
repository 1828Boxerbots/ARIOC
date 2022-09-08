// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "RobotContainers/RobotContainerBase.h"

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

#define USE_C418 = 1;
//#define USE_KURGEN = 2;


/*int m_robot = 1;

switch (m_robot)
{
    case 1:
    m_pContainer = new C418Container();

    case 2:
    m_pContainer = new KurganContainer();
}
*/
//C418:
constexpr int PWM_RIGHTDRIVE_C418 = 0;
constexpr int PWM_LEFTDRIVE_C418 = 1;
constexpr int PWM_SHOOTER_C418 = 3;
constexpr int PWM_LOWERINNER_C418 = 4;
constexpr int PWM_INTAKE_C418 = 5;
constexpr int PWM_UPPERINNER_C418 = 6;

//Rocky:
constexpr int PWM_RIGHTDRIVE_ROCKY = 3;
constexpr int PWM_LEFTDRIVE_ROCKY = 2;
constexpr int PWM_LOADER_ROCKY = 9;
constexpr int PWM_SHOOTER_ROCKY = 5;
constexpr int PWM_TURRET_ROCKY = 4;

//Leland:
constexpr int PWM_RIGHTDRIVE_LELAND = 0;
constexpr int PWM_LEFTDRIVE_LELAND = 1;
constexpr int PWM_ARM_LELAND = 2;
constexpr int PWM_INTAKE_LELAND = 3;
constexpr int PWM_LOWERINNER_LELAND = 4;
constexpr int PWM_UPPERINNER_LELAND = 5;
constexpr int PWM_SHOOTER_LELAND = 6;
constexpr int PWM_CLIMB_LELAND = 7;
constexpr int PWM_CLIMBSERVO_LELAND = 8;


// Kurgan
constexpr int PWM_LEFTDRIVE_ONE_KURGAN  = 2;
constexpr int PWM_LEFTDRIVE_TWO_KURGAN  = 1;
constexpr int PWM_RIGHTDRIVE_ONE_KURGAN = 3;
constexpr int PWM_RIGHTDRIVE_TWO_KURGAN = 4;
constexpr int PWM_LEFTSHOOT_ONE_KURGAN  = 6;
constexpr int PWM_LEFTSHOOT_TWO_KURGAN  = 7;
constexpr int PWM_RIGHTSHOOT_ONE_KURGAN = 5;
constexpr int PWM_RIGHTSHOOT_TWO_KURGAN = 8;
constexpr int PWM_LOADER_KURGAN         = 0;
constexpr int DIO_PHOTOGATE_KURGAN      = 0;