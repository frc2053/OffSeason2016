#ifndef ClimberSolenoid_H
#define ClimberSolenoid_H

#include "Commands/Command.h"
#include "../../Robot.h"

class ClimberSolenoid: public Command
{
public:
	ClimberSolenoid(bool solenoidDirection);
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
