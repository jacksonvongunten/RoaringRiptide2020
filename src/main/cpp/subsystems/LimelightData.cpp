/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/LimelightData.h"

LimelightData::LimelightData() {}

// This method will be called once per scheduler run
void LimelightData::Periodic() {}

void LimelightData::StandardCam() {

    table->PutNumber("ledMode", 1);
    table->PutNumber("camMode", 1);

}

void LimelightData::Track() {

    table->PutNumber("ledMode", 3);
    table->PutNumber("camMode", 0);
    
}

double LimelightData::GetHorizontalOffset() {

    return table->GetNumber("tx", 0);

}