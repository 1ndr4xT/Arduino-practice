/* connections:-
hc sr04 ultrasonic sensor used
trig(input) connected to 4
echo(output) to 7 */





const int echo_pin=7;
const int trig_pin=4;

void setup(){
  pinMode(echo_pin,INPUT);
  pinMode(trig_pin,OUTPUT);
  Serial.begin(9600);

}

void loop(){
  digitalWrite(trig_pin,LOW);
  delayMicroseconds(2); //set it to low for safety 
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin,LOW); //short pulse created

  long duration=pulseIn(echo_pin,HIGH);
  int distance = duration * 0.0343 / 2;      //formula
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);      //delay sometime for safe reaadings

}