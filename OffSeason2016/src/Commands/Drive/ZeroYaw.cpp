#include "ZeroYaw.h"

ZeroYaw::ZeroYaw()
{
	Requires(Robot::drivebaseSubsystem.get());
	isDone = false;
}

void ZeroYaw::Initialize()
{
	isDone = false;
}

void ZeroYaw::Execute()
{
	isDone = false;
	Robot::drivebaseSubsystem->ZeroYaw();
	isDone = true;
}

bool ZeroYaw::IsFinished()
{
	return isDone;
}

void ZeroYaw::End()
{

}

void ZeroYaw::Interrupted()
{

}
