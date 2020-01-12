/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "rev/CANSparkMax.h"
#include "rev/SparkMax.h"
#include "frc/PIDController.h"
#include "frc/AnalogInput.h"
#include "frc/Spark.h"

class WheelDrive {
 public:
  WheelDrive(int _angleMotor, int _speedMotor, int _encoder);
  void Drive(double speed, double angle);

 private:

  double MAX_VOLTS = 4.95; //todo

  rev::SparkMax speedMotor;
  rev::CANSparkMax angleMotor;
  frc::PIDController pidController;  

  frc::Spark* dummy_output{0};

  // alright it seems like its impossible to get a

  // rev::CANPIDController revPID;
  // rev::CANSensor encoder;

  
};
