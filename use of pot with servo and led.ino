// this is to demonstrate use of potentiometer and pwm, it will start after pressing the button.

/* connections:-
push buttton to 7
servo pwm pin 11
pot analog pin A0
led anode pin to pwm 6 */



#include<Servo.h>
Servo s;

bool laststate=HIGH;
bool sweep_state=false;
void setup(){
  s.attach(11);
  pinMode(7,INPUT_PULLUP);
  pinMode(6,OUTPUT);
}

void loop(){
  bool state=digitalRead(7);
  if(laststate==HIGH&&state==LOW){
    sweep_state=!sweep_state;
  }
  laststate=state;
  if(sweep_state){
  int pot_val=analogRead(A0);
  // map(value,fromlow,fromhigh,tolow,tohigh)
  int brightness=map(pot_val,0,1023,0,255);
  int angle=map(pot_val,0,1023,0,180);
  analogWrite(6,brightness);
  s.write(angle);}
}