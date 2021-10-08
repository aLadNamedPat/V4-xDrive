#pragma config(Motor,  port4,           leftFront,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightFront,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           leftBack,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rightBack,     tmotorVex393_MC29, openLoop)


void Strafe(float degrees, float speed = 1,float time = 0)
{
	float radians = degreesToRadians(degrees);
	float converted_radians = (radians - PI / 4);
// Change motor power based on power
// X power for robot
	float motorXspeed = speed * cos(converted_radians);
	float motorYspeed = speed * sin(converted_radians);

	motor[leftFront] = motorXspeed;
	motor[rightFront] = motorYspeed;
	motor[leftBack] =  -motorYspeed;
	motor[rightBack] = -motorXspeed;
	wait1Msec(time);
}

task main()
{
Strafe((50), 50, 1000);
}
