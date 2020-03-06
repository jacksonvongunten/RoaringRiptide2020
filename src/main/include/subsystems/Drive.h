/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/DoubleSolenoid.h>

class Drive : public frc2::SubsystemBase {
 public:
  Drive();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  void ArcadeDrive(double forward, double rotate);

  void SetHighGear();
  void SetLowGear();

  void ResetEncoder();

  double DriveToDistance(double setpoint);

 private:

  WPI_TalonSRX left_talon1 = {0};
  WPI_TalonSRX left_talon2 = {1};
  WPI_VictorSPX left_victor = {2};

  WPI_TalonSRX right_talon1 = {3};
  WPI_TalonSRX right_talon2 = {4};
  WPI_VictorSPX right_victor = {5};

  frc::SpeedControllerGroup left{left_talon1, left_talon2, left_victor};
  frc::SpeedControllerGroup right{right_talon1, right_talon2, right_victor};

  frc::DifferentialDrive drive{left, right};

  frc::DoubleSolenoid shifter{0, 1};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
