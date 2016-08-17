#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"

//command includes
#include "Commands/Shooter/ShooterSolenoid.h"
#include "Commands/Shooter/ShooterWheels.h"

#include "Commands/Intake/IntakeRoller.h"

#include "Commands/Defense/CDFArm.h"

#include "Commands/Climber/ClimberSolenoid.h"
#include "Commands/Climber/ClimberMotor.h"

#include "Commands/Drive/ZeroYaw.h"

OI::OI() {
	driverJoystick.reset(new Joystick(0));
	operatorJoystick.reset(new Joystick(1));

	aButtonOperator.reset(new JoystickButton(operatorJoystick.get(), 1));
	bButtonOperator.reset(new JoystickButton(operatorJoystick.get(), 2));
	yButtonOperator.reset(new JoystickButton(operatorJoystick.get(), 4));
	leftBumperOperator.reset(new JoystickButton(operatorJoystick.get(), 5));
	rightBumperOperator.reset(new JoystickButton(operatorJoystick.get(), 6));
	backButtonOperator.reset(new JoystickButton(operatorJoystick.get(), 7));
	startButtonOperator.reset(new JoystickButton(operatorJoystick.get(), 8));

	leftTriggerOperator.reset(new TigerLeftTrigger(operatorJoystick.get(), 2));
	rightTriggerOperator.reset(new TigerRightTrigger(operatorJoystick.get(), 3));

	aButtonOperator->WhenPressed(new ShooterSolenoid());

	leftBumperOperator->WhenPressed(new CDFArm(-1, 0));
	leftBumperOperator->WhenReleased(new CDFArm(0, 0));

	rightBumperOperator->WhenPressed(new CDFArm(1, 0));
	rightBumperOperator->WhenReleased(new CDFArm(0, 0));

	bButtonOperator->WhenPressed(new ClimberSolenoid(false));
	yButtonOperator->WhenPressed(new ClimberSolenoid(true));

	backButtonOperator->WhenPressed(new ClimberMotor(-.75, 0));
	backButtonOperator->WhenReleased(new ClimberMotor(0, 0));

	startButtonOperator->WhenPressed(new ClimberMotor(1, 0));
	startButtonOperator->WhenReleased(new ClimberMotor(0, 0));

	leftTriggerOperator->WhileActive(new ShooterWheels(-1500, 0, 0, 200));
	leftTriggerOperator->WhenInactive(new ShooterWheels(0, 0, 70, 110));

	leftTriggerOperator->WhileActive(new IntakeRoller(1, 0));
	leftTriggerOperator->WhenInactive(new IntakeRoller(0, 0));

	rightTriggerOperator->WhileActive(new ShooterWheels(6000, 0, 70, 110));
	rightTriggerOperator->WhenInactive(new ShooterWheels(0, 0, 70, 110));

	rightTriggerOperator->WhileActive(new IntakeRoller(-1, 0));
	rightTriggerOperator->WhenInactive(new IntakeRoller(0, 0));

	//smartdashboard buttons to run commands
	SmartDashboard::PutData("Zero Yaw", new ZeroYaw());
}

double OI::GetLeftXAxisDriver() {
	double joystickValue = OI::DeadBandJoystick(driverJoystick.get()->GetRawAxis(0));
	return joystickValue;
}

double OI::GetLeftYAxisDriver() {
	double joystickValue = OI::DeadBandJoystick(driverJoystick.get()->GetRawAxis(1));
	return joystickValue;
}

double OI::GetRightXAxisDriver() {
	double joystickValue = OI::DeadBandJoystick(driverJoystick.get()->GetRawAxis(4));
	return joystickValue;
}

double OI::GetRightYAxisDriver() {
	double joystickValue = OI::DeadBandJoystick(driverJoystick.get()->GetRawAxis(5));
	return joystickValue;
}

double OI::GetLeftXAxisOperator() {
	double joystickValue = OI::DeadBandJoystick(operatorJoystick.get()->GetRawAxis(0));
	return joystickValue;
}

double OI::GetLeftYAxisOperator() {
	double joystickValue = OI::DeadBandJoystick(operatorJoystick.get()->GetRawAxis(1));
	return joystickValue;
}

double OI::GetRightXAxisOperator() {
	double joystickValue = OI::DeadBandJoystick(operatorJoystick.get()->GetRawAxis(4));
	return joystickValue;
}

double OI::GetRightYAxisOperator() {
	double joystickValue = OI::DeadBandJoystick(operatorJoystick.get()->GetRawAxis(5));
	return joystickValue;
}

float OI::DeadBandJoystick(float axis) {
	if(axis > -0.20 && axis < 0.20)
	{
		axis = 0;
	}
	else
	{
		axis = axis * fabs(axis);
	}
	return axis;
}

bool OI::GetAButtonDriver() {
	return driverJoystick->GetRawButton(1);
}

bool OI::GetBButtonDriver() {
	return driverJoystick->GetRawButton(2);
}

bool OI::GetXButtonDriver() {
	return driverJoystick->GetRawButton(3);
}

bool OI::GetYButtonDriver() {
	return driverJoystick->GetRawButton(4);
}

bool OI::GetLeftBumperDriver() {
	return driverJoystick->GetRawButton(5);
}

bool OI::GetRightBumperDriver() {
	return driverJoystick->GetRawButton(6);
}

bool OI::GetBackButtonDriver() {
	return driverJoystick->GetRawButton(7);
}

bool OI::GetStartButtonDriver() {
	return driverJoystick->GetRawButton(8);
}

bool OI::GetLeftStickButtonDriver() {
	return driverJoystick->GetRawButton(9);
}

bool OI::GetRightStickButtonDriver() {
	return driverJoystick->GetRawButton(10);
}

bool OI::GetAButtonOperator() {
	return operatorJoystick->GetRawButton(1);
}

bool OI::GetBButtonOperator() {
	return operatorJoystick->GetRawButton(2);
}

bool OI::GetXButtonOperator() {
	return operatorJoystick->GetRawButton(3);
}

bool OI::GetYButtonOperator() {
	return operatorJoystick->GetRawButton(4);
}

bool OI::GetLeftBumperOperator() {
	return operatorJoystick->GetRawButton(5);
}

bool OI::GetRightBumperOperator() {
	return operatorJoystick->GetRawButton(6);
}

bool OI::GetBackButtonOperator() {
	return operatorJoystick->GetRawButton(7);
}

bool OI::GetStartButtonOperator() {
	return operatorJoystick->GetRawButton(8);
}

bool OI::GetLeftStickButtonOperator() {
	return operatorJoystick->GetRawButton(9);
}

bool OI::GetRightStickButtonOperator() {
	return operatorJoystick->GetRawButton(10);
}

std::shared_ptr<Joystick> OI::GetDriverJoystick() {
   return driverJoystick;
}

std::shared_ptr<Joystick> OI::GetOperatorJoystick() {
   return operatorJoystick;
}
