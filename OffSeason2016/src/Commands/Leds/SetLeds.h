#ifndef SetLeds_H
#define SetLeds_H

#include "Commands/Command.h"
#include "../../Robot.h"

class SetLeds: public Command
{
public:
	SetLeds(float red, float green, float blue);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float redChannel;
	float greenChannel;
	float blueChannel;
	bool isDone;
};

#endif
