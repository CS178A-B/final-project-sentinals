#include <iostream>
#include "../Mock_Libraries/Mock_Time.h"
#include <chrono>

typedef std::chrono::high_resolution_clock h_r_clock;

int main()
{
    h_r_clock::time_point start;
    h_r_clock::time_point finish;
    unsigned long ms = 45;
    std::cout << "This is a test for the Mock_Time library\n";
    std::cout << "testing for " << ms << " milliseconds\n";
    std::cout << "Initializing Library and running test\n";
    initialize_time();
    unsigned long t_start = millis();
    start = h_r_clock::now();
    while( (millis() - t_start) <= ms){}
    finish = h_r_clock::now();
    std::cout<< "test completed " << ms << " milliseconds\n";
    std::cout<< "execution time of test " 
        <<
        std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count()
        << " milliseconds\n";
}
