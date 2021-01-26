#include <Servo.h>
#include <NewPing.h>

//#define max_dist = 450 //4.5 meters

int ledPin_1 = 11;
int ledPin_2 = 12;
int ledPin_3 = 13;

int inputPin_1 = 2; //right
int inputPin_2 = 3;
int inputPin_3 = 4; //left

int val_1 = 0;
int val_2 = 0;
int val_3 = 0;

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  pinMode(ledPin_3, OUTPUT);
  
  pinMode(inputPin_1, INPUT);
  pinMode(inputPin_2, INPUT);
  pinMode(inputPin_3, INPUT);

  myservo.attach(8);
  myservo.write(90);

  Serial.begin(9600);

}

void ultrasonic_sm(bool reset = false) {
  static enum{INIT, SCAN, SET_L, SET_C, SET_R} state = INIT;

  //actions
  switch(state) {
    case INIT: {
      val_1 = 0;
      val_2 = 0;
      val_3 = 0;
      
      myservo.write(90);
      break;
    }
    case SCAN: {
      val_1 = 0;
      val_2 = 0;
      val_3 = 0;
      
      val_1 = digitalRead(inputPin_1);
      val_2 = digitalRead(inputPin_2);
      val_3 = digitalRead(inputPin_3);

      digitalWrite(ledPin_1, val_1);
      digitalWrite(ledPin_2, val_2);
      digitalWrite(ledPin_3, val_3);
      break;
    }
    case SET_L: {
      myservo.write(175);
      delay(3000);
      break;
    }
    case SET_C: {
      myservo.write(90);
      delay(3000);
      break;
    }
    case SET_R: {
      myservo.write(0);
      delay(3000);
      break;
    }
    default: {
      break;
    }
  }

  //transitions
  switch(state) {
    case INIT: {
      state = SCAN;
      break;
    }
    case SCAN: {
      if ( (val_1 && val_2 && !val_3) || (val_1 && !val_2 && !val_3) ) {
        state = SET_R;
      } else if ( (!val_1 && val_2 && val_3) || (!val_1 && !val_2 && val_3) ) {
        state = SET_L;
      } else if ( (!val_1 && val_2 && !val_3) || (!val_1 && !val_2 && !val_3) ) {
        state = SET_C;
      } else {
        state = SET_C;
      }
      break;
    }
    case SET_L: {
      state = SCAN;
      break;
    }
    case SET_C: {
      state = SCAN;
      break;
    }
    case SET_R: {
      state = SCAN;
      break;
    }
    default: {
      state = INIT;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  ultrasonic_sm();
}