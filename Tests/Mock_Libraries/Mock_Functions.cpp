#include "Mock_Functions.h"

//gpio read pin values
char pinIO[19];

void pinMode(const int & pin, const pin_type & gpio)
{
    if(gpio == INPUT)
    {
        std::cout<< "Setting pin: " << pin << " as INPUT\n";
    }
    else
    {
        std::cout<< "Setting pin: " << pin << " as OUTPUT\n";
    }
}

//"sets" pinmode
void pinMode(const int & pin, const int & gpio)
{
    if(gpio == INPUT)
    {
        std::cout<< "Setting pin: " << pin << " as INPUT\n";
    }
    else
    {
        std::cout<< "Setting pin: " << pin << " as OUTPUT\n";
    }
}

//"reads" data from the pin
//this requires the user to set the value of the pin before
//calling this function
char digitalRead(const char & pin, std::vector<std::string> * output)
{
    if(output != nullptr)
    {
        (*output).push_back("Reading from pin " + std::to_string(pin) + ": " +
                std::to_string(pinIO[pin]));
    }
    if(pin >= 0 && pin <=19)
    {
        return pinIO[pin];
    }
    else
    {
        throw "INVALID PIN\n";
    }
}

//"writes" data to the pin, outputs resulting string to vector
void digitalWrite(const char & pin, const bool & value, std::vector<std::string>
        * output)
{
    if(output != nullptr)
    {
        (*output).push_back("Writing to pin " + std::to_string(pin) + ": " +
                std::to_string(value));
    }
    pinIO[pin] = value;
}

//"writes" data to the pin, outputs resulting string to vector
void digitalWrite(const char & pin, const pin_out & value,
        std::vector<std::string> * output)   
{
    if(output != nullptr)
    {
        (*output).push_back("Writing to pin " + std::to_string(pin) + ": " +
                std::to_string(value));
    }
    pinIO[pin] = value;
}
