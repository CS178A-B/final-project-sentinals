//#include <Servo.h>

#include "Mock_Servo.h"	//this is a mock for testing purposes

//input pins
const char c_pin_1 = A0; //controller pin 1
const char c_pin_2 = A1; //controller pin 2
//const byte c_pin_3 = A2; //controller pin 3
//const byte c_pin_4 = A3; //controller pin 4
//data variables
char x_left;  //checks if the motor moves left
char x_right; //checks if the motor moves right
char x_pos;
//output pins
const char h_pin = 5; //temp output pin for horizontal pin movement
Servo h_servo;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(c_pin_1, INPUT);
  pinMode(c_pin_2, INPUT);
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
      x_left = digitalRead(c_pin_1);
      x_right = digitalRead(c_pin_2);
      break;
    }
    default:
    {
      x_left = 0;
      x_right = 0;
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
  static enum {START, STOP, LEFT, WAIT_LEFT, RIGHT, WAIT_RIGHT} state = START;
  const uint32_t MOTOR_DELAY = 1; //1 ms
  static uint32_t h_Time = 0; //time for motor delay

  //on reset
  if(reset)
  {
    state=START;
  }

  //actions
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
      if(x_pos < 0)
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
      if(c_pin_1 && !c_pin_2)
      {
        state = LEFT;
      }
      else if (!c_pin_1 && c_pin_2)
      {
        state = RIGHT;
      }
      else
      {
        state = STOP;
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
        if(c_pin_1 && !c_pin_2)
        {
          state = LEFT;
        }
        else if(!c_pin_1 && c_pin_2)
        {
          state = RIGHT;
        }
        else
        {
          state = STOP;
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
        if(c_pin_1 && !c_pin_2)
        {
          state = LEFT;
        }
        else if(!c_pin_1 && c_pin_2)
        {
          state = RIGHT;
        }
        else
        {
          state = STOP;
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
