set(CMAKE_C_FLAGS "-std=gnu11")
file(GLOB_RECURSE PROJECT_SOURCES "o_*.c")
add_executable(examples examples.c ${PROJECT_SOURCES})
add_library(${PROJECT} ${PROJECT_SOURCES})
