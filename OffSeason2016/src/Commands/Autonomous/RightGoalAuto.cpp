#include "RightGoalAuto.h"
#include "DriveCommandAuto.h"
#include "../Drive/AlignParallel.h"
#include "../Shooter/ShooterWheels.h"
#include "../Shooter/ShooterSolenoid.h"

RightGoalAuto::RightGoalAuto()
{
	AddSequential(new DriveCommandAuto(0, -.8, 0, .5, 0)); //drive in rough direction of goal
	AddSequential(new DriveCommandAuto(-.8, 0, 0, 0.75, -45)); //slide to the right (one hop this time) a little and rotate to -45
	AddSequential(new AlignParallel(-45, 120)); //align 120 inches away from the goal
	AddSequential(new ShooterWheels(6000, 3, 0, 200);
	AddSequential(new ShooterSolenoid());
}