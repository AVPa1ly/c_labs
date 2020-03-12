cmake_minimum_required(VERSION "3.17.0")


project("lab_2.2")

add_executable("${PROJECT_NAME}" "lab2.2.cpp")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)

install(FILES "lab2.2.cpp" DESTINATION src)