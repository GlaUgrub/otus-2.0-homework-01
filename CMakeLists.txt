# setup project
cmake_minimum_required(VERSION 3.14)

project(otus_2_0_homework_01 VERSION 0.0.1)


# build helloworld
configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

add_executable(helloworld_app main.cpp)

add_library(helloworld lib.cpp)

set_target_properties(helloworld_app helloworld PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(helloworld_app
    helloworld
)