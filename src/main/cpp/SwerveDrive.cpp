/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "SwerveDrive.h"

#define PI 3.1415926535

SwerveDrive::SwerveDrive(WheelDrive _backRight, WheelDrive _backLeft, WheelDrive _frontRight, WheelDrive _frontLeft) {
    backRight = _backRight;
    backLeft = _backLeft;
    frontRight = _frontRight;
    frontLeft = _frontLeft;
}

void SwerveDrive::Drive(double x, double y, double rot) {
    double r = sqrt((LENGTH * WIDTH) + (WIDTH * WIDTH));

    y *= -1;

    double b = x + rot * (LENGTH / r);
    double a = x - rot * (LENGTH / r);
    double c = y - rot * (WIDTH / r);
    double d = y + rot * (WIDTH / r);

    double backRightSpeed = sqrt((a * a) + (d * d));
    double backLeftSpeed = sqrt((a * a) + (c * c));
    double frontRightSpeed = sqrt((b * b) + (d * d));
    double frontLeftSpeed = sqrt((b * b) + (c * c));

    double backRightAngle = atan2(a, d) / PI;
    double backLeftAngle = atan2(a, c) / PI;
    double frontRightAngle = atan2(b, d) / PI;
    double frontLeftAngle = atan2(b, c) / PI;


    backRight.Drive(backRightSpeed, backRightAngle);
    backLeft.Drive(backLeftSpeed, backLeftAngle);
    frontRight.Drive(frontRightSpeed, frontRightAngle);
    frontLeft.Drive(frontLeftSpeed, frontLeftAngle);
} 
