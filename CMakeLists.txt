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


# build test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
        test_gtest
        test_gtest.cpp
)

target_link_libraries(
        test_gtest
        gtest_main
        helloworld
)

# enable test
enable_testing()
include(GoogleTest)
gtest_discover_tests(test_gtest)



# create installation package
install(TARGETS helloworld_app RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT shebdim@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)