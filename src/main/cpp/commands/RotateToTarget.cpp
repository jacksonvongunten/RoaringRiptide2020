/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RotateToTarget.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
RotateToTarget::RotateToTarget(Drive* drive, LimelightData* lime)
    : CommandHelper(frc2::PIDController(0.06, 0, 0),
                    // This should return the measurement
                    [lime] { return lime->GetHorizontalOffset(); },
                    // This should return the setpoint (can also be a constant)
                    [] { return 0; },
                    // This uses the output
                    [drive](double output) {
                      drive->ArcadeDrive(0, output);
                    }) {

                      AddRequirements({drive, lime});

                    }

// Returns true when the command should end.
bool RotateToTarget::IsFinished() { return m_controller.AtSetpoint(); }
