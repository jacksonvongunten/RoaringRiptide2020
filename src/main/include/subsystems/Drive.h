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
#include <Constants.h>

class Drive : public frc2::SubsystemBase {
 public:
  Drive();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  void CurvatureDrive(double forward, double rotate);
  void ArcadeDrive(double forward, double rotate);

  void SetHighGear();
  void SetLowGear();

  void ResetEncoder();

  void DriveToDistance(double setpoint);

 private:

  WPI_TalonSRX left_talon1 = {DriveConstants::left_talon1};
  WPI_TalonSRX left_talon2 = {DriveConstants::left_talon2};
  WPI_VictorSPX left_victor = {DriveConstants::left_victor};

  WPI_TalonSRX right_talon1 = {DriveConstants::right_talon1};
  WPI_TalonSRX right_talon2 = {DriveConstants::right_talon2};
  WPI_VictorSPX right_victor = {DriveConstants::right_victor};

  frc::SpeedControllerGroup left{left_talon1, left_talon2, left_victor};
  frc::SpeedControllerGroup right{right_talon1, right_talon2, right_victor};

  frc::DifferentialDrive drive{left, right};

  frc::DoubleSolenoid shifter{DriveConstants::shifter[0], DriveConstants::shifter[1]};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
