#include "GoalAlignVertical.h"

GoalAlignVertical::GoalAlignVertical(float distanceAway)
{
	Requires(Robot::drivebaseSubsystem.get());
	distanceTarget = distanceAway;
	inToleranceY = false;
	distanceY = 0;
	speedY = 0;
	isDone = false;
	calrot = 0;
	adjyaw = 0;
	XAxis = 0;
	YAxis = 0;
	RotAxis = 0;
	Robot::drivebaseSubsystem->isAlignedY = false;
}

// Called just before this Command runs the first time
void GoalAlignVertical::Initialize()
{
	inToleranceY = false;
	distanceY = 0;
	speedY = 0;
	isDone = false;
	calrot = 0;
	adjyaw = 0;
	Robot::drivebaseSubsystem->isAlignedY = false;
}

// Called repeatedly when this Command is scheduled to run
void GoalAlignVertical::Execute()
{
	XAxis = Robot::oi->GetLeftXAxisDriver();
	YAxis = Robot::oi->GetLeftYAxisDriver();
	RotAxis = Robot::oi->GetRightXAxisDriver();
	Robot::drivebaseSubsystem->isAlignedY = false;
	distanceY = Robot::netTable->GetNumber("distance", 0.0);
	adjyaw = Robot::drivebaseSubsystem->GetAdjYaw();
	calrot = Robot::drivebaseSubsystem->CalculateRotValue(0, 1);

	if(XAxis > .2 || YAxis > .2 || RotAxis > .2) {
		isDone = true;
	}

	if(distanceY >= 144) {
		speedY = .15;
	}
	if(distanceY >= 120) {
		speedY = .15;
	}
	if(distanceY >= 96) {
		speedY = .15;
	}
	if(distanceY >= 60) {
		speedY = .15;
	}

	bool tooClose = distanceY < (distanceTarget - toleranceY);
	bool tooFar = distanceY > (distanceTarget + toleranceY);
	//std::cout << "distanceY: " << distanceY << std::endl;

	std::cout << "tooClose: " << tooClose << std::endl;
	std::cout << "tooFar: " << tooFar << std::endl;
	std::cout << "distanceFromGoalAlign: " << distanceY << std::endl;
	if(tooClose) {
		//printf("bot is too close!\n");
		inToleranceY = false;
		Robot::drivebaseSubsystem->MecanumDrive(0, speedY, calrot, adjyaw);
	}
	else if(tooFar) {
		//printf("bot is too far!\n");
		inToleranceY = false;
		Robot::drivebaseSubsystem->MecanumDrive(0, -speedY, calrot, adjyaw);
	}
	else {
		//printf("inTolerance == true\n");
		inToleranceY = true;
	}

	if(inToleranceY) {
		Robot::drivebaseSubsystem->isAlignedY = true;
		Robot::drivebaseSubsystem->MecanumDrive(0, 0, 0, 0);
		//printf("Target aligned in Y!\n");
		isDone = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool GoalAlignVertical::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void GoalAlignVertical::End()
{
	Robot::drivebaseSubsystem->MecanumDrive(0, 0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GoalAlignVertical::Interrupted()
{
	Robot::drivebaseSubsystem->MecanumDrive(0, 0, 0, 0);
}
