//#include <Servo.h>

#include "../Mock_Libraries/Mock_Time.h"
#include "../Mock_Libraries/Mock_Functions.h"
#include "../Mock_Libraries/Mock_Servo.h"

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


//result data
std::vector<std::string> results;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(115200);
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
      x_left = digitalRead(c_pin_1, nullptr);
      x_right = digitalRead(c_pin_2, nullptr);
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
//        results.push_back("START");
      x_pos = 90;
      h_servo.write(x_pos, &results);
      break;
    }
    case STOP:
    {
//        results.push_back("STOP");
      break;
    }
    case LEFT:
    {
//        results.push_back("LEFT");
      if(x_pos <180)
      {
        x_pos += 1; 
      }
      h_servo.write(x_pos, &results);
      h_Time = millis();
      break;
    }
    case WAIT_LEFT:
    {
//        results.push_back("WAIT_LEFT");
      break;
    }
    case RIGHT:
    {
//        results.push_back("RIGHT");
      if(x_pos > 0)
      {
        x_pos -= 1;
      }
      h_servo.write(x_pos, &results);
      h_Time = millis();
      break;
    }
    case WAIT_RIGHT:
    {
//        results.push_back("WAIT_RIGHT");
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

int main()
{
    //perform "setup"
    setup();

    //initializing c_pin 1 and 2 input

    //initialize the timer then run the program ~10ms
    unsigned long temp;
    unsigned long finish = 60;
    initialize_time();
    unsigned long start = millis();
    while( (millis() - start) <= finish)
    {
        //moving left 10ms
        if( (millis() - start) <= 10)
        {
            pinIO[c_pin_1] = 1;
            pinIO[c_pin_2] = 0;
        }
        //stop 10ms
        else if( (millis() - start) <= 20)
        {
            pinIO[c_pin_1] = 0;
            pinIO[c_pin_2] = 0;
        }
        //moving right 10ms
        else if( (millis() - start) <= 30)
        {
            pinIO[c_pin_1] = 0;
            pinIO[c_pin_2] = 1;
        }
        //stop 10ms
        else if( (millis() - start) <= 40)
        {
            pinIO[c_pin_1] = 0;
            pinIO[c_pin_2] = 0;
        }
        //alternate 10ms
        else if( (millis() - start) <= 41)
        {
            pinIO[c_pin_1] = 0;
            pinIO[c_pin_2] = 1;
            temp = millis();
        }
        else if( (millis() - start) <= 50)
        {
            if( (millis() - temp) >= 1)
            {
                pinIO[c_pin_1] = (pinIO[c_pin_1] == 0) ? 1:0;
                pinIO[c_pin_2] = (pinIO[c_pin_2] == 0) ? 1:0;
                temp = millis();
            }
        }
        //stop 10 ms
        else
        {
            pinIO[c_pin_1] = 0;
            pinIO[c_pin_2] = 0;
        }
        loop();
    }

    std::cout << "printing results\n";
    for(int i = 0; i < results.size(); ++i)
    {
        std::cout << results.at(i) << "\n";
    }
}
