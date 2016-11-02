#include "RobotMap.h"

std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemFrontLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemFrontRightTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemBackLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemBackRightTalon;
std::shared_ptr<RobotDrive> RobotMap::driveBaseSubsystemRobotDrive;

std::shared_ptr<CANTalon> RobotMap::shooterSubsystemShooterTalonLeft;
std::shared_ptr<CANTalon> RobotMap::shooterSubsystemShooterTalonRight;
std::shared_ptr<DoubleSolenoid> RobotMap::shooterSubsystemShooterSolenoid;
std::shared_ptr<Servo> RobotMap::shooterSubsystemShooterServoLeft;
std::shared_ptr<Servo> RobotMap::shooterSubsystemShooterServoRight;

std::shared_ptr<CANTalon> RobotMap::intakeSubsystemIntakeTalon;

std::shared_ptr<CANTalon> RobotMap::climberSubsystemClimbTalonLeft;
std::shared_ptr<CANTalon> RobotMap::climberSubsystemClimbTalonRight;
std::shared_ptr<DoubleSolenoid> RobotMap::climberSubsystemClimbSolenoid;
std::shared_ptr<DoubleSolenoid> RobotMap::climberSubsystemLatchSolenoid;

std::shared_ptr<DigitalOutput> RobotMap::ledSubsystemGreenLED;
std::shared_ptr<DigitalOutput> RobotMap::ledSubsystemRedLED;
std::shared_ptr<DigitalOutput> RobotMap::ledSubsystemBlueLED;

std::shared_ptr<CANTalon> RobotMap::defenseSubsystemTalon;

std::shared_ptr<PowerDistributionPanel> RobotMap::pdp;

std::shared_ptr<AHRS> RobotMap::robotImu;
std::shared_ptr<TigerDrive> RobotMap::tigerDrive;

void RobotMap::init() {
    driveBaseSubsystemFrontLeftTalon.reset(new CANTalon(8));
    driveBaseSubsystemFrontRightTalon.reset(new CANTalon(6));
    driveBaseSubsystemBackLeftTalon.reset(new CANTalon(9));
    driveBaseSubsystemBackRightTalon.reset(new CANTalon(2));
    driveBaseSubsystemRobotDrive.reset(new RobotDrive(driveBaseSubsystemFrontLeftTalon, driveBaseSubsystemBackLeftTalon, driveBaseSubsystemFrontRightTalon, driveBaseSubsystemBackRightTalon));

    driveBaseSubsystemRobotDrive->SetSafetyEnabled(false);
    driveBaseSubsystemRobotDrive->SetExpiration(0.1);
    driveBaseSubsystemRobotDrive->SetSensitivity(0.5);
    driveBaseSubsystemRobotDrive->SetMaxOutput(1.0);

    driveBaseSubsystemRobotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
    driveBaseSubsystemRobotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);

    shooterSubsystemShooterTalonLeft.reset(new CANTalon(4));
    shooterSubsystemShooterTalonRight.reset(new CANTalon(3));

    shooterSubsystemShooterTalonLeft->SetControlMode(CANTalon::kSpeed);
    shooterSubsystemShooterTalonLeft->SetFeedbackDevice(CANTalon::QuadEncoder);
    shooterSubsystemShooterTalonLeft->SetP(0);
    shooterSubsystemShooterTalonLeft->SetI(0);
    shooterSubsystemShooterTalonLeft->SetD(0);

    shooterSubsystemShooterTalonRight->SetControlMode(CANTalon::kSpeed);
    shooterSubsystemShooterTalonRight->SetFeedbackDevice(CANTalon::QuadEncoder);
    shooterSubsystemShooterTalonRight->SetP(0);
	shooterSubsystemShooterTalonRight->SetI(0);
	shooterSubsystemShooterTalonRight->SetD(0);

    shooterSubsystemShooterSolenoid.reset(new DoubleSolenoid(0,1));

    shooterSubsystemShooterServoLeft.reset(new Servo(1));
    shooterSubsystemShooterServoRight.reset(new Servo(0));

    intakeSubsystemIntakeTalon.reset(new CANTalon(1));
    intakeSubsystemIntakeTalon->SetInverted(true);

    climberSubsystemClimbTalonRight.reset(new CANTalon(7));
    climberSubsystemClimbTalonRight->SetInverted(true);

    climberSubsystemClimbTalonLeft.reset(new CANTalon(5));
    climberSubsystemClimbTalonLeft->SetInverted(true);
    climberSubsystemClimbTalonLeft->SetControlMode(CANTalon::kFollower);
    climberSubsystemClimbTalonLeft->Set(7);

    climberSubsystemClimbSolenoid.reset(new DoubleSolenoid(2,3));

    climberSubsystemLatchSolenoid.reset(new DoubleSolenoid(4,5));

    ledSubsystemGreenLED.reset(new DigitalOutput(1));
    ledSubsystemRedLED.reset(new DigitalOutput(2));
    ledSubsystemBlueLED.reset(new DigitalOutput(3));

    defenseSubsystemTalon.reset(new CANTalon(10));

    pdp.reset(new PowerDistributionPanel());

    robotImu.reset(new AHRS(SPI::Port::kMXP));
    tigerDrive.reset(new TigerDrive(robotImu.get()));
}
