#define PIN_R 2
#define PIN_G 3
#define PIN_B 4

void setup() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
}

void setColor(int r, int g, int b) {
  analogWrite(PIN_R, r);
  analogWrite(PIN_G, g);
  analogWrite(PIN_B, b);
}

void loop() {
  setColor(255, 0, 0); delay(1000);   // Red
  setColor(0, 255, 0); delay(1000);   // Green
  setColor(0, 0, 255); delay(1000);   // Blue
  setColor(255, 255, 0); delay(1000); // Yellow
  setColor(0, 255, 255); delay(1000); // Cyan
  setColor(255, 0, 255); delay(1000); // Magenta
  setColor(0, 0, 0); delay(1000);     // OFF
}
