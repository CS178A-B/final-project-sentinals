int Relay =2; // Digital Pin D2

void setup() {
  Serial.begin(115200);
  pinMode(Relay,OUTPUT); //declare Relay as output
}

void SM_Relay(bool reset = false)
{
  const uint32_t RELAY_DELAY = 5000;  //5sec
  static enum {RELAY_TOGGLE, WAIT_DELAY} state = RELAY_TOGGLE;
  static uint32_t timeLastTransition = 0;

  if (reset)
  {
    state = RELAY_TOGGLE;
    digitalWrite(Relay,HIGH);
  }

  switch(state)
  {
    case RELAY_TOGGLE: //toggle relay
    {
      digitalWrite(Relay,!digitalRead(Relay));
      timeLastTransition = millis();
      state = WAIT_DELAY;
      break;
    }
    case WAIT_DELAY:  //wait for the delay period
    {
      if(millis() - timeLastTransition >= RELAY_DELAY)
      {
        state = RELAY_TOGGLE;
      }
      break;
    }
    default:
    {
      state = RELAY_TOGGLE;
      break;
    }
  }
}

void loop() {
  SM_Relay();
//  digitalWrite(Relay, HIGH);
//  delay(5000);
//  digitalWrite(Relay, LOW);
//  delay(5000);
}
