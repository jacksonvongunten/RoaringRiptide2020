/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Elevator.h"

Elevator::Elevator() {

    elevator.SetInverted(true);

}

// This method will be called once per scheduler run
void Elevator::Periodic() {}

void Elevator::Run() {

    elevator.Set(ControlMode::PercentOutput, 0.5);

}

void Elevator::RunReverse() {

    elevator.Set(ControlMode::PercentOutput, -0.5);

}

void Elevator::Stop() {

    elevator.Set(ControlMode::PercentOutput, 0.0);
    resetBall.Set(15/36.);

}

void Elevator::LiftElevator() {

    resetBall.Set(0);

}