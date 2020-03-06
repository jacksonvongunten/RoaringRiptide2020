/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drive.h"
#include <iostream>

Drive::Drive() {

    left_talon1.ConfigFactoryDefault();
    right_talon1.ConfigFactoryDefault();

    left_talon2.Follow(left_talon1);
    left_victor.Follow(left_talon1);

    right_talon2.Follow(right_talon1);
    right_victor.Follow(right_talon1);

    drive.SetSafetyEnabled(false);
    left_talon1.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative);
    right_talon1.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative);

    left_talon1.SetSelectedSensorPosition(0);
    right_talon1.SetSelectedSensorPosition(0);

    left_talon1.Config_kF(0, 0);
    left_talon1.Config_kP(0, 0.03);
    left_talon1.Config_kI(0, 0);
    left_talon1.Config_kD(0, 0);

    right_talon1.Config_kF(0, 0);
    right_talon1.Config_kP(0, 0.03);
    right_talon1.Config_kI(0, 0);
    right_talon1.Config_kD(0, 0);

    left_talon1.SetSensorPhase(false);
    right_talon1.SetSensorPhase(false);

}

// This method will be called once per scheduler run
void Drive::Periodic() {}

void Drive::SetHighGear() {

    shifter.Set(frc::DoubleSolenoid::kForward);

}

void Drive::SetLowGear() {

    shifter.Set(frc::DoubleSolenoid::kReverse);

}

void Drive::ResetEncoder() {

    left_talon1.SetSelectedSensorPosition(0);
    right_talon1.SetSelectedSensorPosition(0);

}

double Drive::DriveToDistance(double setpoint) {

    left_talon1.Set(ControlMode::Position, -setpoint);
    right_talon1.Set(ControlMode::Position, setpoint);

}

void Drive::ArcadeDrive(double forward, double rotate) {

    drive.ArcadeDrive(forward, rotate);
    this->SetLowGear();

}