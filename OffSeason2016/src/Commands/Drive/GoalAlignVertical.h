#ifndef GoalAlignVertical_H
#define GoalAlignVertical_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class GoalAlignVertical: public Command
{
public:
	GoalAlignVertical(float distanceAway);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float XAxis = 0;
	float YAxis = 0;
	float RotAxis = 0;
	bool isDone;
	float speedY = 0;
	float distanceY = 0;
	float calrot = 0;
	float adjyaw = 0;
	const int toleranceY = 3; //inches
	int distanceTarget = 0;
	bool inToleranceY;
};

#endif
