/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DefaultDrive.h"

DefaultDrive::DefaultDrive(Drive* subsystem, std::function<double()> forward, std::function<double()> rotate) : m_subsystem{subsystem}, m_forward{forward}, m_rotate{rotate} {
  AddRequirements({subsystem});
}

void DefaultDrive::Execute() {

  m_subsystem->CurvatureDrive(m_forward(), m_rotate());

}