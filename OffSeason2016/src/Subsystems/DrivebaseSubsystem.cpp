#include "DrivebaseSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/Drive/DriveCommand.h"


DrivebaseSubsystem::DrivebaseSubsystem() : Subsystem("DrivebaseSubsystem")
{
	frontLeftTalon = RobotMap::driveBaseSubsystemFrontLeftTalon;
	frontRightTalon = RobotMap::driveBaseSubsystemFrontRightTalon;
	backLeftTalon = RobotMap::driveBaseSubsystemBackLeftTalon;
	backRightTalon = RobotMap::driveBaseSubsystemBackRightTalon;
	robotDrive = RobotMap::driveBaseSubsystemRobotDrive;
	robotImu = RobotMap::robotImu;
	tigerDrive = RobotMap::tigerDrive;

	imuYaw = 0;
	calculatedOffset = 0;
	yawOffset = 0;
	isAlignedX = false;
	isAlignedY = false;
}

void DrivebaseSubsystem::InitDefaultCommand()
{
	SetDefaultCommand(new DriveCommand());
}

void DrivebaseSubsystem::MecanumDrive(float x, float y, float rot, float gyro)
{
	robotDrive->MecanumDrive_Cartesian(x,y,rot,gyro);
}

float DrivebaseSubsystem::CalculateRotValue(float setAngle, float setSpeed)
{
	return tigerDrive->CalculateRotValue(setAngle, setSpeed);
}

bool DrivebaseSubsystem::GetIsRotDone()
{
	return tigerDrive->GetIsRotDone();
}

float DrivebaseSubsystem::GetAdjYaw()
{
	return tigerDrive->GetAdjYaw();
}

void DrivebaseSubsystem::SetAdjYaw(float offset)
{
	tigerDrive->SetAdjYaw(offset);
}

void DrivebaseSubsystem::SetIsRotDone(bool isDone)
{
	tigerDrive->SetIsRotDone(isDone);
}

void DrivebaseSubsystem::SetIsRotDoneOverride(bool isDone)
{
	tigerDrive->SetIsRotDoneOverride(isDone);
}

void DrivebaseSubsystem::SetTimesThroughLoop(int timeLoop)
{
	tigerDrive->SetTimesThroughLoop(timeLoop);
}

float DrivebaseSubsystem::GetImuYaw()
{
	return tigerDrive->GetImuYaw();
}

bool DrivebaseSubsystem::GetIsRotDoneOverride()
{
	return tigerDrive->GetIsRotDoneOverride();
}

bool DrivebaseSubsystem::IsAlignedX() {
	return isAlignedX;
}

bool DrivebaseSubsystem::IsAlignedY() {
	return isAlignedY;
}

void DrivebaseSubsystem::ZeroYaw() {
	robotImu->ZeroYaw();
}
