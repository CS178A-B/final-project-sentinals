#include <iostream>
#include "../Mock_Libraries/Mock_Time.h"
#include "../Mock_Libraries/Mock_Functions.h"

#define LED_BUILTIN 13 //defining led_builtin for blink example test

std::vector<std::string> output;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    static unsigned long start = 0;
    const unsigned long blink_Delay = 1000;
    static char x;

    if( (millis() - start) > blink_Delay)
    {
        x = digitalRead(LED_BUILTIN, &output);
        if(x == 1)
        {
            digitalWrite(LED_BUILTIN, LOW, &output);
        }
        else
        {
            digitalWrite(LED_BUILTIN, HIGH, &output);
        }
        start = millis();
    }
}

int main()
{
    //this test is to see if the Mock_Functions library works properly
    //set the "builtin" led initially to low
    pinIO[LED_BUILTIN] = 0;

    //perform "setup"
    setup();

    //initialize the timer then run the program for 6 seconds
    unsigned long finish = 6001;
    initialize_time();
    unsigned long start = millis();
    while( (millis() - start) <= finish)
    {
        loop();
    }
    //expecting results
    std::cout<< "Expected results: writing out to pin " << LED_BUILTIN << ": 1"
        " 0 1 0 1 0 \n";
    std::cout << "Actual results : \n";
    //prints the results
    for(int i = 0; i < output.size(); ++i)
    {
        std::cout << output.at(i) << "\n";
    }
}
