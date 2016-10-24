#include "Robot.h"

//auto chooser includes
#include "Commands/Autonomous/DoNothingAuto.h"
#include "Commands/Autonomous/MoatAuto.h"
#include "Commands/Autonomous/RampartsAuto.h"
#include "Commands/Autonomous/RockwallAuto.h"
#include "Commands/Autonomous/RoughTerrainAuto.h"
#include "Commands/Autonomous/CenterGoalAuto.h"
#include "Commands/Autonomous/RightGoalAuto.h"
#include "Commands/Autonomous/LeftGoalAuto.h"
#include "Commands/Autonomous/TestAuto.h"

#include "Commands/Leds/SetLeds.h"

std::unique_ptr<OI> Robot::oi;
std::shared_ptr<DrivebaseSubsystem> Robot::drivebaseSubsystem;
std::shared_ptr<ShooterSubsystem> Robot::shooterSubsystem;
std::shared_ptr<IntakeSubsystem> Robot::intakeSubsystem;
std::shared_ptr<ClimberSubsystem> Robot::climberSubsystem;
std::shared_ptr<DefenseSubsystem> Robot::defenseSubsystem;
std::shared_ptr<LedSubsystem> Robot::ledSubsystem;
std::shared_ptr<NetworkTable> Robot::netTable;

void Robot::RobotInit() {
	RobotMap::init();

	drivebaseSubsystem.reset(new DrivebaseSubsystem());
	shooterSubsystem.reset(new ShooterSubsystem());
	intakeSubsystem.reset(new IntakeSubsystem());
	climberSubsystem.reset(new ClimberSubsystem());
	defenseSubsystem.reset(new DefenseSubsystem());
	ledSubsystem.reset(new LedSubsystem());
	netTable = NetworkTable::GetTable("vision");
	oi.reset(new OI());

	Robot::drivebaseSubsystem->ZeroYaw();

	chooserObstacle = new SendableChooser();
	chooserGoal = new SendableChooser();

	chooserObstacle->AddDefault("Rockwall", new RockwallAuto());
	chooserObstacle->AddObject("Moat", new MoatAuto());
	chooserObstacle->AddObject("Ramparts", new RampartsAuto());
	chooserObstacle->AddObject("Rough Terrain", new RoughTerrainAuto());
	chooserObstacle->AddObject("Do Nothing", new DoNothingAuto(15));

	chooserGoal->AddDefault("Test Auto", new TestAuto());
	chooserGoal->AddObject("Center Goal Auto", new CenterGoalAuto());
	chooserGoal->AddObject("Right Goal Auto", new RightGoalAuto());
	chooserGoal->AddObject("Left Goal Auto", new LeftGoalAuto());
	chooserGoal->AddObject("Do Nothing", new DoNothingAuto(15));

	SmartDashboard::PutData("Obstacle Chooser", chooserObstacle);
	SmartDashboard::PutData("Goal Chooser", chooserGoal);
}

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	//opens latch at start of match
	Robot::climberSubsystem->SetLatchSolenoidReverse();

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
	Scheduler::GetInstance()->AddCommand(new SetLeds(1, 0, 1));
	if (selectedObstacle != nullptr) {
		selectedObstacle->Cancel();
	}
	if (selectedGoal != nullptr) {
		selectedGoal->Cancel();
	}
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	std::cout << "Distance: " << Robot::netTable->GetNumber("distance", 0.0) << std::endl;

	//check if climber is at top if true, close latch and set leds
	if(Robot::climberSubsystem->GetForwardLimitSwitch()) {
		Robot::climberSubsystem->SetLatchSolenoidForward();
		Scheduler::GetInstance()->AddCommand(new SetLeds(0, 1, 0));
	}
}

void Robot::TestPeriodic() {
}

START_ROBOT_CLASS(Robot);
