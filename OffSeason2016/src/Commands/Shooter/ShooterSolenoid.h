#ifndef ShooterSolenoid_H
#define ShooterSolenoid_H

#include "Commands/Command.h"
#include "../../Robot.h"

class ShooterSolenoid: public Command
{
public:
	ShooterSolenoid();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool isDone;
	std::shared_ptr<Timer> timer;
	float timeCurrent;
	float timeTarget;
	const float PNUEMATIC_DELAY = 1;
};

#endif
