#ifndef AlignParallel_H
#define AlignParallel_H

#include "Commands/Command.h"
#include "../../Robot.h"

class AlignParallel: public Command
{
public:
	AlignParallel(float angle, float distanceAway);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	bool isDone;
	int targetX;
	bool inToleranceX;
	const int toleranceX = 3;
	const int centerX = 160; //pixels
	int distanceToCenter = 0;
	float speedX = 0;
	float targetAngle;
	float XAxis = 0;
	float YAxis = 0;
	float RotAxis = 0;
	float speedY = 0;
	float distanceY = 0;
	float calrot = 0;
	float adjyaw = 0;
	const int toleranceY = 3; //inches
	int distanceTarget = 0;
	bool inToleranceY;
};

#endif
