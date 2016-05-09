#ifndef DefenseSubsystem_H
#define DefenseSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DefenseSubsystem: public Subsystem
{
private:
	std::shared_ptr<CANTalon> defenseTalon;
public:
	DefenseSubsystem();
	void InitDefaultCommand();
	void RunMotor(float speed);
};

#endif
