#include "TestAuto.h"
#include "../Shooter/ShooterWheels.h"
#include "../Shooter/ShooterSolenoid.h"
#include "../Drive/AlignCenter.h"
#include "../Drive/AlignParallel.h"
#include "DriveCommandAuto.h"

TestAuto::TestAuto()
{
	AddSequential(new AlignParallel(0, 110));
	AddSequential(new AlignCenter());
	AddSequential(new DriveCommandAuto(0, 0, 0, 1, 0));
	AddSequential(new ShooterWheels(6000, 3, 0, 200));
	AddSequential(new ShooterSolenoid());
}
