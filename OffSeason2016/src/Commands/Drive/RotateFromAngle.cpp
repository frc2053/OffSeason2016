#include "RotateFromAngle.h"
#include "../Autonomous/DriveCommandAuto.h"

//NOTE!!! - ONLY WORKS IF YOU ARE USING THIS IN TELEOP!!!!
//THIS IS BECAUSE IF YOU USE THIS IN AUTO IT GETS CONSTRUCTED
//AS SOON AS THE ROBOT BOOTS, SO IT WILL USE THE ANGLE THAT
//THE ROBOT STARTED AT WHEN IT BOOTED!

RotateFromAngle::RotateFromAngle(float offset)
{
	float angle = Robot::drivebaseSubsystem->GetAdjYaw();
	AddSequential(new DriveCommandAuto(0, 0, 0, 1, angle + offset));
}
