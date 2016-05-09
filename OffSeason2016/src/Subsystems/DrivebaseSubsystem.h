#ifndef DrivebaseSubsystem_H
#define DrivebaseSubsystem_H

#include "Commands/Subsystem.h"
#include "../Tigerdrive/Tigerdrive.h"
#include "WPILib.h"

class DrivebaseSubsystem: public Subsystem
{
private:
	std::shared_ptr<CANTalon> frontLeftTalon;
	std::shared_ptr<CANTalon> frontRightTalon;
	std::shared_ptr<CANTalon> backLeftTalon;
	std::shared_ptr<CANTalon> backRightTalon;
	std::shared_ptr<RobotDrive> robotDrive;
	std::shared_ptr<AHRS> robotImu;
	std::shared_ptr<TigerDrive> tigerDrive;

public:
	DrivebaseSubsystem();
	void InitDefaultCommand();
	void MecanumDrive(float x, float y, float rot, float gyro);
	float CalculateRotValue(float setAngle, float setSpeed);
	void IMU_YAWoffset(float offset);
	float GetAdjYaw();
	void GetAdjYaw(float offset);
	void SetAdjYaw(float offset);
	float GetImuYaw();
	bool GetIsRotDone();
	void SetIsRotDone(bool isDone);
	void SetIsRotDoneOverride(bool isDone);
	void SetTimesThroughLoop(int timeLoop);
	bool GetIsRotDoneOverride();
	bool IsAlignedX();
	bool IsAlignedY();
	void ZeroYaw();

	bool isAlignedX;
	bool isAlignedY;
	float calculatedOffset; //calculated for imu offset
	float yawOffset; //param
	float imuYaw; //return value for imuoffset
};

#endif
