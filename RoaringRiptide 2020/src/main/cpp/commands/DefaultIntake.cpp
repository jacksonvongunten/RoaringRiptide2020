/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DefaultIntake.h"

DefaultIntake::DefaultIntake(Intake* intake) : m_intake{intake} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({intake});
}

// Called repeatedly when this Command is scheduled to run
void DefaultIntake::Execute() {

  m_intake->Stop();

}
