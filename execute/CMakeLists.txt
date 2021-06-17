cmake_minimum_required(VERSION 3.2)
set(This IntentReco)
project(${This})

enable_testing()

set(SOURCES
        main.cpp)

add_executable(${This} ${SOURCES})

target_link_libraries(${This}
        Intent)