int Relay =2; // Digital Pin D5

void setup() {
  Serial.begin(115200);
  pinMode(Relay,OUTPUT); //declare Relay as output
}

void loop() {
  digitalWrite(Relay, HIGH);
  delay(5000);
  digitalWrite(Relay, LOW);
  delay(5000);
}
