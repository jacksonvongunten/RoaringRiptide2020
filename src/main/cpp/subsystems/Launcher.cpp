/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Launcher.h"
#include <string.h>

Launcher::Launcher(double kP, double kI, double kD, double setpoint) : m_kP{kP}, m_kI{kI}, m_kD{kD}, m_setpoint{setpoint} {

    launcher.SetInverted(true);
    launcher.ConfigSupplyCurrentLimit( SupplyCurrentLimitConfiguration(true, 40, 35, 1.0));
    launcher.ConfigClosedloopRamp(5);
    launcher.ConfigSelectedFeedbackSensor(TalonFXFeedbackDevice::IntegratedSensor);

    launcher.Config_kF(0, 0);
    launcher.Config_kP(0, m_kP);
    launcher.Config_kI(0, m_kI);
    launcher.Config_kD(0, m_kD);

    finalCountdown.AddInstrument(launcher);
    std::string path = "building.chrp";
    finalCountdown.LoadMusic(path);

}

// This method will be called once per scheduler run
void Launcher::Periodic() {}

void Launcher::Stop() {

    launcher.Set(ControlMode::PercentOutput, 0);

}

void Launcher::Run() {

    launcher.Set(ControlMode::Velocity, m_setpoint);
    std::cout << launcher.GetSelectedSensorVelocity() << std::endl;

}

bool Launcher::AtSpeed() {

    return (launcher.GetSelectedSensorVelocity() >= m_setpoint-500);

}

void Launcher::StartMusic() {

    finalCountdown.Play();

}

void Launcher::StopMusic() {

    finalCountdown.Stop();

}