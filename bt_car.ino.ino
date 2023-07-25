
#include <AFMotor.h>
  

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
  
int val;
int Speeed = 255;
  
void setup()
{
  Serial.begin(9600); 
}
void loop(){
  if(Serial.available() > 0){
    val = Serial.read();
      
    Stop(); 
      
          if (val == 'F'){
          forward();
          }
  
          if (val == 'B'){
          back();
          }
  
          if (val == 'L'){
          left();
          }
  
          if (val == 'R'){
          right();
          }
          
          if (val == 'T'){
          Stop();
          }
  }
}
           
  
            
  
  
  
void forward()
{
  motor1.setSpeed(Speeed); 
  motor1.run(FORWARD); 
  motor2.setSpeed(Speeed); 
  motor2.run(FORWARD); 
  motor3.setSpeed(Speeed);
  motor3.run(FORWARD); 
  motor4.setSpeed(Speeed);
  motor4.run(FORWARD); 
}
  
void back()
{
  motor1.setSpeed(Speeed);
  motor1.run(BACKWARD); 
  motor2.setSpeed(Speeed); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(Speeed); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(Speeed); 
  motor4.run(BACKWARD); 
}
  
void left()
{
  motor1.setSpeed(Speeed); 
  motor1.run(BACKWARD);
  motor2.setSpeed(Speeed); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(Speeed);
  motor3.run(FORWARD);
  motor4.setSpeed(Speeed); 
  motor4.run(FORWARD);  
}
  
void right()
{
  motor1.setSpeed(Speeed); 
  motor1.run(FORWARD); 
  motor2.setSpeed(Speeed); 
  motor2.run(FORWARD); 
  motor3.setSpeed(Speeed); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(Speeed); 
  motor4.run(BACKWARD); 
}
  

  
void Stop()
{
  motor1.setSpeed(0); 
  motor1.run(RELEASE);
  motor2.setSpeed(0); 
  motor2.run(RELEASE);
  motor3.setSpeed(0); 
  motor3.run(RELEASE);
  motor4.setSpeed(0); 
  motor4.run(RELEASE); 
}