#include "ClimberMotor.h"

ClimberMotor::ClimberMotor(float speed, float time)
{
	Requires(Robot::climberSubsystem.get());
	isDone = false;
	timeTarget = time;
	timeCurrent = 0;
	inputSpeed = speed;
	timer.reset(new Timer());
	timer->Reset();
	timer->Start();
}

void ClimberMotor::Initialize()
{
	timer->Reset();
	timer->Start();
	timeCurrent = 0;
	isDone = false;
}

void ClimberMotor::Execute()
{
	timeCurrent = timer->Get();
	if(timeTarget == 0) {
		Robot::climberSubsystem->RunBothMotors(inputSpeed);
		isDone = true;
	}
	else {
		if(timeCurrent >= timeTarget) {
			Robot::climberSubsystem->RunBothMotors(0);
			isDone = true;
		}
		else {
			Robot::climberSubsystem->RunBothMotors(inputSpeed);
			isDone = false;
		}
	}
}

bool ClimberMotor::IsFinished()
{
	return isDone;
}

void ClimberMotor::End()
{
	timer->Stop();
}

void ClimberMotor::Interrupted()
{

}
