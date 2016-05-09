#include "DriveCommandAuto.h"

DriveCommandAuto::DriveCommandAuto(float side, float fow, float rot, float time, float angle)
{
	Requires(Robot::drivebaseSubsystem.get());
	inputSide = side;
	inputFow = fow;
	inputRot = rot;
	timeTarget = time;
	inputAngle = angle;
	timeCurrent = 0;
	isDone = false;
	adjustedYaw = 0;
	finalAutoRot = 0;
	isRotDone = false;
	timer.reset(new Timer());
	timer->Reset();
	timer->Start();
}

void DriveCommandAuto::Initialize()
{
	timer->Reset();
	timer->Start();
}

void DriveCommandAuto::Execute()
{
	timeCurrent = timer->Get();
	adjustedYaw = Robot::drivebaseSubsystem->GetAdjYaw();
	isRotDone = Robot::drivebaseSubsystem->GetIsRotDone();
	finalAutoRot = Robot::drivebaseSubsystem->CalculateRotValue(inputAngle, 1);
	Robot::drivebaseSubsystem->MecanumDrive(inputSide, inputFow, finalAutoRot, adjustedYaw);
	if((timeCurrent >= timeTarget) || isRotDone) {
		Robot::drivebaseSubsystem->MecanumDrive(0,0,0,0);
		isDone = true;
	}
	else {
		isDone = false;
	}
}

bool DriveCommandAuto::IsFinished()
{
	return isDone;
}

void DriveCommandAuto::End()
{
	timer->Stop();
	Robot::drivebaseSubsystem->MecanumDrive(0,0,0,0);
}

void DriveCommandAuto::Interrupted()
{
	Robot::drivebaseSubsystem->MecanumDrive(0,0,0,0);
}
