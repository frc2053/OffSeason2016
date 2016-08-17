#ifndef AlignCenter_H
#define AlignCenter_H

#include "Commands/Command.h"
#include "../../Robot.h"

class AlignCenter: public Command
{
public:
	AlignCenter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	float CalculateSpeedValue(int toCenter);
private:
	int distanceToCenter;
	float adjyaw;
	float speedRot;
	const int TOLERANCE = 5;
	const int TARGET = 0;
	bool isDone;
	float XAxis, YAxis, RotAxis;
};

#endif
