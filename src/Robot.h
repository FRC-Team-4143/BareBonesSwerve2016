#ifndef _ROBOT_H
#define _ROBOT_H

#include <WPILib.h>
#include <Commands/Command.h>
#include <LiveWindow/LiveWindow.h>
#include <iostream>
#include "Modules/DoubleAutoMonitor.h"
#include "Subsystems/DriveTrain.h"
#include "OI.h"

class Robot : public IterativeRobot {
public:
	Command *autonomousCommand;
	LiveWindow *lw;
	//SendableChooser* autoChooser;
	static OI *oi;
	static DriveTrain* driveTrain;

	virtual void RobotInit();

	virtual void DisabledInit();
	virtual void DisabledPeriodic();

	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();

	virtual void TeleopInit();
	virtual void TeleopPeriodic();

	virtual void TestInit();
	virtual void TestPeriodic();

protected:
	void PreferencesInit();

	DoubleAutoMonitor _monitor;
};

#endif
