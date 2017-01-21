#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include <WPILib.h>
#include "Modules/AnalogChannelVolt.h"

// The RobotMap is a mapping from the ports sensors and actuators are wired into
// to a variable name. This provides flexibility changing wiring, makes checking
// the wiring easier and significantly reduces the number of magic numbers
// floating around.

class RobotMap {
public:
    static PowerDistributionPanel* pdp;

	static PIDController*     driveTrainFrontLeft;
	static SpeedController*   driveTrainFrontLeftDrive;
	static AnalogChannelVolt* driveTrainFrontLeftPos;
	static SpeedController*   driveTrainFrontLeftSteer;

    static PIDController*     driveTrainFrontRight;
	static SpeedController*   driveTrainFrontRightDrive;
	static AnalogChannelVolt* driveTrainFrontRightPos;
	static SpeedController*   driveTrainFrontRightSteer;

	static PIDController*     driveTrainRearLeft;
	static SpeedController*   driveTrainRearLeftDrive;
	static AnalogChannelVolt* driveTrainRearLeftPos;
	static SpeedController*   driveTrainRearLeftSteer;

	static PIDController*     driveTrainRearRight;
	static SpeedController*   driveTrainRearRightDrive;
	static AnalogChannelVolt* driveTrainRearRightPos;
	static SpeedController*   driveTrainRearRightSteer;

    static void Init();
};

#endif
