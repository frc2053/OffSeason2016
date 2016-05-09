#include "RampartsAuto.h"
#include "DriveCommandAuto.h"
#include "../Shooter/ShooterWheels.h"

RampartsAuto::RampartsAuto()
{
	AddParallel(new DriveCommandAuto(0, -1, 0, 2.9, 0));
	AddSequential(new ShooterWheels(-1200, 2));
}
