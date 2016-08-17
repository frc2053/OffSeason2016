#include "IntakeRoller.h"

IntakeRoller::IntakeRoller(float speed, float time)
{
	Requires(Robot::intakeSubsystem.get());
	timer.reset(new Timer());
	isDone = false;
	timeTarget = time;
	timeCurrent = 0;
	inputSpeed = speed;
	timer->Reset();
	timer->Start();
}

void IntakeRoller::Initialize()
{
	isDone = false;
	timeCurrent = 0;
	timer->Reset();
	timer->Start();
}

void IntakeRoller::Execute()
{
	timeCurrent = timer->Get();
	if(timeTarget == 0) {
		Robot::intakeSubsystem->RunMotor(inputSpeed);
		isDone = true;
	}
	else {
		if(timeCurrent >= timeTarget) {
			Robot::intakeSubsystem->RunMotor(0);
			isDone = true;
		}
		else {
			Robot::intakeSubsystem->RunMotor(inputSpeed);
			isDone = false;
		}
	}
}

bool IntakeRoller::IsFinished()
{
	return isDone;
}

void IntakeRoller::End()
{
	timer->Stop();
}

void IntakeRoller::Interrupted()
{

}
