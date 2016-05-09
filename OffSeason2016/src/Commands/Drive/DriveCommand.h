#ifndef DriveCommand_H
#define DriveCommand_H

#include "Commands/Command.h"
#include "../../Robot.h"

class DriveCommand: public Command
{
public:
	DriveCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	void SetAngleWithButton();
	void RotateCommand();
	void CheckRotateOverride();
	void CallToMecanumDrive();

	float xAxis;
	float yAxis;
	float rotAxis;
	float adjustedYaw;
	bool isRotDone;
	float setAngle;
	float setSpeed;
	float finalAutoRot;
	bool buttonAPressed;
	bool buttonBPressed;
	bool buttonXPressed;
	bool buttonYPressed;
};

#endif
