cmake_minimum_required (VERSION 3.10)


project ("lab6" VERSION 1.0.0)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

file(GLOB CCS "src/*.c")

add_executable(${PROJECT_NAME} ${CCS})

install (TARGETS "${PROJECT_NAME}" DESTINATION "${EXE_DIR}")