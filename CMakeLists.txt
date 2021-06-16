cmake_minimum_required(VERSION 3.2)
set(This Intent)
project (${This} C CXX)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    IntentType.h
)

set(Sources
    IntentType.cpp
    main.cpp
)
add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)