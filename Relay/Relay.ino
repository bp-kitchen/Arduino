// NO <-> resistor <-> LED+ ... LED- <-> GND
// COM <-> 5V/12V
// D+ <-> 5V
// D- <-> GND
// IN1/2/3/4 <-> RELAY_PIN (Arduino)
// Check active high or low

int RELAY_PIN = 8;  // the Arduino pin, which connects to the IN pin of relay
int LED_PIN = 13;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(RELAY_PIN, HIGH);
  delay(1000);
  digitalWrite(RELAY_PIN, LOW);
  delay(1000);
}
