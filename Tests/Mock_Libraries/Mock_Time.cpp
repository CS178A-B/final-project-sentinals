#include "Mock_Time.h"

//time when the clock starts
timeb t_start;

//this function starts the "internal timer" of the mock system
void initialize_time()
{
    ftime(&t_start);
}


//finds the number of millisecond since the start time
unsigned long millis()
{
    timeb t_now;
    ftime(&t_now);
    return (t_now.time - t_start.time) * 1000 + (t_now.millitm - t_start.millitm);
}

//delays the number of milliseconds delayed
void delay(const unsigned long & ms)
{
    unsigned long start = millis();
    while(millis() - start < ms){}
}
