#ifndef ClimberSubsystem_H
#define ClimberSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ClimberSubsystem: public Subsystem
{
private:
	std::shared_ptr<CANTalon> climbTalonLeft;
	std::shared_ptr<CANTalon> climbTalonRight;
	std::shared_ptr<DoubleSolenoid> climbSolenoid;
	std::shared_ptr<DoubleSolenoid> latchSolenoid;
public:
	ClimberSubsystem();
	void InitDefaultCommand();
	void RunBothMotors(float speed);
	void RunLeftMotor(float speed);
	void RunRightMotor(float speed);
	void SetClimbSolenoidForward();
	void SetClimbSolenoidReverse();
	void SetLatchSolenoidForward();
	void SetLatchSolenoidReverse();
	bool GetForwardLimitSwitch();
	bool GetReverseLimitSwitch();
};

#endif
