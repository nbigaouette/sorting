cmake_minimum_required(VERSION 2.8.9)

option(test "Run all tests." ON) # Makes boolean 'test' available.

project(libsorting_utests)

########################################################################################
# Source files
set(SOURCES "")
set(HEADERS "")

list(APPEND SOURCES "simplesorts.cc")


# See https://github.com/dmonopoly/gtest-cmake-example


enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

##############
# Unit Tests
##############
add_executable(${PROJECT_NAME} ${SOURCES})

# Standard linking to gtest stuff.
target_link_libraries(${PROJECT_NAME} gtest gtest_main)

# Extra linking for the project.
target_link_libraries(${PROJECT_NAME} ${PROJECT_LIBRARY_NAME})

# This is so you can do 'make test' to see all your tests run, instead of
# manually running the executable ${PROJECT_NAME} to see those specific tests.
add_test(NAME test COMMAND ${PROJECT_NAME})

# You can also omit NAME and COMMAND. The second argument could be some other
# test executable.
# add_test(that-other-test-I-made ${PROJECT_NAME})
