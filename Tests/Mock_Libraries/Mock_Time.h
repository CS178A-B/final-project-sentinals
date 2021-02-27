#ifndef MOCK_TIME_H
#define MOCK_TIME_H

#include<sys/timeb.h>


//this function starts the "internal timer" of the mock system
void initialize_time();

//finds the number of millisecond since the start time
unsigned long millis();

//delays the number of milliseconds delayed
void delay(const unsigned long & ms);

#endif
