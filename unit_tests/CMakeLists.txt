cmake_minimum_required(VERSION 2.8.9)

option(test "Run all tests." ON) # Makes boolean 'test' available.

project(libsorting_utests)

########################################################################################
# Source files
set(SOURCES "")
set(HEADERS "")

list(APPEND HEADERS "verifyarrays.h")
list(APPEND HEADERS "verifsortedyarrays.h")
list(APPEND SOURCES "validate_verifyarray.cc")
list(APPEND SOURCES "simplesorts.cc")
list(APPEND SOURCES "efficientsorts_mergesort.cc")
list(APPEND SOURCES "efficientsorts_mergesortrecursive.cc")
list(APPEND SOURCES "efficientsorts_quicksort.cc")


include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

##############
# Unit Tests
##############
add_executable(${PROJECT_NAME} ${SOURCES})

# Standard linking to gtest stuff.
target_link_libraries(${PROJECT_NAME} gtest gtest_main)

# Extra linking for the project.
target_link_libraries(${PROJECT_NAME} ${PROJECT_LIBRARY_NAME})

set(VALGRIND    valgrind --tool=memcheck --leak-check=full --show-reachable=yes --db-attach=yes)
set(GDB         gdb)

# Compile and run unit tests
add_custom_target(utest DEPENDS ${PROJECT_NAME} COMMAND             ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}  COMMENT "Compile and run unit tests")
# Compile and run unit tests through valgrind
add_custom_target(val  DEPENDS ${PROJECT_NAME} COMMAND ${VALGRIND} ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}  COMMENT "Compile and run unit tests through valgrind")
# Compile and run unit tests through gdb
add_custom_target(gdb  DEPENDS ${PROJECT_NAME} COMMAND ${GDB}      ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}  COMMENT "Compile and run unit tests through gdb")
