#ifndef IntakeSubsystem_H
#define IntakeSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class IntakeSubsystem: public Subsystem
{
private:
	std::shared_ptr<CANTalon> intakeTalon;
public:
	IntakeSubsystem();
	void InitDefaultCommand();
	void RunMotor(float speed);
};

#endif
