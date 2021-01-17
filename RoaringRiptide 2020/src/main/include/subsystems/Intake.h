/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DoubleSolenoid.h>
#include <ctre/Phoenix.h>
#include <Constants.h>

class Intake : public frc2::SubsystemBase {
 public:
  Intake();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  void LowerArm();
  void RaiseArm();
  void RunIntake();
  void RunIntakeReverse();
  void Stop();

 private:

  frc::DoubleSolenoid arm{IntakeConstants::arm_ports[0], IntakeConstants::arm_ports[1]};
  WPI_VictorSPX intake = {IntakeConstants::intake_victor};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
