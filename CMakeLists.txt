cmake_minimum_required(VERSION 3.2)
set(This Intent)
project (${This})
set(CMAKE_CXX_STANDARD 11)

#test case
if(EXISTS googletest)
add_subdirectory(googletest)
add_subdirectory(test)
endif()

enable_testing()

set(SOURCES
    IntentType.cpp
)

set(HEADERS
    IntentType.h
)

add_library(${This} STATIC ${SOURCES} ${HEADERS})

add_subdirectory(execute)