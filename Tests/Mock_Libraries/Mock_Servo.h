#ifndef MOCK_SERVO
#define MOCK_SERVO

#include <string>
#include <vector>

//this is a mock class for the servo motor library
class Servo
{
    private:
        int S_pin;
        int S_value;
    public:
        Servo();
        ~Servo();
        void attach(const int & pin);
        void write(const int & value, std::vector<std::string> * output);
};

#endif
