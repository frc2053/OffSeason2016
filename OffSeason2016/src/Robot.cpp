#include "Robot.h"

//auto chooser includes
#include "Commands/Autonomous/DoNothingAuto.h"
#include "Commands/Autonomous/MoatAuto.h"
#include "Commands/Autonomous/RampartsAuto.h"
#include "Commands/Autonomous/RockwallAuto.h"
#include "Commands/Autonomous/RoughTerrainAuto.h"

std::unique_ptr<OI> Robot::oi;
std::shared_ptr<DrivebaseSubsystem> Robot::drivebaseSubsystem;
std::shared_ptr<ShooterSubsystem> Robot::shooterSubsystem;
std::shared_ptr<IntakeSubsystem> Robot::intakeSubsystem;
std::shared_ptr<ClimberSubsystem> Robot::climberSubsystem;
std::shared_ptr<DefenseSubsystem> Robot::defenseSubsystem;
std::shared_ptr<LedSubsystem> Robot::ledSubsystem;

void Robot::RobotInit() {
	std::cout << "ROBOT INIT!" << std::endl;
	RobotMap::init();

	drivebaseSubsystem.reset(new DrivebaseSubsystem());
	shooterSubsystem.reset(new ShooterSubsystem());
	intakeSubsystem.reset(new IntakeSubsystem());
	climberSubsystem.reset(new ClimberSubsystem());
	defenseSubsystem.reset(new DefenseSubsystem());
	ledSubsystem.reset(new LedSubsystem());
	oi.reset(new OI());

	std::cout << "DONE INITING SUBSYSTEMS!" << std::endl;

	Robot::drivebaseSubsystem->ZeroYaw();

	chooserObstacle = new SendableChooser();
	chooserGoal = new SendableChooser();

	chooserObstacle->AddDefault("Rockwall", new RockwallAuto());
	chooserObstacle->AddObject("Moat", new MoatAuto());
	chooserObstacle->AddObject("Ramparts", new RampartsAuto());
	chooserObstacle->AddObject("Rough Terrain", new RoughTerrainAuto());
	chooserObstacle->AddObject("Do Nothing", new DoNothingAuto(5));

	SmartDashboard::PutData("Obstacle Chooser", chooserObstacle);
}

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	started = false;
	selectedObstacle = (Command*) chooserObstacle->GetSelected();
	selectedGoal = (Command*) chooserGoal->GetSelected();
	selectedObstacle->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	if(selectedObstacle->IsRunning() == false && started == false) {
		selectedGoal->Start();
		started = true;
	}
}

void Robot::TeleopInit() {
	if (selectedObstacle != nullptr) {
		selectedObstacle->Cancel();
	}
	if (selectedGoal != nullptr) {
		selectedGoal->Cancel();
	}
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("Amperage on Frontleft", RobotMap::pdp->GetCurrent(3));
}

void Robot::TestPeriodic() {
}

START_ROBOT_CLASS(Robot);
