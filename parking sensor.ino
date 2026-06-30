const int trigPin = 7;
const int echoPin = 4;
const int redPin = 13;
const int bluePin = 12;
const int greenPin = 11;
const int buzzerPin = 2;

unsigned long previousBeepTime = 0;
bool beepState = false;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, LOW);
  digitalWrite(bluePin, LOW);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.0343 / 2;

  if (distance > 0 && distance < 100) {
    setColor(redPin);
    handleBeep(mapDistanceToInterval(distance));
  } else if (distance >= 100 && distance < 200) {
    setColor(bluePin);
    stopBuzzer();
  } else if (distance >= 200) {
    setColor(greenPin);
    stopBuzzer();
  } else {
    setColor(-1);
    stopBuzzer();
  }
}

void setColor(int color) {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  if (color == redPin) digitalWrite(redPin, HIGH);
  else if (color == greenPin) digitalWrite(greenPin, HIGH);
  else if (color == bluePin) digitalWrite(bluePin, HIGH);
}

int mapDistanceToInterval(int cm) {
  int interval = map(cm, 2, 100, 50, 500);
  return constrain(interval, 30, 1000);
}

void handleBeep(int interval) {
  unsigned long now = millis();
  if (now - previousBeepTime >= interval) {
    previousBeepTime = now;
    beepState = !beepState;
    if (beepState) tone(buzzerPin, 1000);
    else noTone(buzzerPin);
  }
}

void stopBuzzer() {
  noTone(buzzerPin);
  beepState = false;
}