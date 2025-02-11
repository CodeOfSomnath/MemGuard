cmake_minimum_required(VERSION 3.18)

project(memguard)

# properties
include_directories("include/")

# main library

add_library(${PROJECT_NAME} 
src/memguard.c
)


# tests

add_executable(TestBasicFunctions tests/basic.c)

target_link_libraries(TestBasicFunctions PUBLIC ${PROJECT_NAME})
if (MSVC)
    # Microsoft Visual Studio Compiler (cl.exe)
    target_compile_options(TestBasicFunctions PUBLIC /W3 /WX /Zi)
else()
    # GCC/Clang
    target_compile_options(TestBasicFunctions PUBLIC -Wall -Werror -g)
endif()
# target_link_libraries(TestBasicFunctions PUBLIC -fsanitize=address)