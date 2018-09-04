project(Tests)

add_subdirectory(lib/googletest)

set(TESTS_SOURCES
        test.cpp)

add_executable(Tests ${TESTS_SOURCES})
target_link_libraries(Tests GForce gtest_main)
add_test(TestName Tests)
