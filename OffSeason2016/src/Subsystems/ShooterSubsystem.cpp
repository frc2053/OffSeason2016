#include "ShooterSubsystem.h"
#include "../RobotMap.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem")
{
    shooterTalonLeft = RobotMap::shooterSubsystemShooterTalonLeft;
    shooterTalonRight = RobotMap::shooterSubsystemShooterTalonRight;
    shooterSolenoid = RobotMap::shooterSubsystemShooterSolenoid;
    shooterServoLeft = RobotMap::shooterSubsystemShooterServoLeft;
    shooterServoRight = RobotMap::shooterSubsystemShooterServoRight;
}

void ShooterSubsystem::InitDefaultCommand()
{

}

void ShooterSubsystem::RunBothMotors(float speed)
{
	shooterTalonLeft->Set(speed);
	shooterTalonRight->Set(speed);
}

void ShooterSubsystem::RunLeftMotor(float speed)
{
	shooterTalonLeft->Set(speed);
}

void ShooterSubsystem::RunRightMotor(float speed) {
	shooterTalonRight->Set(speed);
}

void ShooterSubsystem::SetSolenoidForward() {
	shooterSolenoid->Set(DoubleSolenoid::kForward);
}

void ShooterSubsystem::SetSolenoidReverse() {
	shooterSolenoid->Set(DoubleSolenoid::kReverse);
}

double ShooterSubsystem::GetEncoderVelocityLeft() {
	return (shooterTalonLeft->GetEncVel() * -1);
}

double ShooterSubsystem::GetEncoderVelocityRight() {
	return (shooterTalonRight->GetEncVel() * -1);
}

void ShooterSubsystem::SetAngleLeftServo(float inputAngle) {
	shooterServoLeft->SetAngle(inputAngle);
}

void ShooterSubsystem::SetAngleRightServo(float inputAngle) {
	shooterServoRight->SetAngle(inputAngle);
}
