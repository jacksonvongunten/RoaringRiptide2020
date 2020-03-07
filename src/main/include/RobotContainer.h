/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/ConditionalCommand.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/WaitCommand.h>
#include <frc2/command/WaitUntilCommand.h>

#include <subsystems/Drive.h>
#include <subsystems/Climber.h>
#include <subsystems/Launcher.h>
#include <subsystems/Intake.h>
#include <subsystems/Elevator.h>
#include <subsystems/LimelightData.h>

#include <commands/DefaultDrive.h>
#include <commands/StopClimber.h>
#include <commands/StopLauncher.h>
#include <commands/DefaultIntake.h>
#include <commands/StopElevator.h>
#include <commands/RotateToTarget.h>
#include <commands/LaunchAtSpeed.h>
#include <commands/LimelightDefault.h>
#include <commands/PlayMusic.h>

#include <frc/XboxController.h>

#include <frc/smartdashboard/SendableChooser.h>
#include <frc/shuffleboard/Shuffleboard.h>

#include <frc2/command/button/Button.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/ParallelCommandGroup.h>

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();
  frc2::Command* GetAutonomousCommand();
  
  frc::SendableChooser<frc2::Command*> m_chooser;

 private:

  Drive m_drive;
  Climber m_climber;
  Launcher m_launcher{0.7, 2e-5, 0, 12000};
  Intake m_intake;
  Elevator m_elevator;
  LimelightData m_lime;

  frc2::RunCommand lift_up_arm{[this] {m_climber.ExtendUp();}, {&m_climber}};
  frc2::RunCommand lift_up_robot{[this] {m_climber.PullDown();}, {&m_climber}};
  frc2::InstantCommand stop_climber{[this] {m_climber.StopLeft(); m_climber.StopRight(); }, {&m_climber}};
  frc2::RunCommand run_intake{[this] {m_intake.LowerArm(); m_intake.RunIntake(); }, {&m_intake}};
  frc2::RunCommand run_intake_reverse{[this] {m_intake.RunIntakeReverse(); }, {&m_intake}};
  frc2::RunCommand raise_intake{[this] {m_intake.RaiseArm(); }, {&m_intake}};
  frc2::RunCommand lower_intake{[this] {m_intake.LowerArm();}, {&m_intake}};
  frc2::RunCommand run_launcher{[this] {m_launcher.Run();}, {&m_launcher}};
  frc2::RunCommand run_elevator{[this] {m_elevator.Run();}, {&m_elevator}};
  frc2::RunCommand stop_elevator{[this] {m_elevator.Stop();}, {&m_elevator}};
  frc2::RunCommand lift_elevator{[this] {m_elevator.LiftElevator(); }, {&m_elevator}};
  frc2::RunCommand run_elevator_reverse{[this] {m_elevator.RunReverse();}, {&m_elevator}};
  frc2::RunCommand start_music{[this] {m_launcher.StartMusic();}, {&m_launcher}};
  frc2::RunCommand stop_music{[this] {m_launcher.StopMusic();}, {&m_launcher}};

  frc2::SequentialCommandGroup auto_go{

    frc2::InstantCommand{ [this] { m_drive.ResetEncoder(); }, {&m_drive}},
    frc2::RunCommand{ [this] { m_drive.DriveToDistance(30000); }, {&m_drive} }.WithTimeout(2_s),
    frc2::InstantCommand{ [this] {m_lime.Track();}, {&m_lime}},
    frc2::WaitCommand(1_s),
    frc2::ParallelCommandGroup{
    
    RotateToTarget(&m_drive, &m_lime),
    LaunchAtSpeed(&m_launcher, &m_elevator),
    frc2::InstantCommand{[this] { m_intake.LowerArm(); }, {&m_intake}}

    }

  };

  // The robot's subsystems and commands are defined here...
  frc::XboxController driver_controller{0};
  frc2::Button r_bumper{[&] { return driver_controller.GetBumper(frc::GenericHID::JoystickHand::kRightHand); }};
  frc2::Button l_bumper{[&] { return driver_controller.GetBumper(frc::GenericHID::JoystickHand::kLeftHand); }};
  frc2::Button a_button{[&] { return driver_controller.GetAButton(); }};
  frc2::Button x_button{[&] { return driver_controller.GetXButton(); }};
  frc2::Button y_button{[&] { return driver_controller.GetYButton(); }};
  frc2::Button b_button{[&] { return driver_controller.GetBButton(); }};

  frc::XboxController operator_controller{1};
  frc2::Button r_bumper_o{[&] { return operator_controller.GetBumper(frc::GenericHID::JoystickHand::kRightHand); }};
  frc2::Button l_bumper_o{[&] { return operator_controller.GetBumper(frc::GenericHID::JoystickHand::kLeftHand); }};
  frc2::Button up_button_o{[&] { return operator_controller.GetPOV() == 0; }};
  frc2::Button down_button_o{[&] { return operator_controller.GetPOV() == 180; }};
  frc2::Button right_button_o{[&] { return operator_controller.GetPOV() == 270; }};
  frc2::Button left_button_o{[&] { return operator_controller.GetPOV() == 90; }};
  frc2::Button r_trigger_o{[&] { return operator_controller.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand) != 0; }};
  frc2::Button l_trigger_o{[&] { return operator_controller.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand) != 0; }};
  frc2::Button a_button_o{[&] { return operator_controller.GetAButton(); }};
  frc2::Button y_button_o{[&] { return operator_controller.GetYButton(); }};
  frc2::Button x_button_o{[&] { return operator_controller.GetXButton(); }};

  void ConfigureButtonBindings();
};