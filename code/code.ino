#include <Servo.h>
#define SERVO_1_PIN 9
#define SERVO_2_PIN 11
#define MIN_ANGLE 15
#define MAX_ANGLE 90
int angle1,angle2,angle3;
int JOY[]{A0,A1};
Servo servoA;
Servo servoB;
void setup(){
  Serial.begin(9600);
  servoA.attach(SERVO_1_PIN);
  servoB.attach(SERVO_2_PIN);
  for(int i=0;i<2;i++){
    pinMode(JOY[i],INPUT);
  }
}
void loop(){
  angle1=map(analogRead(JOY[0]), 505, 1020, MIN_ANGLE,MAX_ANGLE);
  angle2=map(analogRead(JOY[1]), 505, 1020, MIN_ANGLE,MAX_ANGLE);
  angle3=map(analogRead(JOY[1]), 445, 0, MIN_ANGLE,MAX_ANGLE);
 // Serial.println(analogRead(JOY[1]));
  if(angle1<MIN_ANGLE){
    angle1=MIN_ANGLE;
  }else if(angle1>MAX_ANGLE){
    angle1=MAX_ANGLE;
  }
   if(angle2<MIN_ANGLE){
    angle2=MIN_ANGLE;
  }else if(angle2>MAX_ANGLE){
    angle2=MAX_ANGLE;
  }
   if(angle3<MIN_ANGLE){
    angle3=MIN_ANGLE;
  }else if(angle3>MAX_ANGLE){
    angle3=MAX_ANGLE;
  }
  if(angle1>MIN_ANGLE+2){
    servoA.write(angle1);
    servoB.write(angle1);
    Serial.println("MOVE FORWARD");
  }else if(angle2>MIN_ANGLE+2){
    Serial.println("LEFT");
    servoA.write(angle2);
    servoB.write(MIN_ANGLE);
  }
  else if(angle3>MIN_ANGLE+2){
    Serial.println("RIGHT");
    servoB.write(angle3);
    servoA.write(MIN_ANGLE);
  }
  
}
