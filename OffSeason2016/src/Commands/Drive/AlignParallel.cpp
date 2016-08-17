#include "AlignParallel.h"

AlignParallel::AlignParallel(float angle, float distanceAway)
{
	Requires(Robot::drivebaseSubsystem.get());
	isDone = false;
	targetX = 0;
	inToleranceX = false;
	calrot = 0;
	adjyaw = 0;
	targetAngle = angle;
	distanceToCenter = 0;
	speedX = 0;
	XAxis = 0;
	YAxis = 0;
	RotAxis = 0;
	distanceTarget = distanceAway;
	inToleranceY = false;
	distanceY = 0;
	speedY = 0;
	//SetTimeout(2);
	Robot::drivebaseSubsystem->isAlignedX = false;
	Robot::drivebaseSubsystem->isAlignedY = false;
}

// Called just before this Command runs the first time
void AlignParallel::Initialize()
{
	isDone = false;
	targetX = 0;
	inToleranceX = false;
	calrot = 0;
	adjyaw = 0;
	distanceToCenter = 0;
	speedX = 0;
	Robot::drivebaseSubsystem->isAlignedX = false;
	Robot::drivebaseSubsystem->isAlignedY = false;
	inToleranceY = false;
	distanceY = 0;
	speedY = 0;
}

// Called repeatedly when this Command is scheduled to run
void AlignParallel::Execute()
{
	speedX = 0;
	speedY = 0;
	XAxis = Robot::oi->GetLeftXAxisDriver();
	YAxis = Robot::oi->GetLeftYAxisDriver();
	RotAxis = Robot::oi->GetRightXAxisDriver();
	Robot::drivebaseSubsystem->isAlignedX = false;
	Robot::drivebaseSubsystem->isAlignedY = false;
	distanceToCenter = Robot::netTable->GetNumber("center", 9);
	adjyaw = Robot::drivebaseSubsystem->GetAdjYaw();
	distanceY = Robot::netTable->GetNumber("distance", 0.0);
	calrot = Robot::drivebaseSubsystem->CalculateRotValue(targetAngle, 1);
	targetX = Robot::netTable->GetNumber("targetX", 0.0);
	//std::cout << "TargetX: " << targetX << std::endl;

	if(abs(XAxis) > .2 || abs(YAxis) > .2 || abs(RotAxis) > .2) {
		isDone = true;
	}

	if(abs(distanceToCenter) <= 160)
	{
		speedX = 0.5;
	}
	if(abs(distanceToCenter) <= 80)
	{
		speedX = 0.4;
	}
	if(abs(distanceToCenter) <= 40)
	{
		speedX = 0.3;
	}

	if(distanceY <= 999999) {
		speedY = .3;
	}
	if(distanceY <= 120) {
		speedY = .2;

	}
	if(distanceY <= 96) {
		speedY = .15;
	}
	if(distanceY <= 60) {
		speedY = .15;
	}

	bool tooClose = distanceY < (distanceTarget - toleranceY);
	bool tooFar = distanceY > (distanceTarget + toleranceY);

	inToleranceY = true;

	if(tooClose) {
		printf("bot is too close in y!\n");
		std::cout << "bot distance: " << distanceY << std::endl;
		inToleranceY = false;
		
	}
	if(tooFar) {
		printf("bol is too far in y!\n");
		std::cout << "bot distance: " << distanceY << std::endl;
		inToleranceY = false;
		speedY = speedY * -1;
	
	}
	
	if(inToleranceY) {
		printf("inToleranceY is true\n");
		speedY = 0;
	}
	
	

	//targetX = targetX - 2;
	inToleranceX = true;

	//std::cout << "targetX: " << targetX << std::endl;
	//std::cout << "centerX: " << centerX << std::endl;
	//std::cout << "toleranceX: " << toleranceX << std::endl;

	if(distanceToCenter >= (0 + toleranceX)) {
		inToleranceX = false;
		//std::cout << "bot is too far right!" << std::endl;
		speedX = speedX * -1;
	
	}
	if(distanceToCenter <= (0 - toleranceX)) {
		inToleranceX = false;
		//std::cout << "bot is too far left!" << std::endl;

	}

	if(inToleranceX == true) {
		//std::cout << "inToleranceX!" << std::endl;
		speedX = 0;
	}

	//std::cout << "speedX: " << speedX << std::endl;
	std::cout << "speedY: " << speedY << std::endl;

	Robot::drivebaseSubsystem->MecanumDrive(speedX, speedY, calrot, adjyaw);

	if(inToleranceX && inToleranceY) {
		Robot::drivebaseSubsystem->MecanumDrive(0, 0, 0, 0);
		//printf("Target aligned in X dir!\n");
		Robot::drivebaseSubsystem->isAlignedX = true;
		Robot::drivebaseSubsystem->isAlignedY = true;
		isDone = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AlignParallel::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void AlignParallel::End()
{
	Robot::drivebaseSubsystem->MecanumDrive(0, 0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignParallel::Interrupted()
{
	Robot::drivebaseSubsystem->MecanumDrive(0, 0, 0, 0);
}
