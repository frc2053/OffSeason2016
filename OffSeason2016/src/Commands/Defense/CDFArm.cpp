#include "CDFArm.h"

CDFArm::CDFArm(float speed, float time)
{
	Requires(Robot::defenseSubsystem.get());
	isDone = false;
	timeTarget = time;
	timeCurrent = 0;
	inputSpeed = speed;
	timer.reset(new Timer());
	timer->Reset();
	timer->Start();
}

void CDFArm::Initialize()
{
	isDone = false;
	timeCurrent = 0;
	timer->Reset();
	timer->Start();
}

void CDFArm::Execute()
{
	timeCurrent = timer->Get();
	if(timeTarget == 0) {
		Robot::defenseSubsystem->RunMotor(inputSpeed);
		isDone = true;
	}
	else {
		if(timeCurrent >= timeTarget) {
			Robot::defenseSubsystem->RunMotor(0);
			isDone = true;
		}
		else {
			Robot::defenseSubsystem->RunMotor(inputSpeed);
			isDone = false;
		}
	}
}

bool CDFArm::IsFinished()
{
	return isDone;
}

void CDFArm::End()
{
	timer->Stop();
}

void CDFArm::Interrupted()
{

}
