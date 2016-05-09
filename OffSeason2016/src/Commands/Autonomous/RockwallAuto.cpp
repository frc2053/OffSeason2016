#include "RockwallAuto.h"
#include "DriveCommandAuto.h"
#include "../Shooter/ShooterWheels.h"

RockwallAuto::RockwallAuto()
{
	AddParallel(new DriveCommandAuto(0, -1, 0, 2.4, 0));
	AddSequential(new ShooterWheels(-1200, 2));
}
