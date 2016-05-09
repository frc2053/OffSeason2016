#include "ShooterWheels.h"

ShooterWheels::ShooterWheels(float speed, float time, float servoangleleft, float servoangleright)
{
	Requires(Robot::shooterSubsystem.get());
	isDone = false;
	timeTarget = time;
	timeCurrent = 0;
	inputSpeed = speed;
	timer.reset(new Timer());
	timer->Reset();
	timer->Start();
	velocityLeftWheel = 0;
	velocityRightWheel = 0;
	servoAngleLeft = servoangleleft;
	servoAngleRight = servoangleright;
}

void ShooterWheels::Initialize()
{
	timer->Reset();
	timer->Start();
	timeCurrent = 0;
	isDone = false;
	velocityLeftWheel = 0;
	velocityRightWheel = 0;
	servoAngleLeft = 70;
	servoAngleRight = 110;
}

void ShooterWheels::Execute()
{
	velocityLeftWheel = Robot::shooterSubsystem->GetEncoderVelocityLeft();
	velocityRightWheel = Robot::shooterSubsystem->GetEncoderVelocityRight();

	SmartDashboard::PutNumber("Velocity Left Wheel", velocityLeftWheel);
	SmartDashboard::PutNumber("Velocity Right Wheel", velocityRightWheel);

	timeCurrent = timer->Get();

	//if we are in teleop modes
	if(timeTarget == 0) {
		Robot::shooterSubsystem->RunBothMotors(inputSpeed);
		Robot::shooterSubsystem->SetAngleLeftServo(servoAngleLeft);
		Robot::shooterSubsystem->SetAngleRightServo(servoAngleRight);
		isDone = true;
	}
	//if we are in auto mode
	else {
		if(timeCurrent >= timeTarget) {
			Robot::shooterSubsystem->RunBothMotors(0);
			isDone = true;
		}
		else {
			Robot::shooterSubsystem->RunBothMotors(inputSpeed);
			isDone = false;
		}
	}
}

bool ShooterWheels::IsFinished()
{
	return isDone;
}

void ShooterWheels::End()
{
	Robot::shooterSubsystem->RunBothMotors(0);
	timer->Stop();
}

void ShooterWheels::Interrupted()
{

}
