#include "MoatAuto.h"
#include "DriveCommandAuto.h"
#include "../Shooter/ShooterWheels.h"

MoatAuto::MoatAuto()
{
	AddParallel(new DriveCommandAuto(0, -.8, 0, 2.4, 0));
	AddSequential(new ShooterWheels(-1200, 2));
}
