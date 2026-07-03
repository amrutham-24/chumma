int redPin = 25;
int greenPin = 26;
int bluePin = 27;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  digitalWrite(redPin, HIGH);
  delay(1000);
  digitalWrite(redPin, LOW);

  digitalWrite(greenPin, HIGH);
  delay(1000);
  digitalWrite(greenPin, LOW);

  digitalWrite(bluePin, HIGH);
  delay(1000);
  digitalWrite(bluePin, LOW);
}
