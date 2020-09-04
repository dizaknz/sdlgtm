cmake_minimum_required(VERSION 3.7)

project(lgtm2ic)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(lgtm lgtm.c)
target_link_libraries(lgtm ${CONAN_LIBS})
