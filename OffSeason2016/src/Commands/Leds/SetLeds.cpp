#include "SetLeds.h"

SetLeds::SetLeds(float red, float green, float blue)
{
	Requires(Robot::ledSubsystem.get());
	redChannel = red;
	greenChannel = green;
	blueChannel = blue;
	isDone = false;
}

void SetLeds::Initialize()
{

}

void SetLeds::Execute()
{
	isDone = false;
	Robot::ledSubsystem->SetRedLED(redChannel);
	Robot::ledSubsystem->SetGreenLED(greenChannel);
	Robot::ledSubsystem->SetBlueLED(blueChannel);
	isDone = true;
}

bool SetLeds::IsFinished()
{
	return isDone;
}

void SetLeds::End()
{

}

void SetLeds::Interrupted()
{

}
