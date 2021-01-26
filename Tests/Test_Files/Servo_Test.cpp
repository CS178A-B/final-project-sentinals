#include <iostream>
#include "../Mock_Libraries/Mock_Time.h"
#include "../Mock_Libraries/Mock_Servo.h"

Servo myservo;

std::vector<std::string> output;

void setup()
{
    myservo.attach(5);
}

void SM_Trigger(bool reset = false)
{
  static char pos; //position of the motor
  const uint32_t SERVO_DELAY = 5; //5 ms delay for each state
  static enum {START, TRIGGER_LEFT, TRIGGER_RIGHT, TRIGGER_WAIT} state = START;
  static enum {STOP, LEFT, RIGHT} t_move = STOP;  //motor state
  static uint32_t timeLastTransition = 0;
  
  //check if reset button is pressed
  if(reset)
  {
    state = START;
    pos=0;
    myservo.write(pos, &output);
  }

  //actions
  switch(state)
  {
    case START:
    {
      t_move = RIGHT;
      pos=0;
      myservo.write(pos, &output);
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
      myservo.write(pos, &output);
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
      myservo.write(pos, &output);
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

void loop()
{
    SM_Trigger();
}

int main()
{

    //perform "setup"
    setup();

    //initialize the timer then run the program for ~900ms
    unsigned long finish = 901;
    initialize_time();
    unsigned long start = millis();
    while( (millis() - start) <= finish)
    {
        loop();
    }
    //expecting results
    std::cout << "Actual results : \n";
    //prints the results
    for(int i = 0; i < output.size(); ++i)
    {
        std::cout << output.at(i) << "\n";
    }
}
