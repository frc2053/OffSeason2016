#include "ClimberSolenoid.h"

ClimberSolenoid::ClimberSolenoid(bool solenoidDirection)
{
	Requires(Robot::climberSubsystem.get());
	isDone = false;
	direction = solenoidDirection;
	timeTarget = PNUEMATIC_DELAY;
	timeCurrent = 0;
	timer.reset(new Timer());
	timer->Reset();
	timer->Start();
}

void ClimberSolenoid::Initialize()
{
	isDone = false;
	timer->Reset();
	timer->Start();
	timeTarget = PNUEMATIC_DELAY;
	timeCurrent = 0;
}

void ClimberSolenoid::Execute()
{
	isDone = false;
	timeCurrent = timer->Get();

	if(timeCurrent >= timeTarget) {
		isDone = true;
	}
	else {
		isDone = false;
	}

	if(direction == true) {
		Robot::climberSubsystem->SetSolenoidForward();
	}
	if(direction == false) {
		Robot::climberSubsystem->SetSolenoidReverse();
	}
}

bool ClimberSolenoid::IsFinished()
{
	return isDone;
}

void ClimberSolenoid::End()
{
	timer->Stop();
}

void ClimberSolenoid::Interrupted()
{

}
