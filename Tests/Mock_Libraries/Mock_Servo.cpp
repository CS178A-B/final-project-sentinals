#include "Mock_Servo.h"
#include <string>
#include <iostream>

Servo::Servo()
{
}

Servo::~Servo()
{
}

void Servo::attach(const int& pin)
{
    std::cout << "Attaching servo to pin: " << pin << "\n";
}

void Servo::write(const int & value)
{
    std::cout << "Writing to servo: " << value << "\n";
}
