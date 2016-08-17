#ifndef GoalAlign_H
#define GoalAlign_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"
#include "../Leds/SetLeds.h"

class GoalAlign: public Command
{
public:
	GoalAlign(float angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool isDone;
	int targetX;
	bool inToleranceX;
	const int toleranceX = 2;
	const int centerX = 160; //pixels
	float calrot = 0;
	float adjyaw = 0;
	int distanceToCenter = 0;
	float speedX = 0;
	float XAxis;
	float YAxis;
	float RotAxis;
	float targetAngle;
};

#endif
