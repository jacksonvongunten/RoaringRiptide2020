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
#include <Constants.h>

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
  
  WPI_VictorSPX left = {ClimberConstants::left};
  WPI_VictorSPX right = {ClimberConstants::right};

  frc::DigitalInput leftLimitSwitch{ClimberConstants::top_left_limit_switch};
  frc::DigitalInput rightLimitSwitch{ClimberConstants::top_right_limit_switch};

  frc::DigitalInput leftBottomLimitSwitch{ClimberConstants::bottom_left_limit_switch};
  frc::DigitalInput rightBottomLimitSwitch{ClimberConstants::bottom_right_limit_switch};

  frc::Servo leftServo{ClimberConstants::left_servo};
  frc::Servo rightServo{ClimberConstants::right_servo};

};
