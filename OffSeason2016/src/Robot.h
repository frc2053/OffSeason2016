#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "OI.h"

#include "Subsystems/DrivebaseSubsystem.h"
#include "Subsystems/ShooterSubsystem.h"
#include "Subsystems/IntakeSubsystem.h"
#include "Subsystems/LedSubsystem.h"
#include "Subsystems/ClimberSubsystem.h"
#include "Subsystems/DefenseSubsystem.h"

class Robot : public IterativeRobot {
public:
	static std::unique_ptr<OI> oi;
	static std::shared_ptr<DrivebaseSubsystem> drivebaseSubsystem;
	static std::shared_ptr<ShooterSubsystem> shooterSubsystem;
	static std::shared_ptr<IntakeSubsystem> intakeSubsystem;
	static std::shared_ptr<ClimberSubsystem> climberSubsystem;
	static std::shared_ptr<DefenseSubsystem> defenseSubsystem;
	static std::shared_ptr<LedSubsystem> ledSubsystem;
	static std::shared_ptr<NetworkTable> netTable;

	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
private:
	SendableChooser* chooserObstacle;
	SendableChooser*  chooserGoal;
	Command* selectedObstacle;
	Command* selectedGoal;
	bool started;
};
#endif
