#ifndef ShooterSubsystem_H
#define ShooterSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterSubsystem: public Subsystem
{
private:
	std::shared_ptr<CANTalon> shooterTalonLeft;
	std::shared_ptr<CANTalon> shooterTalonRight;
	std::shared_ptr<Servo> shooterServoLeft;
	std::shared_ptr<Servo> shooterServoRight;
	std::shared_ptr<DoubleSolenoid> shooterSolenoid;
public:
	ShooterSubsystem();
	void InitDefaultCommand();
	void RunBothMotors(float speed);
	void RunLeftMotor(float speed);
	void RunRightMotor(float speed);
	void SetSolenoidForward();
	void SetSolenoidReverse();
	void SetAngleLeftServo(float inputAngle);
	void SetAngleRightServo(float inputAngle);
	double GetEncoderVelocityLeft();
	double GetEncoderVelocityRight();
};

#endif
