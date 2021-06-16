cmake_minimum_required(VERSION 3.2)
set(This IntentTest)
project(${This})

set(SOURCES
        mainTest.cpp
        IntentTest.cpp
    )

add_executable(${This} ${SOURCES})

target_link_libraries(${This}
        gtest_main
        gtest
        Intent
        pthread
    )

add_test(NAME ${This}
        COMMAND ${This})