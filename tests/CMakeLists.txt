project(TestsDriver)
add_subdirectory(lib/googletest)

set(TESTS_SOURCES
        test.cpp vectors.cpp math.cpp)

add_executable(TestsDriver ${TESTS_SOURCES})
target_link_libraries(TestsDriver GForce gtest_main)
