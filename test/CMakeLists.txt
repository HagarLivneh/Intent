cmake_minimum_required(VERSION 3.2)
set(This IntentTests)

set(TestSources
    main_test.cpp
    IntentTest.cpp
)

add_executable(${This} ${TestSources})

target_link_libraries(${This} PUBLIC 
    gtest_main
    Intent)

add_test(
    NAME ${This} 
    COMMAND ${This}
)
