#ifndef MOCK_FUNCTIONS_H
#define MOCK_FUNCTIONS_H

#include <iostream>

//This header contains the mock functionality of the general purpose input output pins

enum {INPUT, OUTPUT} pin_type; //this defines the pin as set to input or output
enum {LOW, HIGH} pin_out; //defines if output is high or low

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

//gpio read pin values
int pinD0;
int pinD1;
int pinD2;
int pinD3;
int pinD4;
int pinD5;
int pinD6;
int pinD7;
int pinD8;
int pinD9;
int pinD10;
int pinD11;
int pinD12;
int pinD13;
int pinA0;
int pinA1;
int pinA2;
int pinA3;
int pinA4;
int pinA5;

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

//"reads" data from the pin
//this requires the user to set the value of the pin before
//calling this function
char digitalRead(const char & pin)
{
    switch(pin)
    {
        case 0:
        {
            return pinD0;
            break;
        }
        case 1:
        {
            return pinD1;
            break;
        }
        case 2:
        {
            return pinD2;
            break;
        }
        case 3:
        {
            return pinD3;
            break;
        }
        case 4:
        {
            return pinD4;
            break;
        }
        case 5:
        {
            return pinD5;
            break;
        }
        case 6:
        {
            return pinD6;
            break;
        }
        case 7:
        {
            return pinD7;
            break;
        }
        case 8:
        {
            return pinD8;
            break;
        }
        case 9:
        {
            return pinD9;
            break;
        }
        case 10:
        {
            return pinD10;
            break;
        }
        case 11:
        {
            return pinD11;
            break;
        }
        case 12:
        {
            return pinD12;
            break;
        }
        case 13:
        {
            return pinD13;
            break;
        }
        case 14:
        {
            return pinA0;
            break;
        }
        case 15:
        {
            return pinA1;
            break;
        }
        case 16:
        {
            return pinA2;
            break;
        }
        case 17:
        {
            return pinA3;
            break;
        }
        case 18:
        {
            return pinA4;
            break;
        }
        case 19:
        {
            return pinA5;
            break;
        }
        default:
        {
            throw "INVALID PIN\n";
            break;
        }
    }
}

//"writes" data to the pin
void digitalWrite(const char & pin, bool value)
{
    std::cout<< "Setting pin: " << pin << " to " << value << "\n";
}
#endif
