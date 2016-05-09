#ifndef ClimberMotor_H
#define ClimberMotor_H

#include "Commands/Command.h"
#include "../../Robot.h"

class ClimberMotor: public Command
{
public:
	ClimberMotor(float speed = 0, float time = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<Timer> timer;
	float timeCurrent;
	float timeTarget;
	float inputSpeed;
	bool isDone;
};

#endif
