#ifndef MOCK_FUNCTIONS_H
#define MOCK_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <string>
//This header contains the mock functionality of the general purpose input output pins

enum pin_type{INPUT, OUTPUT}; //this defines the pin as set to input or output
enum pin_out{LOW, HIGH}; //defines if output is high or low

#define D0 0
#define D1 1
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define D8 8
#define D9 9
#define D10 10
#define D11 11
#define D12 12
#define D13 13
#define A0 14
#define A1 15
#define A2 16
#define A3 17
#define A4 18
#define A5 19

//output vector of the results
std::vector<std::string> output;
//gpio read pin values
char pinIO[19];

//"sets" pinmode
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
char digitalRead(const char & pin)
{
    if(pin >= 0 && pin <=19)
    {
        return pinIO[pin];
    }
    else
    {
        throw "INVALID PIN\n";
    }
}

//"writes" data to the pin
void digitalWrite(const char & pin, const bool & value)
{
    output.push_back("Writing to pin " + std::to_string(pin) + ": " + std::to_string(value));
    pinIO[pin] = value;
}

//"writes" data to the pin
void digitalWrite(const char & pin, const pin_out & value)   
{
    output.push_back("Writing to pin " + std::to_string(pin) + ": " + std::to_string(value));
    pinIO[pin] = value;
}
#endif
