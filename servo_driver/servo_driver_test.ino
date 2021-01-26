#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

//code based on following tutorial: https://www.youtube.com/watch?v=F1jOo3ScQB8

const int BUTTON1 = 2;
const int BUTTON2 = 3;
const int BUTTON3 = 4;
const int BUTTON4 = 5;

int button1, button2, button3, button4;
int dim_val = 64;
int dim_val1 = 64;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(1600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(LED_BUILTIN, HIGH);
  //digitalRead: high = press; low = not press
  button1 = digitalRead(BUTTON1);
  button2 = digitalRead(BUTTON2);
  button3 = digitalRead(BUTTON3);
  button4 = digitalRead(BUTTON4);

  if(button1 == HIGH ) {
    if(dim_val < 2048) {
      dim_val *= 2;
      delay(300);
    } else {
      dim_val = dim_val;
    }
  }
  if(button2 == HIGH) {
    if(dim_val > 64) {
      dim_val /= 2;
      delay(300);
    } else {
      dim_val = dim_val;
    }
  }

  if(button3 == HIGH ) {
    if(dim_val1 < 2048) {
      dim_val1 *= 2;
      delay(300);
    } else {
      dim_val1 = dim_val1;
    }
  }
  if(button4 == HIGH) {
    if(dim_val1 > 64) {
      dim_val1 /= 2;
      delay(300);
    } else {
      dim_val1 = dim_val1;
    }
  }
  pwm.setPWM(1,0,dim_val);
  pwm.setPWM(5,0,dim_val1);
  /*pwm.setPWM(5,0,4096);
  delay(500);
  //digitalWrite(LED_BUILTIN, LOW);
  pwm.setPWM(1,0,4096);
  pwm.setPWM(5,4096,0);
  delay(500); */
  /* int i = 0;
  while (i < 3072) {
    pwm.setPWM(1, 0, i);
    pwm.setPWM(5, 0, i);
    //delay(10);
    i += 1;
  } */
  /* delay(500);
  while (i > 0) { 
    pwm.setPWM(0, i, i - 1);
    delay(500);
    i -= 1;
  } */
}
