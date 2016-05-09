#ifndef RotateFromAngle_H
#define RotateFromAngle_H

#include "Commands/CommandGroup.h"
#include "../../Robot.h"

class RotateFromAngle: public CommandGroup
{
public:
	RotateFromAngle(float offset);
};

#endif
