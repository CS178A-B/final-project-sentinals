#include <Servo.h>

Servo myservo;  // create servo object to control a servo

//int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void SM_Trigger(bool reset = false)
{
  static char pos; //position of the motor
  const uint32_t SERVO_DELAY = 12; //12 ms delay for each state
  static enum {START, TRIGGER_LEFT, TRIGGER_RIGHT, TRIGGER_WAIT} state = START;
  static enum {STOP, LEFT, RIGHT} t_move = STOP;  //motor state
  static uint32_t timeLastTransition = 0;
  
  //check if reset button is pressed
  if(reset)
  {
    state = START;
    pos=0;
    myservo.write(pos);
  }

  //actions
  switch(state)
  {
    case START:
    {
      t_move = RIGHT;
      pos=0;
      myservo.write(pos);
      timeLastTransition = millis();
      break;
    }
    case TRIGGER_LEFT:  //moves from 90 to 0 degrees
    {
      t_move = LEFT;
      if(pos >0)
      {
        pos -= 1;
      }
      myservo.write(pos);
      timeLastTransition = millis();
      break;
    }
    case TRIGGER_RIGHT: //moves from 0 to 90 degrees
    {
      t_move = RIGHT;
      if(pos < 90)
      {
        pos += 1;
      }
      myservo.write(pos);
      timeLastTransition = millis();
      break;
    }
    case TRIGGER_WAIT: //waits for time
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
      state = TRIGGER_WAIT;
      break;
    }
    case TRIGGER_LEFT:  //moves from 90 to 0 degrees
    {
      state = TRIGGER_WAIT;
      break;
    }
    case TRIGGER_RIGHT: //moves from 0 to 90 degrees
    {
      state = TRIGGER_WAIT;
      break;
    }
    case TRIGGER_WAIT: //waits for time
    {
      if(millis() - timeLastTransition >= SERVO_DELAY)
      {
        if(t_move == RIGHT && pos == 90)
        {
          state = TRIGGER_LEFT;
        }
        else if(t_move == LEFT && pos == 0)
        {;
          state = TRIGGER_RIGHT;
        }
        else
        {
          state = (t_move == RIGHT) ? TRIGGER_RIGHT:TRIGGER_LEFT;
        }
      }
      else
      {
        state = TRIGGER_WAIT;
      }
      break;
    }
    default:
    {
      state = START;
      break;
    }
  }
}

void loop() {
  SM_Trigger();
  //for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
  //  myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //  delay(12);                       // waits 12ms for the servo to reach the position
  //}
  //for (pos = 90; pos >= 0; pos -= 1) { // goes from 90 degrees to 0 degrees
  //  myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //  delay(12);                       // waits 12ms for the servo to reach the position
  //}
}
