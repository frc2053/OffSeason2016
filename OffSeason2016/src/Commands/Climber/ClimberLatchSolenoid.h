#ifndef ClimberLatchSolenoid_H
#define ClimberLatchSolenoid_H

#include "Commands/Command.h"
#include "../../Robot.h"

class ClimberLatchSolenoid: public Command
{
public:
	ClimberLatchSolenoid(bool solenoidDirection);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool direction;
	bool isDone;
	std::shared_ptr<Timer> timer;
	float timeCurrent;
	float timeTarget;
	const float PNUEMATIC_DELAY = 2.5;
};

#endif
