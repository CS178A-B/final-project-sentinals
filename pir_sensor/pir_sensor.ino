//https://www.arduinoforbeginners.com/hc-sr501/

//https://www.youtube.com/watch?v=ZC_sEW3_694
//w/o micrpro, ~six-second delay to reclamitize

int ledPin_1 = 8;
int ledPin_2 = 9;
int ledPin_3 = 10;

int inputPin_1 = 2;
int inputPin_2 = 3;
int inputPin_3 = 4;

int pirState_1 = LOW;
int pirState_2 = LOW;
int pirState_3 = LOW;

int val_1 = 0;
int val_2 = 0;
int val_3 = 0;

//const uint32_t delay = 5000; //5 seconds

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  pinMode(ledPin_3, OUTPUT);
  
  pinMode(inputPin_1, INPUT);
  pinMode(inputPin_2, INPUT);
  pinMode(inputPin_3, INPUT);

  Serial.begin(9600);
}

//'bool reset = false' is an arg special case when reset button is pressed; optional
/* void sensor_1() {
  static enum {START, WAIT, DETECT, DELAY};
  switch(state) {
    case START:
    default:
  }

  switch(state) {
    case START:
  }
} */

void loop() {
  // put your main code here, to run repeatedly:
  val_1 = digitalRead(inputPin_1);
  val_2 = digitalRead(inputPin_2);
  val_3 = digitalRead(inputPin_3);

  if(val_1 == HIGH) {
    Serial.println("motion detected");
    /* if(pirState == LOW) {
      Serial.println("motion detected again");
      digitalWrite(ledPin_1, LOW);
      delay(250);
      digitalWrite(ledPin_1, HIGH);
      delay(250);
    } */   
    
    Serial.println("motion established?");
    digitalWrite(ledPin_1, HIGH);
    //delay(250);
    pirState_1 = HIGH;
  } else {
    if(pirState_1 == HIGH) {
      //just got out of detection; keep the LED high during reclimatize for 5 seconds; then power off LED
      digitalWrite(ledPin_1, HIGH);
      delay(5000);
    }
    digitalWrite(ledPin_1, LOW);
    pirState_1 = LOW;
  }
  
   if(val_2 == HIGH) {
    Serial.println("motion detected");
    
    Serial.println("motion established?");
    digitalWrite(ledPin_2, HIGH);
    //delay(250);
    pirState_2 = HIGH;
  } else {
    if(pirState_2 == HIGH) {
      //just got out of detection; keep the LED high during reclimatize for 5 seconds; then power off LED
      digitalWrite(ledPin_2, HIGH);
      delay(5000);
    }
    digitalWrite(ledPin_2, LOW);
    pirState_2 = LOW;
  }
  
  if(val_3 == HIGH) {
    Serial.println("motion detected");
    //if (pirState == LOW) {
    //  Serial.println("motion detected again");
    //  digitalWrite(ledPin_1, LOW);
    //  delay(250);
    //  digitalWrite(ledPin_1, HIGH);
    //  delay(250);
    //}  
    
    Serial.println("motion established?");
    digitalWrite(ledPin_3, HIGH);
    //delay(250);
    pirState_3 = HIGH;
  } else {
    if(pirState_3 == HIGH) {
      //just got out of detection; keep the LED high during reclimatize for 5 seconds; then power off LED
      digitalWrite(ledPin_3, HIGH);
      delay(5000);
    }
    digitalWrite(ledPin_3, LOW);
    pirState_3 = LOW;
  } 
}