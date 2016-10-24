#include "ClimberSubsystem.h"
#include "../RobotMap.h"

ClimberSubsystem::ClimberSubsystem() : Subsystem("ClimberSubsystem")
{
	climbTalonRight = RobotMap::climberSubsystemClimbTalonRight;
	climbTalonLeft = RobotMap::climberSubsystemClimbTalonLeft;
	climbSolenoid = RobotMap::climberSubsystemClimbSolenoid;
}

void ClimberSubsystem::InitDefaultCommand()
{

}

void ClimberSubsystem::RunBothMotors(float speed) {
	climbTalonRight->Set(speed);
	climbTalonLeft->Set(speed);
}

void ClimberSubsystem::RunRightMotor(float speed) {
	climbTalonRight->Set(speed);
}

void ClimberSubsystem::RunLeftMotor(float speed)
{
	climbTalonLeft->Set(speed);
}

void ClimberSubsystem::SetClimbSolenoidForward() {
	climbSolenoid->Set(DoubleSolenoid::kForward);
}

void ClimberSubsystem::SetClimbSolenoidReverse() {
	climbSolenoid->Set(DoubleSolenoid::kReverse);
}

void ClimberSubsystem::SetLatchSolenoidForward() {
	latchSolenoid->Set(DoubleSolenoid::kForward);
}

void ClimberSubsystem::SetLatchSolenoidReverse() {
	latchSolenoid->Set(DoubleSolenoid::kReverse);
}

bool ClimberSubsystem::GetForwardLimitSwitch() {
	return climbTalonRight->IsFwdLimitSwitchClosed();
}

bool ClimberSubsystem::GetReverseLimitSwitch() {
	return climbTalonRight->IsRevLimitSwitchClosed();
}
