#ifndef OI_H
#define OI_H

#include <WPILib.h>

class OI {
public:
	OI();

	bool GetButtonA();
	bool GetButtonB();
	bool GetButtonX();
	bool GetButtonY();

	float GetJoystickX();
	float GetJoystickY();
	float GetJoystickZ();

	float GetDriverLeftTrigger();
	float GetDriverRightTrigger();

private:
	// Declare joysticks
	Joystick* driverJoystick;
	Joystick* pickerJoystick;

	Preferences* prefs;

	// Declare commands

	// Declare joystick buttons
	// TODO

	Joystick* GetDriverJoystick() { return driverJoystick; }
	Joystick* GetPickerJoystick() { return pickerJoystick; }
};

#endif
