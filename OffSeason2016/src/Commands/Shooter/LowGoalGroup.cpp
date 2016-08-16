#include "LowGoalGroup.h"

LowGoalGroup::LowGoalGroup()
{
	AddSequential(new ShooterWheels(3000, .4, 70, 110));
	AddSequential(new ShooterWheels(0, .1, 0, 200));
	Robot::shooterSubsystem->SetSolenoidForward();
	Wait(1);
	Robot::shooterSubsystem->SetSolenoidReverse();
	AddSequential(new ShooterWheels(0, .1, 70, 110));
}
