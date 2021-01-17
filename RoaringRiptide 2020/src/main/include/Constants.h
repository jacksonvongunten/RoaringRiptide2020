/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace ClimberConstants {

    const int left = 6;
    const int right = 7;

    const int top_left_limit_switch = 9;
    const int top_right_limit_switch = 8;
    const int bottom_left_limit_switch = 7;
    const int bottom_right_limit_switch = 6;

    const int left_servo = 0;
    const int right_servo = 1; 

    const double arm_up_speed = 0.5;
    const double arm_down_speed = 0.5;
    const double servo_angle = 0.25;

}

namespace DriveConstants {

    const int left_talon1 = 0;
    const int left_talon2 = 1;
    const int left_victor = 2;

    const int right_talon1 = 3;
    const int right_talon2 = 4;
    const int right_victor = 5;

    const int shifter[2] = {0, 1};

}

namespace ElevatorConstants {

    const int elevator_victor = 9;
    const int elevator_servo = 3;

    const double elevator_forward_speed = 0.6;
    const double elevator_reverse_speed = 0.5;

}

namespace IntakeConstants {

    const int arm_ports[2] = {2, 3};
    const int intake_victor = 8;

    const double forward_intake_speed = 0.8;
    const double reverse_intake_speed = 0.8;

}

namespace LauncherConstants {

    const int launcher_port = 6;
    const double kP = 0.3;
    const double kI = 2e-5;
    const double kD = 0;
    const double setpoint = 12000;

}

namespace LimelightConstants {



}