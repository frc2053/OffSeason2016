#include "TestAuto.h"
#include "../Shooter/ShooterWheels.h"
#include "../Shooter/ShooterSolenoid.h"
#include "AlignCenter.h"
#include "AlignParallel.h"
#include "DriveCommandAuto.h"

TestAuto::TestAuto()
{
	AddSequential(new AlignParallel(0, 110));
	AddSequential(new AlignCenter());
	AddSequential(new RotateToAngleAuto(0, 0, 0, 1, 0));
	AddSequential(new ShooterControl(6000, 4));
	AddSequential(new ShooterSolenoidControl());
}