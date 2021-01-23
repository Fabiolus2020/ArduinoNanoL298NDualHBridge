/*  
  L298N Motor Control Demonstration with 2 Potentiometers
  L298N-Motor-Control-Demo-2pots.ino
  Demonstrates use of 2 potentiometers with Arduino and L298N Motor Controller
  
  DroneBot Workshop 2017
  http://dronebotworkshop.com
*/
  

// Motor A

int enA = 3;
int in1 = 5;
int in2 = 4;

// Speed control potentiometers

int SpeedControl = A0;  



// Motor Speed Values - Start at zero

int MotorSpeed = 0;


void setup()

{

  // Set all the motor control pins to outputs

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);  
   
}

void loop() {
  
  // Set Motor A forward

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);


  
  // Read the values from the potentiometers
    
  MotorSpeed = analogRead(SpeedControl); 

  
  // Convert to range of 0-255
  
  MotorSpeed = map(MotorSpeed, 0, 1023, 0, 255);

  
  // Adjust to prevent "buzzing" at very low speed
  
  if (MotorSpeed < 8)MotorSpeed = 0;
        
  
  // Set the motor speeds
  
  analogWrite(enA, MotorSpeed);

  
}
