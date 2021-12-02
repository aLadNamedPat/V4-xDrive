#pragma config(Sensor, in2,    Yaw,            sensorGyro)
#pragma config(Sensor, dgtl3,  rightTopEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  rightBottomEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  leftBottomEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  leftTopEncoder, sensorQuadEncoder)
#pragma config(Motor,  port4,           leftFront,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightFront,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           leftBack,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rightBack,     tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//3.25 diameter wheels
float wheelDiameter = 3.25;
void encoderDrive(float distanceInFeet, float speed, float degrees){
	SensorValue[leftTopEncoder] = 0;
	SensorValue[leftBottomEncoder] = 0;
	float radians = degreesToRadians(degrees);
	//Converts based on a 45 degree shifted axis
	float converted_radians = (radians - PI / 4);
	// Change motor power based on power
	// X motor power
	float motorXspeed = speed * cos(converted_radians);
	// Y motor power
	float motorYspeed = speed * sin(converted_radians);
	// Finds distance needed to be traveled in X-axis
	float xDistance = distanceInFeet * cos(converted_radians);
	// Finds distance needed to be traveled in Y-axis
	float yDistance = distanceInFeet * sin(converted_radians);
	// Converts distances needed into degree turns for robot motors
	float xDegrees = xDistance * 4320 / PI / wheelDiameter;
	float yDegrees = yDistance * 4320 / PI / wheelDiameter;
	//Different cases of different degrees (positive and negative)
	//Purpose is to account for the case such that one motor is unable to turn.
	//This way, the robot will not overrun even when such a case is true
	if (xDegrees > 0 && yDegrees > 0){
		while((-SensorValue[leftTopEncoder] + SensorValue[leftBottomEncoder])< xDegrees + yDegrees){
			motor[leftFront] = motorXspeed;
			motor[rightFront] = motorYspeed;
			motor[leftBack] =  motorYspeed;
			motor[rightBack] = motorXspeed;
			clearLCDLine(0);
			clearLCDLine(1);
			displayNextLCDNumber(sensorValue[leftTopEncoder], 0);
			displayNextLCDNumber(sensorValue[leftBottomEncoder], 1);
		}
	}
	else if (xDegrees > 0 && yDegrees <= 0){
		while(SensorValue[leftTopEncoder] > yDegrees){
			motor[leftFront] = motorXspeed;
			motor[rightFront] = motorYspeed;
			motor[leftBack] =  motorYspeed;
			motor[rightBack] = motorXspeed;
			clearLCDLine(0);
			clearLCDLine(1);
			displayNextLCDNumber(sensorValue[leftTopEncoder], 0);
			displayNextLCDNumber(sensorValue[leftBottomEncoder], 1);
		}
	}
	//Make sure to adjust code so that yDegrees and leftBottomEncoder match
	else if (xDegrees < 0 && yDegrees >= 0) {
		while(SensorValue[leftBottomEncoder] < yDegrees){
			motor[leftFront] = motorXspeed;
			motor[rightFront] = motorYspeed;
			motor[leftBack] =  motorYspeed;
			motor[rightBack] = motorXspeed;
			clearLCDLine(0);
			clearLCDLine(1);
			displayNextLCDNumber(sensorValue[leftTopEncoder], 0);
			displayNextLCDNumber(sensorValue[leftBottomEncoder], 1);
		}
	}
	else {
		while((-SensorValue[leftTopEncoder] + SensorValue[leftBottomEncoder]) > xDegrees + yDegrees){
			motor[leftFront] = motorXspeed;
			motor[rightFront] = motorYspeed;
			motor[leftBack] =  motorYspeed;
			motor[rightBack] = motorXspeed;
			clearLCDLine(0);
			clearLCDLine(1);
			displayNextLCDNumber(sensorValue[leftTopEncoder], 0);
			displayNextLCDNumber(sensorValue[leftBottomEncoder], 1);
		}
	}
	motor[leftFront] = 0;
	motor[rightFront] = 0;
	motor[leftBack] =  0;
	motor[rightBack] = 0;
}

task main()
{
	//90 degrees is 90 degrees to the right of the front side
	//wait1Msec(1000);

	//timeStrafe(90, 127, 1800);
	//Stop(1000);
	//timeStrafe(90, 127, 2350);
	//Stop(1000);
	//timeStrafe(90, 127, 3000);
	//Stop(1000);
	//timeStrafe(0, 127, 6300);
	//turn(-20, 200);
	//Stop(1000);
	//timeStrafe(270, 127, 2500);
	//Stop(1000);
	//timeStrafe(270, 127, 5200);
	//Stop(1000);
	//timeStrafe(132, 127, 12000);
	//Stop(1000);
	//==================================
	//wait(1);

	//encoderDrive(1.75, 40, 90);
	//wait(0.5);
	//turn90Degrees(false ,25);
	//wait(0.5);
	//encoderDrive(3, 40, 90);
	//wait(0.5);
	//turn90Degrees(true ,25);
	//wait(0.5);
	//encoderDrive(1.85,40,90);
	//wait(0.5);
	//turn90Degrees(true ,25);
	//wait(0.5);
	//encoderDrive(1.20, 40,90);
	//==================================
	//==================================
	wait(1);
	encoderDrive(6, 70, 90);
	wait(1);
	encoderDrive(5.5, 70, 180);
	wait(0.5);
	encoderDrive(6.2, 70, 270);
	wait(0.5);
	//encoderDrive(5.2, 70, 90);
	//wait(0.5);
	encoderDrive(1.5, 70, 360);
	wait(0.5);
	encoderDrive(2.5, 70, 90);
	wait(0.5);
	encoderDrive(1.5, 70, 360);
	wait(0.5);
	encoderDrive(2.5, 70, 270);
	wait(0.5);
	encoderDrive(1.5, 70, 360);
	//==================================

	//==================================
	//gyroTest();
	//==================================
	//accelerationStrafe(70, 100, 0.5, 3);
	//Stop(1000);
	//encoderTest();
}
