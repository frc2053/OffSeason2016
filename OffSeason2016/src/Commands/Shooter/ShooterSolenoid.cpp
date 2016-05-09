#include "ShooterSolenoid.h"

ShooterSolenoid::ShooterSolenoid()
{
	Requires(Robot::shooterSubsystem.get());
	isDone = false;
	timer.reset(new Timer());
	timeTarget = PNUEMATIC_DELAY;
	timeCurrent = 0;
}

void ShooterSolenoid::Initialize()
{
	isDone = false;
	timer->Reset();
	timer->Start();
	timeTarget = PNUEMATIC_DELAY;
	timeCurrent = 0;
}

void ShooterSolenoid::Execute()
{
	isDone = false;
	//gets current time
	timeCurrent = timer->Get();

	//if we are past the time we want to stop at
	if(timeCurrent >= timeTarget) {
		Robot::shooterSubsystem->SetSolenoidReverse();
		isDone = true;
	}
	//checks if we have the shooter wheels at the correct speed
	//if we do, open servos, wait .25 seconds, then shoot
	else {
		if(Robot::shooterSubsystem->GetEncoderVelocityRight() <= -32000) {
			Robot::shooterSubsystem->SetAngleLeftServo(0);
			Robot::shooterSubsystem->SetAngleRightServo(200);
			Wait(.25);
			Robot::shooterSubsystem->SetSolenoidForward();
		}
		isDone = false;
	}
}

bool ShooterSolenoid::IsFinished()
{
	return isDone;
}

void ShooterSolenoid::End()
{
	timer->Stop();
}

void ShooterSolenoid::Interrupted()
{

}
