/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "WheelDrive.h"

WheelDrive::WheelDrive(int _angleMotor, int _speedMotor, int _encoder) :
    speedMotor{_speedMotor},
    angleMotor{_angleMotor, rev::CANSparkMax::MotorType::kBrushless},
    // revPID{angleMotor},
    pidController{1, 0, 0, new frc::AnalogInput(_encoder), dummy_output} 
    {

        // revPID.SetP(1);
        // revPID.SetI(0);
        // revPID.SetD(0);
        // revPID.SetOutputRange(-1,1);


    pidController.SetOutputRange(-1, 1);
    pidController.SetContinuous();
    pidController.Enable();

    angleMotor.Set(pidController.Get());

}

void WheelDrive::Drive(double speed, double angle) {
    speedMotor.Set(speed);

    double setpoint = angle * (MAX_VOLTS * 0.5) + (MAX_VOLTS * 0.5);

    if (setpoint < 0) {
        setpoint = MAX_VOLTS + setpoint;
    }
    if (setpoint > MAX_VOLTS) {
        setpoint = setpoint - MAX_VOLTS;
    }

    pidController.SetSetpoint(setpoint);


    angleMotor.Set(pidController.Get());

}
