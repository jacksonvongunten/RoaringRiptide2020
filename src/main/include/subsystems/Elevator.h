/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/Servo.h>

class Elevator : public frc2::SubsystemBase {
 public:
  Elevator();
  void Run();
  void RunReverse();
  void Stop();
  void LowerElevator();
  void LiftElevator();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  WPI_VictorSPX elevator = {9};
  frc::Servo resetBall{3};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
