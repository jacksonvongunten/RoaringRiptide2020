/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/StopClimber.h"

StopClimber::StopClimber(Climber* climber) : m_climber{climber} {
  AddRequirements({climber});
}

// Called repeatedly when this Command is scheduled to run
void StopClimber::Execute() {

  m_climber->StopLeft();
  m_climber->StopRight();

}