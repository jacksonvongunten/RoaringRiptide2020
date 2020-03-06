/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/StopElevator.h"

StopElevator::StopElevator(Elevator* elevator) : m_elevator{elevator} {
  AddRequirements({elevator});
}

// Called repeatedly when this Command is scheduled to run
void StopElevator::Execute() {

  m_elevator->Stop();

}