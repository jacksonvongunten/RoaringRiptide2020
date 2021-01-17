/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LaunchAtSpeed.h"

LaunchAtSpeed::LaunchAtSpeed(Launcher* launcher, Elevator* elevator) : m_launcher{launcher}, m_elevator{elevator} {
  AddRequirements({launcher, elevator});
}

// Called repeatedly when this Command is scheduled to run
void LaunchAtSpeed::Execute() {

  m_launcher->Run();
  if (m_launcher->AtSpeed()) {

    m_elevator->Run();

  }
  else {

    m_elevator->Stop();

  }

}
