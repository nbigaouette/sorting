cmake_minimum_required(VERSION 2.8.9)

project(sorting)

get_filename_component(MAIN_PROJECT_PATH "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE CACHE)
set(CMAKE_MODULE_PATH "${MAIN_PROJECT_PATH}/cmake")

include(compilation_flags)

# http://stackoverflow.com/questions/1435953/how-can-i-pass-git-sha1-to-compiler-as-definition-using-cmake
include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC GIT_SHA1)
git_describe(GIT_DESCRIPTION)
set(GIT_REFSPEC         ${GIT_REFSPEC}      CACHE STRING "GIT_REFSPEC")
set(GIT_SHA1            ${GIT_SHA1}         CACHE STRING "GIT_SHA1")
set(GIT_DESCRIPTION     ${GIT_DESCRIPTION}  CACHE STRING "GIT_DESCRIPTION")

add_subdirectory(gtest)

########################################################################################
# Source files
set(SOURCES "")
set(HEADERS "")

list(APPEND HEADERS "include/simplesorts.h")
#list(APPEND SOURCES "src/main.cc")

include_directories(${MAIN_PROJECT_PATH}/include)

########################################################################################
# Dynamic library linking
#add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})

add_subdirectory(unit_tests)
