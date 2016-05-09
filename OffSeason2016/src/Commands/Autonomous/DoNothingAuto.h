#ifndef DoNothingAuto_H
#define DoNothingAuto_H

#include "Commands/Command.h"
#include "../../Robot.h"

class DoNothingAuto: public Command
{
public:
	DoNothingAuto(float timeToWait);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<Timer> timer;
	double timeTarget;
	float timeCurrent;
	bool isDone;
};

#endif
