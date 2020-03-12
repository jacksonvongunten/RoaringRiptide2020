/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  frc::Shuffleboard::GetTab("Game").Add(m_chooser);
  frc::Shuffleboard::GetTab("Game").AddBoolean("Launcher Ready", [this] {return m_launcher.AtSpeed();});
  frc::Shuffleboard::GetTab("Game").AddNumber("Launcher Velocity", [this] {return m_launcher.GetEncoderCount();});
  frc::Shuffleboard::GetTab("Game").AddNumber("Time", [this] {return timer.GetMatchTime();});
  m_chooser.SetDefaultOption("Advanced Auto Parts", &advanced_auto);
  m_chooser.AddOption("Nothing", &nothing_auto);
  m_chooser.AddOption("Drive Auto", &drive_auto);

  // Configure the button bindings
  ConfigureButtonBindings();

  m_drive.SetDefaultCommand(DefaultDrive{&m_drive, [this] { return -driver_controller.GetY(frc::GenericHID::JoystickHand::kLeftHand); }, [this] { return -0.7*driver_controller.GetX(frc::GenericHID::JoystickHand::kRightHand); } });
  m_climber.SetDefaultCommand(StopClimber(&m_climber));
  m_launcher.SetDefaultCommand(StopLauncher(&m_launcher));
  m_intake.SetDefaultCommand(DefaultIntake(&m_intake));
  m_elevator.SetDefaultCommand(StopElevator(&m_elevator));
  m_lime.SetDefaultCommand(LimelightDefault(&m_lime));

}

void RobotContainer::ConfigureButtonBindings() {

  l_bumper.ToggleWhenPressed(&run_launcher);
  r_bumper.WhileHeld(&run_elevator);
  a_button.ToggleWhenPressed(&run_intake);
  x_button.WhileActiveOnce(&lift_up_arm);
  y_button.WhileActiveOnce(&lift_up_robot);

  r_bumper_o.WhileHeld(RotateToTarget(&m_drive, &m_lime));
  up_button_o.ToggleWhenPressed(&raise_intake);
  down_button_o.ToggleWhenPressed(&lower_intake);
  a_button_o.WhileHeld(&run_elevator_reverse);
  y_button_o.WhileHeld(&run_intake);
  x_button_o.WhileHeld(&run_intake_reverse);

}

frc2::Command* RobotContainer::GetAutonomousCommand() {

  return m_chooser.GetSelected();

}