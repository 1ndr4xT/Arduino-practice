/* CONNECTIONS:-
L298N DRIVER USED
ena pwm 3
IN1 7
IN2 8
button 2 and gnd
OUT1 AND OUT 2 connected to two terminals of dc motor
pot pin to A0 */

//in1 and in2 should have opposite bool value to rotate either direction



const int in1=7;
const int in2=8;
const int pwm=3;
const int btn=2;
bool btn_state=false;
bool laststate=HIGH;
bool fwd=true;
void setup(){
  pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(pwm,OUTPUT);
pinMode(2,INPUT_PULLUP);}



void loop(){
  bool state=digitalRead(btn);
  if(laststate==HIGH&&state==LOW){

    fwd=!fwd;
  }
  laststate=state;

  int pot_val=analogRead(A0);
  int speed=map(pot_val,0,1023,0,255);
  digitalWrite(in1,(fwd)? HIGH:LOW);
  digitalWrite(in2,(fwd)? LOW:HIGH);
  analogWrite(pwm,speed);
}