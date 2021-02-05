/*
 * Fabiolus
 * 2020/07/04
 * the_fabiolous@hotmail.com
   This is a dual axis joystick skitch for Arduino.
   The position of joystick is read and displayed on serial monitor
*/
//Joystick Pins
int x_key = A1;
int y_key = A0;
int x_pos;
int y_pos;


//Motor Pins
int EN_A = 10;      //Enable pin for first motor
int IN1 = 4;       //control pin for first motor
int IN2 = 5;       //control pin for first motor
int IN3 = 6;        //control pin for second motor
int IN4 = 7;        //control pin for second motor
int EN_B = 3;      //Enable pin for second motor

//Initializing variables to store data
int motor_speed1 = 0;
int motor_speed2 = 0;


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(EN_A, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN_B, OUTPUT);

  //Initializng the joystick pins as input
  pinMode (x_key, INPUT) ;
  pinMode (y_key, INPUT) ;

}

void loop() {


  x_pos = analogRead (x_key) ;  //Reading the horizontal movement value
  y_pos = analogRead (y_key) ;  //Reading the vertical movement value

  if (x_pos < 460) {    //Rotating direction FORWARD BOTH MOTORS
    motor_speed1 = map(x_pos, 460, 0, 0, 255);   //Mapping the values to 0-255 to move the motor
    motor_speed2 = map(x_pos, 460, 0, 0, 255);   //Mapping the values to 0-255 to move the motor
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(EN_A, motor_speed1);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(EN_B, motor_speed2);
  }

  else if (x_pos > 525) {  //Rotating direction BACKWARD BOTH MOTORS
    motor_speed1 = map(x_pos, 525, 1023, 0, 255);   //Mapping the values to 0-255 to move the motor
    motor_speed2 = map(x_pos, 525, 1023, 0, 255);   //Mapping the values to 0-255 to move the motor
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(EN_A, motor_speed1);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(EN_B, motor_speed2);

  }






 else if (y_pos > 525) {    //Rotating direction FORWARD and BACKWARD BOTH MOTORS PUSHING JOYSTICK RIGHT
    motor_speed1 = map(y_pos, 525, 1023, 0, 255);   //Mapping the values to 0-255 to move the motor
    motor_speed2 = map(y_pos, 525, 1023, 0, 255);   //Mapping the values to 0-255 to move the motor
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(EN_A, motor_speed1);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(EN_B, motor_speed2);
  }

  else if (y_pos < 460) {    //Rotating direction FORWARD and BACKWARD BOTH MOTORS PUSHING JOYSTICK RIGHT
    motor_speed1 = map(y_pos, 460, 0, 0, 255);   //Mapping the values to 0-255 to move the motor
    motor_speed2 = map(y_pos, 460, 0, 0, 255);   //Mapping the values to 0-255 to move the motor
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(EN_A, motor_speed1);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(EN_B, motor_speed2);
  }

else 
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    motor_speed1 = 0;
    motor_speed2 = 0;
}
  //   // Adjust to prevent "buzzing" at very low speed

  if (motor_speed1 < 20)motor_speed1 = 0;
  if (motor_speed2 < 20)motor_speed2 = 0;


  //  Serial.print("X: ");
  //  Serial.print(x_pos); //print x

  //  Serial.print(" Y: ");
  //  Serial.println(y_pos);// print y

}
