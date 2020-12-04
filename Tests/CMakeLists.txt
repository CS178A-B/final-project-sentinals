CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENTIONS OFF)

ADD_EXECUTABLE(Mock_Time_Test.out
    "Test_Files/Mock_Time_Test.cpp"
    "Mock_Libraries/Mock_Time.cpp"
    )
