#include "Mock_Servo.h"
#include <iostream>

Servo::Servo()
{
    S_pin = -1;
}

Servo::~Servo()
{
}

void Servo::attach(const int& pin)
{
    std::cout << "Attaching servo to pin: " << pin << "\n";
    S_pin = pin;    
}

void Servo::write(const int & value, std::vector<std::string> * output)
{
    S_value = value;
    if(output != nullptr)
    {
        (*output).push_back("Writing to servo on pin " + std::to_string(S_pin)
                +": " + std::to_string(S_value));
    }
}
