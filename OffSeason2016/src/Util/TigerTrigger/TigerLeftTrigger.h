#ifndef SRC_UTIL_TIGERTRIGGER_TIGERLEFTTRIGGER_H_
#define SRC_UTIL_TIGERTRIGGER_TIGERLEFTTRIGGER_H_

#include "WPILib.h"

class TigerLeftTrigger : public Trigger {
public:
	TigerLeftTrigger(Joystick* joy, int axis);
	bool Get();
	float GetTriggerValue();
private:
	float Deadband(float axis);

	int joystickAxis;
	float joystickValue;
	Joystick* joystick;
};

#endif
