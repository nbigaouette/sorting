cmake_minimum_required(VERSION 2.8.9)

option(prof "Run profile tests." ON) # Makes boolean 'prof' available.

project(libsorting_profile)

########################################################################################
# Source files
set(SOURCES "")
set(HEADERS "")

#list(APPEND HEADERS "verifyarrays.h")
list(APPEND SOURCES "main.cc")

##############
# Profiling
##############
add_executable(${PROJECT_NAME} ${SOURCES})

# Standard linking to gtest stuff.
#target_link_libraries(${PROJECT_NAME} gtest gtest_main)

# Extra linking for the project.
#target_link_libraries(${PROJECT_NAME} ${PROJECT_LIBRARY_NAME})

set(VALGRIND    valgrind --tool=memcheck --leak-check=full --show-reachable=yes --db-attach=yes)
set(GDB         gdb)

# Compile and run profiling
add_custom_target(prof DEPENDS ${PROJECT_NAME} COMMAND             ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}  COMMENT "Compile and run profiling")
# Compile and run profiling through valgrind
add_custom_target(profval  DEPENDS ${PROJECT_NAME} COMMAND ${VALGRIND} ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}  COMMENT "Compile and run profiling through valgrind")
# Compile and run profiling through gdb
add_custom_target(profgdb  DEPENDS ${PROJECT_NAME} COMMAND ${GDB}      ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}  COMMENT "Compile and run profiling through gdb")
# Plot profiling
add_custom_target(plot  COMMAND             ${CMAKE_SOURCE_DIR}/profiling/plot.py ${CMAKE_CURRENT_BINARY_DIR}  COMMENT "Plot profiling data")
