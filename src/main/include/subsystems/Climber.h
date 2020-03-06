/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>
#include <frc/Servo.h>

class Climber : public frc2::SubsystemBase {
 public:
  Climber();

  void ExtendUp();
  void PullDown();
  void StopLeft();
  void StopRight();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  
  WPI_VictorSPX left = {6};
  WPI_VictorSPX right = {7};

  frc::DigitalInput leftLimitSwitch{9};
  frc::DigitalInput rightLimitSwitch{8};

  frc::DigitalInput leftBottomLimitSwitch{7};
  frc::DigitalInput rightBottomLimitSwitch{6};

  frc::Servo leftServo{0};
  frc::Servo rightServo{1};

};
