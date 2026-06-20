


#include <LiquidCrystal_I2C.h>
#include <Servo.h>
Servo s;
LiquidCrystal_I2C lcd(0x27, 20, 4);

int led_pin=11;
int servo_pin=5;
int btn=6;
bool ledstate=HIGH;
bool laststate=HIGH;
void start();
unsigned long prev=0;
void setup(){
  s.attach(5);
  s.write(0);
  pinMode(11,OUTPUT);
  pinMode(6,INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("press to start");
  }

void loop(){
  digitalWrite(led_pin,(ledstate) ? LOW:HIGH );
 bool state=digitalRead(btn);
  if(laststate==HIGH&&state==LOW){
    digitalWrite(led_pin,ledstate);
    start();
    ledstate=!ledstate;
  }
  laststate=state;
  
}
void start(){
  unsigned long now=millis();
  for(int i=0;i<=180;i++){
    
      lcd.clear();
      s.write(i);
      lcd.setCursor(0,0);
      lcd.print(i);
      delay(100);}

  for(int i=180;i>=0;i--){
    
      lcd.clear();
      s.write(i);
      lcd.setCursor(0,0);
      lcd.print(i);
      delay(100);
    }

}