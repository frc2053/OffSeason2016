#include "LedSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/Leds/SetLeds.h"

LedSubsystem::LedSubsystem() : Subsystem("LEDSubsystem")
{
	redLed = RobotMap::ledSubsystemRedLED;
	greenLed = RobotMap::ledSubsystemGreenLED;
	blueLed = RobotMap::ledSubsystemBlueLED;
}

void LedSubsystem::InitDefaultCommand()
{
}

void LedSubsystem::SetRedLED(float red)
{
	redLed->DisablePWM();
	redLed->EnablePWM(red);
}

void LedSubsystem::SetGreenLED(float green)
{
	greenLed->DisablePWM();
	greenLed->EnablePWM(green);
}

void LedSubsystem::SetBlueLED(float blue)
{
	blueLed->DisablePWM();
	blueLed->EnablePWM(blue);
}
