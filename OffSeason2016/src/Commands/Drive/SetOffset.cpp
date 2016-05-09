#include "SetOffset.h"

SetOffset::SetOffset(float offset)
{
	Requires(Robot::drivebaseSubsystem.get());
	isDone = false;
	offsetInput = offset;
}

void SetOffset::Initialize()
{
	isDone = false;
}

void SetOffset::Execute()
{
	isDone = false;
	Robot::drivebaseSubsystem->SetAdjYaw(offsetInput);
	isDone = true;
}

bool SetOffset::IsFinished()
{
	return isDone;
}

void SetOffset::End()
{

}

void SetOffset::Interrupted()
{

}
