/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <cmath>

#include "WheelDrive.h"

class SwerveDrive {
 public:

  double LENGTH = 30; //[[todo]]
  double WIDTH  = 20;

  WheelDrive backRight;
  WheelDrive backLeft;
  WheelDrive frontRight;
  WheelDrive frontLeft;

  SwerveDrive(WheelDrive _backRight, WheelDrive _backLeft, WheelDrive _frontRight, WheelDrive _frontLeft);

  void Drive(double x, double y, double rot);
};
