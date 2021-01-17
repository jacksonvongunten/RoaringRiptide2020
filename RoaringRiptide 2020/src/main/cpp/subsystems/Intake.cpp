/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Intake.h"

Intake::Intake() {}

// This method will be called once per scheduler run
void Intake::Periodic() {}

void Intake::LowerArm() {

    arm.Set(frc::DoubleSolenoid::kReverse);

}

void Intake::RaiseArm() {

    arm.Set(frc::DoubleSolenoid::kForward);

}

void Intake::RunIntake() {

    intake.Set(IntakeConstants::forward_intake_speed);

}

void Intake::RunIntakeReverse() {

    intake.Set(-IntakeConstants::reverse_intake_speed);

}

void Intake::Stop() {

    intake.Set(0); 

}