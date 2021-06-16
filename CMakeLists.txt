cmake_minimum_required(VERSION 3.2)
set(This Intent)
project (${This})
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(googletest)

enable_testing()

set(SOURCES
    IntentType.cpp
)

set(HEADERS
    IntentType.h
)

add_library(${This} STATIC ${SOURCES} ${HEADERS})

add_subdirectory(test)
add_subdirectory(execute)