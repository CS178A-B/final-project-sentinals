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
void sm_sensor1(bool reset = false) {
  static enum {START, WAIT, DETECT, DELAY} state = START;

  switch(state) {
    case START: { 
      digitalWrite(ledPin_1, LOW);
      state = WAIT;
      break;
    }
    case WAIT: {
      val_1 = digitalRead(inputPin_1);
      if (val_1 == HIGH) {
        state = DETECT;
      } else {
        state = WAIT;
      }
      break;
    }
    case DETECT: {
      digitalWrite(ledPin_1, HIGH);
      state = DELAY;
      break;
    }
    case DELAY: {
      delay(5000);
      state = WAIT;
      digitalWrite(ledPin_1, LOW);
      break;
    }
    default:
      state = START;
      break;
  }    
}

void sm_sensor2(bool reset = false) {
  static enum {START, WAIT, DETECT, DELAY} state = START;

  switch(state) {
    case START: { 
      digitalWrite(ledPin_2, LOW);
      state = WAIT;
      break;
    }
    case WAIT: {
      val_2 = digitalRead(inputPin_2);
      if (val_2 == HIGH) {
        state = DETECT;
      } else {
        state = WAIT;
      }
      break;
    }
    case DETECT: {
      digitalWrite(ledPin_2, HIGH);
      state = DELAY;
      break;
    }
    case DELAY: {
      delay(5000);
      state = WAIT;
      digitalWrite(ledPin_2, LOW);
      break;
    }
    default:
      state = START;
      break;
  }    
}

void sm_sensor3(bool reset = false) {
  static enum {START, WAIT, DETECT, DELAY} state = START;

  switch(state) {
    case START: { 
      digitalWrite(ledPin_3, LOW);
      state = WAIT;
      break;
    }
    case WAIT: {
      val_3 = digitalRead(inputPin_3);
      if (val_3 == HIGH) {
        state = DETECT;
      } else {
        state = WAIT;
      }
      break;
    }
    case DETECT: {
      digitalWrite(ledPin_3, HIGH);
      state = DELAY;
      break;
    }
    case DELAY: {
      delay(5000);
      state = WAIT;
      digitalWrite(ledPin_3, LOW);
      break;
    }
    default:
      state = START;
      break;
  }    
}

void loop() {
  // put your main code here, to run repeatedly:
  sm_sensor1();
  sm_sensor2();
  sm_sensor3();
}