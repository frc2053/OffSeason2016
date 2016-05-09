#include "RoughTerrainAuto.h"
#include "DriveCommandAuto.h"
#include "../Shooter/ShooterWheels.h"

RoughTerrainAuto::RoughTerrainAuto()
{
	AddParallel(new DriveCommandAuto(0, -.8, 0, 1.5, 0));
	AddSequential(new ShooterWheels(-1200, 2));
}
