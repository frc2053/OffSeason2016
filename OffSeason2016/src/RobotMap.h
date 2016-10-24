#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "TigerDrive/TigerDrive.h"

class RobotMap {
public:
	static void init();

	static std::shared_ptr<CANTalon> driveBaseSubsystemFrontLeftTalon;
	static std::shared_ptr<CANTalon> driveBaseSubsystemFrontRightTalon;
	static std::shared_ptr<CANTalon> driveBaseSubsystemBackLeftTalon;
	static std::shared_ptr<CANTalon> driveBaseSubsystemBackRightTalon;
	static std::shared_ptr<RobotDrive> driveBaseSubsystemRobotDrive;

	static std::shared_ptr<CANTalon> shooterSubsystemShooterTalonLeft;
	static std::shared_ptr<CANTalon> shooterSubsystemShooterTalonRight;
	static std::shared_ptr<DoubleSolenoid> shooterSubsystemShooterSolenoid;
	static std::shared_ptr<Servo> shooterSubsystemShooterServoLeft;
	static std::shared_ptr<Servo> shooterSubsystemShooterServoRight;

	static std::shared_ptr<CANTalon> intakeSubsystemIntakeTalon;

	static std::shared_ptr<CANTalon> climberSubsystemClimbTalonLeft;
	static std::shared_ptr<CANTalon> climberSubsystemClimbTalonRight;
	static std::shared_ptr<DoubleSolenoid> climberSubsystemClimbSolenoid;
	static std::shared_ptr<DoubleSolenoid> climberSubsystemLatchSolenoid;

	static std::shared_ptr<DigitalOutput> ledSubsystemGreenLED;
	static std::shared_ptr<DigitalOutput> ledSubsystemRedLED;
	static std::shared_ptr<DigitalOutput> ledSubsystemBlueLED;

	static std::shared_ptr<CANTalon> defenseSubsystemTalon;

	static std::shared_ptr<PowerDistributionPanel> pdp;

	static std::shared_ptr<AHRS> robotImu;
	static std::shared_ptr<TigerDrive> tigerDrive;
};
#endif
