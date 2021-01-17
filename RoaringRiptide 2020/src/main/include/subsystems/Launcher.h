/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <iostream>

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

class Launcher : public frc2::SubsystemBase {
 public:
  Launcher(double kP, double kI, double kD, double setpoint);

  void Stop();
  void Run();
  bool AtSpeed();
  double GetEncoderCount();
  void StartMusic();
  void StopMusic();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  TalonFX launcher{6};
  Orchestra finalCountdown;
  double m_kP;
  double m_kI;
  double m_kD;
  double m_setpoint;

};
