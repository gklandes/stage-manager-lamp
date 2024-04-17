// script is intended to be used on an ATTiny85
const int redPin = 0;
const int whitePin = 1;
const int levelPin = A1;
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(whitePin, OUTPUT);
}
void loop() {
  int levelVal = map(analogRead(levelPin), 0, 1023, 0, 510);
  int rVal = getRedVal(levelVal);
  int wVal = getWhiteVal(levelVal);
  analogWrite(redPin, rVal);
  analogWrite(whitePin, wVal);
  delay(1);
}
int getRedVal(int raw) {
  if (raw < 255) return raw;
  else return max(510 - raw, 0);
}
int getWhiteVal(int raw) {
  raw = raw - 255;
  return max(raw, 0);
}
