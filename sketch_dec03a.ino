//https://www.arduinoforbeginners.com/hc-sr501/

//https://www.youtube.com/watch?v=ZC_sEW3_694
//w/o micrpro, ~six delay to reclamitize

int ledPin_1 = 8;
int ledPin_2 = 9;
int ledPin_3 = 10;
int ledPin_4 = 11;
int ledPin_5 = 12;

int inputPin_1 = 2;

int pirState = LOW;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin_1, OUTPUT);
  pinMode(inputPin_1, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(inputPin_1);

  if(val == HIGH) {
    Serial.println("motion detected");
    if(pirState == HIGH) {
      Serial.println("motion detected again");
      digitalWrite(ledPin_1, LOW);
      delay(500);
      digitalWrite(ledPin_1, HIGH);
      delay(500);
    }   
    
    Serial.println("motion established?");
    digitalWrite(ledPin_1, HIGH);
    delay(500);
    pirState = HIGH;
  } else {
    if(pirState == HIGH) {
      //just got out of detection; keep the LED high during reclimatize for 5 seconds; then power off LED
      digitalWrite(ledPin_1, HIGH);
      delay(5000);
    }
    digitalWrite(ledPin_1, LOW);
    pirState = LOW;
  }
}
