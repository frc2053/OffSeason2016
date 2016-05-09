#include "DriveCommand.h"

DriveCommand::DriveCommand()
{
	Requires(Robot::drivebaseSubsystem.get());
	xAxis = 0;
	yAxis = 0;
	rotAxis = 0;
	adjustedYaw = 0;
	setAngle = 0;
	setSpeed = 1;
	finalAutoRot = 0;
	isRotDone = false;
	buttonAPressed = false;
	buttonBPressed = false;
	buttonXPressed = false;
	buttonYPressed = false;
}

void DriveCommand::Initialize()
{
	xAxis = 0;
	yAxis = 0;
	rotAxis = 0;
	adjustedYaw = 0;
	setSpeed = 1;
	finalAutoRot = 0;
	setAngle = 0;
	isRotDone = false;
	buttonAPressed = false;
	buttonBPressed = false;
	buttonXPressed = false;
	buttonYPressed = false;
}

void DriveCommand::Execute()
{
	//puts useful info on smart dashboard
	SmartDashboard::PutNumber("IMU Yaw", adjustedYaw);
	SmartDashboard::PutNumber("X Axis", xAxis);
	SmartDashboard::PutNumber("Y Axis", yAxis);
	SmartDashboard::PutNumber("Rot Axis", rotAxis);

	//Gets joystick values and deadbands them
	xAxis = Robot::oi->GetLeftXAxisDriver();
	yAxis = Robot::oi->GetLeftYAxisDriver();
	rotAxis = Robot::oi->GetRightXAxisDriver();

	//Gets if buttons are pressed (for rotating to angles)
	buttonAPressed = Robot::oi->GetAButtonDriver();
	buttonBPressed = Robot::oi->GetBButtonDriver();
	buttonXPressed = Robot::oi->GetXButtonDriver();
	buttonYPressed = Robot::oi->GetYButtonDriver();

	//gets imu yaw and if the robot is done rotating
	adjustedYaw = Robot::drivebaseSubsystem->GetAdjYaw();
	isRotDone = Robot::drivebaseSubsystem->GetIsRotDone();

	//writes to setAngle to set which angle to go to depending on button
	DriveCommand::SetAngleWithButton();
	//sends values to rotate to angle if button is pressed or we are not done rotating
	DriveCommand::RotateCommand();
	//checks if we overrided the rotating with the rotAxis
	DriveCommand::CheckRotateOverride();
	//Calls mecanum drive function to actually run motors
	DriveCommand::CallToMecanumDrive();
}

bool DriveCommand::IsFinished()
{
	return false;
}

void DriveCommand::End()
{

}

void DriveCommand::Interrupted()
{

}

void DriveCommand::SetAngleWithButton()
{
	if(buttonAPressed) {
		setAngle = 180;
	}

	if(buttonBPressed) {
		setAngle = 90;
	}

	if(buttonXPressed) {
		setAngle = -90;
	}

	if(buttonYPressed) {
		setAngle = 0;
	}
}

void DriveCommand::RotateCommand()
{
	if(((buttonYPressed == true||buttonXPressed == true || buttonAPressed == true || buttonBPressed == true) && isRotDone == true) || (isRotDone == false))
	{
		finalAutoRot = Robot::drivebaseSubsystem->CalculateRotValue(setAngle, setSpeed);
	}
}

void DriveCommand::CheckRotateOverride() {
	if(Robot::drivebaseSubsystem->GetIsRotDoneOverride())
	{
		finalAutoRot = 0;
	}
}

void DriveCommand::CallToMecanumDrive() {
	if(rotAxis == 0)
	{
		Robot::drivebaseSubsystem->SetIsRotDoneOverride(false);
		Robot::drivebaseSubsystem->MecanumDrive(xAxis, yAxis, finalAutoRot, adjustedYaw);
	}
	else
	{
		Robot::drivebaseSubsystem->SetIsRotDoneOverride(true);
		Robot::drivebaseSubsystem->SetIsRotDone(true);
		Robot::drivebaseSubsystem->SetTimesThroughLoop(0);
		Robot::drivebaseSubsystem->MecanumDrive(xAxis, yAxis, rotAxis, adjustedYaw);
	}
}
