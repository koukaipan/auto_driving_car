enum MOTOR_MODE {
	MOTOR_STOP,
	MOTOR_FORWARD,
	MOTOR_BACKWARD
};

#define LEFT_MOTOR	0
#define RIGHT_MOTOR	1

#define MAX_SPEED	255
#define NR_MOTOR	2
const int motor_pin[NR_MOTOR][2] = {{5,6},{10,11}};

void setup()	
{
	int i, j;

	for (i=0; i<NR_MOTOR; i++)
		for (j=0; j<2; j++)
			pinMode(motor_pin[i][j], OUTPUT);
}

/* 
   Input for motor
 IN1	IN2	Action
 LOW	LOW	Motor Stop
 HIGH	LOW	Motor moves forward	
 LOW	HIGH	Motor moves backward
 HIGH	HIGH	Motor Stop
*/
void run_motor(int nr_motor, int mode, int speed)
{
	switch (mode) {
	case MOTOR_STOP:
		analogWrite(motor_pin[nr_motor][0], 0);
		analogWrite(motor_pin[nr_motor][1], 0);
		break;
	case MOTOR_FORWARD:
		analogWrite(motor_pin[nr_motor][0], speed);
		analogWrite(motor_pin[nr_motor][1], 0);
		break;
	case MOTOR_BACKWARD:
		analogWrite(motor_pin[nr_motor][0], 0);
		analogWrite(motor_pin[nr_motor][1], speed);
		break;
	default:
		break;
	}
}

void forward()
{
	run_motor(LEFT_MOTOR, MOTOR_FORWARD, MAX_SPEED);
	run_motor(RIGHT_MOTOR, MOTOR_FORWARD, MAX_SPEED);
}

void backward()
{
	run_motor(LEFT_MOTOR, MOTOR_BACKWARD, MAX_SPEED);
	run_motor(RIGHT_MOTOR, MOTOR_BACKWARD, MAX_SPEED);
}

void right()
{
	run_motor(LEFT_MOTOR, MOTOR_FORWARD, MAX_SPEED);
	run_motor(RIGHT_MOTOR, MOTOR_STOP, 0);
}

void left()
{
	run_motor(LEFT_MOTOR, MOTOR_STOP, 0);
	run_motor(RIGHT_MOTOR, MOTOR_FORWARD, MAX_SPEED);
}

void motor_stop()
{
	run_motor(LEFT_MOTOR, MOTOR_STOP, 255);
	run_motor(RIGHT_MOTOR, MOTOR_STOP, 255);
}

void self_test()
{
	forward();
	delay(1000);
	motor_stop();
	delay(500);
	
	backward();
	delay(1000);
	motor_stop();
	delay(500);
	
	right();
	delay(1000);
	motor_stop();
	delay(500);
	
	left();
	delay(1000);
	motor_stop();
	delay(500);
}

void loop()
{
	self_test();
	delay(5000);
}
