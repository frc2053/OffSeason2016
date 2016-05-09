#include "DefenseSubsystem.h"
#include "../RobotMap.h"

DefenseSubsystem::DefenseSubsystem() : Subsystem("DefenseSubsystem")
{
	defenseTalon = RobotMap::defenseSubsystemTalon;
}

void DefenseSubsystem::InitDefaultCommand()
{

}

void DefenseSubsystem::RunMotor(float speed) {
	defenseTalon->Set(speed);
}
