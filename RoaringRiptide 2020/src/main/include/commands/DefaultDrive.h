/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <subsystems/Drive.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class DefaultDrive
    : public frc2::CommandHelper<frc2::CommandBase, DefaultDrive> {
 public:
  DefaultDrive(Drive* subsystem, std::function<double()> forward, std::function<double()> rotate);

  void Execute();

 private:
  Drive* m_subsystem;
  std::function<double()> m_forward;
  std::function<double()> m_rotate;
};
