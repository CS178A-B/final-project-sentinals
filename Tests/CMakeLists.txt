CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENTIONS OFF)

ADD_EXECUTABLE(Mock_Time_Test.out
    "Test_Files/Mock_Time_Test.cpp"
    "Mock_Libraries/Mock_Time.cpp"
    )

ADD_EXECUTABLE(GPIO_Test.out
    "Test_Files/GPIO_Test.cpp"
    "Mock_Libraries/Mock_Time.cpp"
    "Mock_Libraries/Mock_Functions.cpp"
    )

ADD_EXECUTABLE(Servo_Test.out
    "Test_Files/Servo_Test.cpp"
    "Mock_Libraries/Mock_Time.cpp"
    "Mock_Libraries/Mock_Servo.cpp"
    )

ADD_EXECUTABLE(Horizontal_Test.out
    "Test_Files/horizontal_test.cpp"
    "Mock_Libraries/Mock_Time.cpp"
    "Mock_Libraries/Mock_Functions.cpp"
    "Mock_Libraries/Mock_Servo.cpp"
    )

ADD_EXECUTABLE(Movement_Test.out
    "Test_Files/Movement_Test.cpp"
    "Mock_Libraries/Mock_Time.cpp"
    "Mock_Libraries/Mock_Functions.cpp"
    "Mock_Libraries/Mock_Servo.cpp"
    )
