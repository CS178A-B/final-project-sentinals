#ifndef MOCK_FUNCTIONS_H
#define MOCK_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <string>
//This header contains the mock functionality of the general purpose input
//output pins

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

//gpio read pin values, extern tells the compiler that the variable exists
//elsewhere. In this case it is is Mock_Functions.cpp
extern char pinIO[19];

//"sets" pinmode
void pinMode(const int & pin, const pin_type & gpio);

//"sets" pinmode
void pinMode(const int & pin, const int & gpio);

//"reads" data from the pin
//this requires the user to set the value of the pin before
//calling this function
char digitalRead(const char & pin, std::vector<std::string> * output);

//"writes" data to the pin, outputs resulting string to vector
void digitalWrite(const char & pin, const bool & value, std::vector<std::string>
        * output);

//"writes" data to the pin, outputs resulting string to vector
void digitalWrite(const char & pin, const pin_out & value,
        std::vector<std::string> * output);

#endif
