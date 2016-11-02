#include "ClimberLatchSolenoid.h"

ClimberLatchSolenoid::ClimberLatchSolenoid(bool solenoidDirection)
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

void ClimberLatchSolenoid::Initialize()
{
	isDone = false;
	timer->Reset();
	timer->Start();
	timeTarget = PNUEMATIC_DELAY;
	timeCurrent = 0;
}

void ClimberLatchSolenoid::Execute()
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
		Robot::climberSubsystem->SetLatchSolenoidForward();
	}
	if(direction == false) {
		Robot::climberSubsystem->SetLatchSolenoidReverse();
	}
}

bool ClimberLatchSolenoid::IsFinished()
{
	return isDone;
}

void ClimberLatchSolenoid::End()
{
	timer->Stop();
}

void ClimberLatchSolenoid::Interrupted()
{

}
