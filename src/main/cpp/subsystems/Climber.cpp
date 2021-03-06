/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Climber.h"

Climber::Climber() {

    leftServo.Set(0);
    rightServo.Set(0);

}

// This method will be called once per scheduler run
void Climber::Periodic() {}

void Climber::ExtendUp() {

    if (!leftLimitSwitch.Get()) {

        this->StopLeft();
        
    }
    else {

        left.Set(-ClimberConstants::arm_up_speed);

    }

    if (rightLimitSwitch.Get()) {

        this->StopRight();

    }
    else {

        right.Set(ClimberConstants::arm_up_speed);

    }

    leftServo.Set(0);
    rightServo.Set(0);

}

void Climber::StopLeft() {

    left.Set(0);

}

void Climber::StopRight() {

    right.Set(0);

}

void Climber::PullDown() {

    if (!leftBottomLimitSwitch.Get()) {

        this->StopLeft();

    }
    else {

        left.Set(ClimberConstants::arm_down_speed);

    }

    if (!rightBottomLimitSwitch.Get()) {

        this->StopRight();

    }
    else {

        right.Set(-ClimberConstants::arm_down_speed);

    }

    leftServo.Set(ClimberConstants::servo_angle);
    rightServo.Set(ClimberConstants::servo_angle);

}