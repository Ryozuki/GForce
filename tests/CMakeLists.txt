project(Test)

add_subdirectory(lib/googletest)

set(TEST_SOURCES
        test.cpp)

add_executable(Test ${TEST_SOURCES})
target_link_libraries(Test GForce gtest_main)
add_test(NAME example_test COMMAND example)
