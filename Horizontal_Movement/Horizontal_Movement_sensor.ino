#include <Servo.h>

//input pins
const char c_pin_1 = A0; //controller pin 1
const char c_pin_2 = A1; //controller pin 2

const int ledLeft = 11;
const int ledRight = 12;

//sensor input
int inputPin_1 = 2; //right
int inputPin_2 = 3;
int inputPin_3 = 4; //left

//vars to store sensors reads
int val_1 = 0;
int val_2 = 0;
int val_3 = 0;

//sensor led pins
int ledPin_1 = 11;
int ledPin_2 = 12;
int ledPin_3 = 13;

//const byte c_pin_3 = A2; //controller pin 3
//const byte c_pin_4 = A3; //controller pin 4
//data variables
char x_left;  //checks if the motor moves left
char x_right; //checks if the motor moves right
short x_pos;
//output pins
const char h_pin = 5; //temp output pin for horizontal pin movement
Servo h_servo;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(c_pin_1, INPUT);
  pinMode(c_pin_2, INPUT);
  pinMode(ledLeft,INPUT);
  pinMode(ledRight,INPUT);

  //sensor setup
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  pinMode(ledPin_3, OUTPUT);
  
  pinMode(inputPin_1, INPUT);
  pinMode(inputPin_2, INPUT);
  pinMode(inputPin_3, INPUT);
  
  h_servo.attach(h_pin);
}


void SM_Read(bool reset = false)
{
  //States
  static enum {READ} state = READ;

  if(reset)
  {
    x_left = 0;
    x_right = 0;
  }

  //actions
  switch(state)
  {
    case READ:
    {
      //reset sensor bits before read
      val_1 = 0;
      val_2 = 0;
      val_3 = 0;

      x_left = digitalRead(c_pin_1);
      x_right = digitalRead(c_pin_2);

      //sensor reads
      val_1 = digitalRead(inputPin_1);
      val_2 = digitalRead(inputPin_2);
      val_3 = digitalRead(inputPin_3);

      break;
    }
    default:
    {
      x_left = 0;
      x_right = 0;

      val_1 = 0;
      val_2 = 0;
      val_3 = 0;

      break;
    }
  }
  //transitions
  switch(state)
  {
    case READ:
    {
      break;
    }
    default:
    {
      break;
    }
  }
}

//state machine for outputing horizontal motor movement
void SM_H_Motor(bool reset = false)
{
  //states
  static enum {START, STOP, SET_C, SET_L, SET_R, WAIT, LEFT, WAIT_LEFT, RIGHT, WAIT_RIGHT} state = START;
  const uint32_t MOTOR_DELAY = 90; //90 ms delay 
  static uint32_t h_Time = 0; //time for motor delay

  //on reset
  if(reset)
  {
    state=START;
  }
  //actions
  digitalWrite(ledLeft,x_left);
  digitalWrite(ledRight,x_right);

  //sensor read flags
  digitalWrite(ledPin_1, val_1);
  digitalWrite(ledPin_2, val_2);
  digitalWrite(ledPin_3, val_3);

  switch(state)
  {
    case START:
    {
      x_pos = 90;
      h_servo.write(x_pos);
      break;
    }
    case STOP:
    {
      break;
    }
    case SET_L: 
    {
      myservo.write(170);
      delay(3000);
      break;
    }
    case SET_C: 
    {
      myservo.write(90);
      delay(3000);
      break;
    }
    case SET_R: 
    {
      myservo.write(10);
      delay(3000);
      break;
    }
    case WAIT: 
    {
      break;
    }
    case LEFT:
    {
      if(x_pos <180)
      {
        x_pos += 1; 
      }
      h_servo.write(x_pos);
      h_Time = millis();
      break;
    }
    case WAIT_LEFT:
    {
      break;
    }
    case RIGHT:
    {
      if(x_pos > 0)
      {
        x_pos -= 1;
      }
      h_servo.write(x_pos);
      h_Time = millis();
      break;
    }
    case WAIT_RIGHT:
    {
      break;
    }
    default:
    {
      break;
    }
  }

  //transitions
  switch(state)
  {
    case START:
    {
      state = STOP;
      break;
    }
    case STOP: 
    {
      if ( (val_1 && val_2 && !val_3) || (val_1 && !val_2 && !val_3) ) {
        state = SET_R;
      } else if ( (!val_1 && val_2 && val_3) || (!val_1 && !val_2 && val_3) ) {
        state = SET_L;
      } else if ( (!val_1 && val_2 && !val_3) || (!val_1 && !val_2 && !val_3) ) {
        state = SET_C;
      } else {
        state = STOP;
      }
      break;
    }
    case SET_L: {
      state = WAIT;
      break;
    }
    case SET_C: {
      state = WAIT;
      break;
    }
    case SET_R: {
      state = WAIT;
      break;
    }
    case WAIT:
    {
      if(x_left && !x_right)
      {
        state = LEFT;
      }
      else if (!x_left && x_right)
      {
        state = RIGHT;
      }
      else
      {
        state = WAIT;
      }
      break;
    }
    case LEFT:
    {
      state = WAIT_LEFT;
      break;
    }
    case WAIT_LEFT:
    {
      if(millis() - h_Time >= MOTOR_DELAY)
      {
        if(x_left && !x_right)
        {
          state = LEFT;
        }
        else if(!x_left && x_right)
        {
          state = RIGHT;
        }
        else
        {
          state = WAIT;
        }
      }
      else
      {
        state = WAIT_LEFT;
      }
      break;
    }
    case RIGHT:
    {
      state = WAIT_RIGHT;
      break;
    }
    case WAIT_RIGHT:
    {
      if(millis() - h_Time >= MOTOR_DELAY)
      {
        if(x_left && !x_right)
        {
          state = LEFT;
        }
        else if(!x_left && x_right)
        {
          state = RIGHT;
        }
        else
        {
          state = WAIT;
        }
      }
      else
      {
        state = WAIT_RIGHT;
      }
      break;
    }
    default:
    {
      break;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  SM_Read();
  SM_H_Motor();
}
