#include "Logger.h"
#include "OI.h"
#include "Robot.h"
#include "Commands/SaveWheelPositions.h"
#include "Commands/ShowPrefs.h"
#include "Commands/UpdateSmartDashboard.h"

const uint32_t JOYSTICK_PORT_DRIVER = 0;
const uint32_t JOYSTICK_PORT_PICKER = 1;

const float JOYSTICK_DEAD_ZONE = 0.1;

const uint32_t JOYSTICK_LX_AXIS    = 0;
const uint32_t JOYSTICK_LY_AXIS    = 1;
const uint32_t JOYSTICK_LTRIG_AXIS = 2;
const uint32_t JOYSTICK_RTRIG_AXIS = 3;
const uint32_t JOYSTICK_RX_AXIS    = 4;
const uint32_t JOYSTICK_RY_AXIS    = 5;

const uint32_t JOYSTICK_BUTTON_A     = 1;
const uint32_t JOYSTICK_BUTTON_B     = 2;
const uint32_t JOYSTICK_BUTTON_X     = 3;
const uint32_t JOYSTICK_BUTTON_Y     = 4;
const uint32_t JOYSTICK_BUTTON_LB    = 5;
const uint32_t JOYSTICK_BUTTON_RB    = 6;
const uint32_t JOYSTICK_BUTTON_BACK  = 7;
const uint32_t JOYSTICK_BUTTON_START = 8;
const uint32_t JOYSTICK_BUTTON_LEFT  = 9;
const uint32_t JOYSTICK_BUTTON_RIGHT = 10;

OI::OI() {
	LOG("OI::OI");

	// Define joysticks
	driverJoystick = new Joystick(JOYSTICK_PORT_DRIVER);
	pickerJoystick = new Joystick(JOYSTICK_PORT_PICKER);

	// Define joystick button mappings

	// Add SmartDashboard controls
	SmartDashboard::PutData("SaveWheelPositions", new SaveWheelPositions());
	SmartDashboard::PutData("UpdateSmartDashboard", new UpdateSmartDashboard());
}

bool OI::GetButtonA(){
	auto value = GetDriverJoystick()->GetRawButton(JOYSTICK_BUTTON_A);
	return (value);
}

bool OI::GetButtonB(){
	auto value = GetDriverJoystick()->GetRawButton(JOYSTICK_BUTTON_B);
	return (value);
}

bool OI::GetButtonX(){
	auto value = GetDriverJoystick()->GetRawButton(JOYSTICK_BUTTON_X);
	return (value);
}

bool OI::GetButtonY(){
	auto value = GetDriverJoystick()->GetRawButton(JOYSTICK_BUTTON_Y);
	return (value);
}

float OI::GetJoystickX() {
	auto value = GetDriverJoystick()->GetRawAxis(JOYSTICK_LX_AXIS);
	return (fabs(value) < JOYSTICK_DEAD_ZONE) ? 0 : value;
}

float OI::GetJoystickY() {
	auto value = GetDriverJoystick()->GetRawAxis(JOYSTICK_LY_AXIS);
	return (fabs(value) < JOYSTICK_DEAD_ZONE) ? 0 : value;
}

float OI::GetJoystickZ() {
	auto value = GetDriverJoystick()->GetRawAxis(JOYSTICK_RX_AXIS);
	return (fabs(value) < JOYSTICK_DEAD_ZONE) ? 0 : value;
}

float OI::GetDriverRightTrigger(){
	auto value = GetDriverJoystick()->GetRawAxis(JOYSTICK_RTRIG_AXIS);
	return (fabs(value) < JOYSTICK_DEAD_ZONE) ? 0 : value;
}

float OI::GetDriverLeftTrigger(){
	auto value = GetDriverJoystick()->GetRawAxis(JOYSTICK_LTRIG_AXIS);
	return (fabs(value) < JOYSTICK_DEAD_ZONE) ? 0 : value;
}
