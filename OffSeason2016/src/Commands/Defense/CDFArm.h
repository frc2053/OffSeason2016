#ifndef CDFArm_H
#define CDFArm_H

#include "Commands/Command.h"
#include "../../Robot.h"

class CDFArm: public Command
{
public:
	CDFArm(float speed = 0, float time = 0);
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
