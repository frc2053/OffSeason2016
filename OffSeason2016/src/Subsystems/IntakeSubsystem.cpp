#include "IntakeSubsystem.h"
#include "../RobotMap.h"

IntakeSubsystem::IntakeSubsystem() : Subsystem("IntakeSubsystem")
{
	intakeTalon = RobotMap::intakeSubsystemIntakeTalon;
}

void IntakeSubsystem::InitDefaultCommand()
{

}

void IntakeSubsystem::RunMotor(float speed) {
	intakeTalon->Set(speed);
}
