/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>

#include <subsystems/Drive.h>
#include <subsystems/LimelightData.h>

class RotateToTarget
    : public frc2::CommandHelper<frc2::PIDCommand, RotateToTarget> {
 public:
  RotateToTarget(Drive* drive, LimelightData* lime);

  bool IsFinished() override;

};
