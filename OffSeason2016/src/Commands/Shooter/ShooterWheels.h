#ifndef ShooterWheels_H
#define ShooterWheels_H

#include "Commands/Command.h"
#include "../../Robot.h"

class ShooterWheels: public Command
{
public:
	ShooterWheels(float speed = 0, float time = 0, float servoangleleft = 70, float servoangleright = 110);
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
	float velocityLeftWheel;
	float velocityRightWheel;
	float servoAngleLeft;
	float servoAngleRight;
};

#endif
