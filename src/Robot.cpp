#include "Logger.h"
#include "Robot.h"
#include "RobotMap.h"
#include "Modules/DriveTrainSettings.h"

#define USE_DOUBLEAUTOMONITOR 1

OI* Robot::oi = nullptr;
DriveTrain* Robot::driveTrain = nullptr;

void Robot::RobotInit() {
	LOG("Robot::RobotInit");

#if USE_DOUBLEAUTOMONITOR
	_monitor.OnRobotInit();
#endif

	PreferencesInit();

	RobotMap::Init();

	//autoChooser = new SendableChooser();

	//SmartDashboard::PutData("AutonomousChooser", static_cast<Sendable*>(autoChooser));

	// List all preferences
	auto prefs = Preferences::GetInstance();
	std::vector<std::string> keys = prefs->GetKeys();
	std::cout << "[DEBUG] Keys:" << std::endl;
	for (auto iter = keys.begin(); iter != keys.end(); iter++) {
		auto value = prefs->GetString((*iter).c_str());
		std::cout << "[DEBUG] " << *iter << ": " << value;
		std::cout << std::endl;
	}

	// -----------------------
	// Initialize subsystems.
	// -----------------------
	driveTrain = new DriveTrain();

	// ------------------------------------------------------------
	// Initialize OI *AFTER* all subsystems have been initialized.
	// ------------------------------------------------------------
	oi = new OI();
	lw = LiveWindow::GetInstance();
	lw->AddSensor("pdp", "pdp", RobotMap::pdp);

	// -------------------------------------------------
	// Initialize the command used for autonomous mode.
	// -------------------------------------------------
	//autonomousCommand = new AutonomousCommand();

	driveTrain->SetWheelbase(24, 35, 24);
/*
	auto prefs = Preferences::GetInstance();
	auto FLOffset = prefs->GetDouble("FLOff");
	auto FROffset = prefs->GetDouble("FROff");
	auto RLOffset = prefs->GetDouble("RLOff");
	auto RROffset = prefs->GetDouble("RROff");
	std::cout << "Offsets(FL " << FLOffset << ", FR " << FROffset << ", RL " << RLOffset << ", RR " << RROffset << std::endl;
	driveTrain->SetOffsets(FLOffset, FROffset, RLOffset, RROffset);
*/
	DriveTrainSettings::LoadSettings();

	driveTrain->frontLeftPos->Start();
	driveTrain->frontRightPos->Start();
	driveTrain->rearLeftPos->Start();
	driveTrain->rearRightPos->Start();

	driveTrain->frontLeft->Enable();
	driveTrain->frontRight->Enable();
	driveTrain->rearLeft->Enable();
	driveTrain->rearRight->Enable();
}

// ---------------------------------------------------------
// This function is called when the Disabled button is hit.
// You can use it to reset subsystems before shutting down.
// ---------------------------------------------------------
void Robot::DisabledInit(){
	LOG("Robot::DisabledInit");
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	LOG("Robot::AutonomousInit");

#if USE_DOUBLEAUTOMONITOR
	if (_monitor.IsDoubleAutonomous()) {
		std::cout << "Suppressing double autonomous." << std::endl;
		return;
	}
	_monitor.OnAutonomousInit();
#endif

	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	LOG("Robot::TeleopInit");

#if USE_DOUBLEAUTOMONITOR
	_monitor.OnTeleopInit();
#endif

	// This makes sure the autonomous command stops running when
	// teleop starts running. To let autonomous continue until
	// interrupted by another command, remove the following
	// lines.
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestInit() {
	LOG("Robot::TestInit");
}

void Robot::TestPeriodic() {
	lw->Run();
}

void Robot::PreferencesInit() {
	LOG("Robot::PreferencesInit");
	Preferences::GetInstance();
}

START_ROBOT_CLASS (Robot);
