#ifndef MOCK_SERVO
#define MOCK_SERVO

//this is a mock class for the servo motor library
class Servo
{
    Servo();
    ~Servo();
    void attach(const int & pin);
    void write(const int & value);
};

#endif
