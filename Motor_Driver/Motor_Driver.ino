#include <Servo.h>

int Relay =2; // Digital Pin D2
Servo myservo;  // create servo object to control a servo
bool Flag = false; // flag to signal motor
bool Shoot = false; // flag to signal pull trigger
bool Done = false; // flag to signal the shot is complete
int inPin = 7;   // choose the input pin (for a buttonpress)
int ledpin = 13; // output pin for debugging when initializing system

uint32_t timeLastTransition = 0; //motor startup time

void setup() {
  Serial.begin(115200);
  pinMode(Relay,OUTPUT); //declare Relay as output

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(inPin, INPUT);    // declare button as input
  pinMode(ledpin,OUTPUT);  // declare led output for debugging

}


void SM_Driver(bool reset = false){

   //States
    static enum {START, WAIT, START_MOTOR, START_SHOOT} state = START;
    const uint32_t RELAY_DELAY = 2500;  //2.5sec
    static int button = 0;

    switch(state)
    {
      case START:
      {
        Flag = false;
        Shoot = false;
        Done = false;
        state = WAIT;
        break;
      }
      case WAIT:
      {
        button = digitalRead(inPin);  // read input value

        if(button != HIGH && Flag!= true){
          state = WAIT;
//          digitalWrite(ledpin,LOW);
        }else if(button == HIGH){
          state = START_MOTOR;
          Flag = true;
          timeLastTransition = millis();
//          digitalWrite(ledpin,HIGH);
        }else{
          state = WAIT;
        }
        break;
      }
      
      case START_MOTOR:
      {
        if(millis() - timeLastTransition >= RELAY_DELAY){
          state = START_SHOOT;
          Shoot = true;
        }else{
          state = START_MOTOR;
        }
        break;
      }
        
      case START_SHOOT:
      {
        if(Done == false){
          state = START_SHOOT;
        }else if(Done == true){
          state = WAIT;
          Flag = false;
          Done = false;
          Shoot = false;
          timeLastTransition = 0;
        }else{
          state = START_SHOOT;
        }
        break;
    }
    default:
      break;
    }
}


void SM_Relay(bool reset = false)
{
//  const uint32_t RELAY_DELAY = 5000;  //5sec
  //States
  static enum {OFF, ON} state = OFF;
//  static uint32_t timeLastTransition = 0;
  

//  if (reset)
//  {
//    state = OFF;
//    digitalWrite(Relay,HIGH);
//  }

  switch(state)
  {
    case OFF: //Motor is turned off
    {
      digitalWrite(Relay,LOW);
      if(Flag == true){
          state = ON;
      }
      break;
    }
    case ON:  //Motor is turned on 
    {
      digitalWrite(Relay,HIGH);
      if(Flag == false)
      {
        state = OFF;
        
      }
      
      break;
    }
    default:
    {
      state = OFF;
      break;
    }
  }
}

void SM_Trigger(bool reset = false)
{
  static char pos; //position of the motor
  const uint32_t SERVO_DELAY = 5; //5 ms delay for each state
  static enum {START, WAIT_FOR_SHOOT, TRIGGER_LEFT, TRIGGER_RIGHT, WAIT_RIGHT, WAIT_LEFT} state = START;
  static enum {STOP, LEFT, RIGHT} t_move = STOP;  //motor state
  static uint32_t servoTime = 0; //time for servo to delay
  
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
    case START:  // init
    {
      pos=90;
      myservo.write(pos);
      state = WAIT_FOR_SHOOT;
      break;
    }

    case WAIT_FOR_SHOOT: //wait for shoot flag
    {
      digitalWrite(ledpin,LOW);

      if(Shoot == false){
        state = WAIT_FOR_SHOOT;
      }
      else if(Shoot == true){
//        digitalWrite(ledpin,HIGH);
        state = TRIGGER_LEFT;
      }else{
        state = WAIT_FOR_SHOOT;
      }
      break;
    }
    
    case TRIGGER_RIGHT: //moves from 0 to 90 degrees
    {
      t_move = RIGHT;
      if(pos < 90)
      {
        pos += 1;
        state = WAIT_RIGHT;
      }
      myservo.write(pos);
      servoTime = millis();
      break;
    }

    case WAIT_RIGHT: //check if we need to move trigger left
    {

      //first we check if servo delay within delay speed
      if(millis() - servoTime >= SERVO_DELAY)
      { 
      if( pos >= 90 ){
            // we are finished with the shot go back to wait
            // reset variables
           state = WAIT_FOR_SHOOT;
           servoTime = 0;
           Done = true;
           Shoot = false;
           Flag = false;
           t_move = STOP;

      }else{
        state = TRIGGER_RIGHT;
        t_move = RIGHT;
      }
      
      }
      break;
    }

    case TRIGGER_LEFT:  //moves from 90 to 0 degrees
    {
     digitalWrite(ledpin,HIGH);
      t_move = LEFT;
//      digitalWrite(ledpin,HIGH);
      if(pos > 0)
      {
        pos -= 1;
        state = WAIT_LEFT;
      }
      myservo.write(pos);
      servoTime = millis();

      break;
    }
    case WAIT_LEFT: //waits for servo delay 
    {

      if(millis() - servoTime >= SERVO_DELAY)
      {
        if(pos <= 0){
        state = TRIGGER_RIGHT; //switches to finish trigger action
         }else{
        state = TRIGGER_LEFT; //keep moving servo to the left
         }
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
  SM_Driver();
  SM_Relay();
  SM_Trigger();

}
