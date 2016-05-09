#ifndef LedSubsystem_H
#define LedSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LedSubsystem: public Subsystem
{
private:
	std::shared_ptr<DigitalOutput> redLed;
	std::shared_ptr<DigitalOutput> greenLed;
	std::shared_ptr<DigitalOutput> blueLed;
public:
	LedSubsystem();
	void InitDefaultCommand();
	void SetRedLED(float red);
	void SetGreenLED(float green);
	void SetBlueLED(float blue);
};

#endif
