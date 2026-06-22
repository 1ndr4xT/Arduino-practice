


#include <LiquidCrystal_I2C.h>
#include <Servo.h>
Servo s;
LiquidCrystal_I2C lcd(0x27, 20, 4);

int angle=0;
int step=1;
bool sweep_state=false;
unsigned long prev=0;
bool laststate = HIGH;
void setup(){
  pinMode(6,INPUT_PULLUP);
  pinMode(11,OUTPUT);
  s.attach(5);
  s.write(0);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("press to start");
  
}

void loop(){
  bool state=digitalRead(6);
  if(laststate==HIGH&&state==LOW){
  sweep_state=!sweep_state;
  
}
laststate=state;
digitalWrite(11,(sweep_state) ? HIGH:LOW);
if(sweep_state){
 
    unsigned long now=millis();
   if(now-prev>=500 && angle<=180 && step==1){
    
    s.write(angle);
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print(angle);
    prev=now;
    angle++;
   }
   if(angle>180) step=0;
   if(now-prev>=500 && angle>=0 && step==0){
   lcd.clear();
    s.write(angle);
    lcd.setCursor(4,0);
    lcd.print(angle);
    prev=now;
    angle--;
   }
   if(angle<0) step=1;
}
}

