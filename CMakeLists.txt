cmake_minimum_required(VERSION 3.14)
project(c_course C)

set(CMAKE_C_STANDARD 11)
#SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static" )

# ============= C Programming For Beginners - Master the C Language =========
#add_executable(c_course main.c master-the-c-languaje/code/input_output.c master-the-c-languaje/code/printing_formats.c master-the-c-languaje/code/enums.c master-the-c-languaje/code/program_arguments.c master-the-c-languaje/code/challenge_rectangle.c master-the-c-languaje/code/challenge_enums.c master-the-c-languaje/code/bitwise_operators.c master-the-c-languaje/code/challenge_guest_the_number.c master-the-c-languaje/code/challenge_prime_numbers.c master-the-c-languaje/code/strings_manipulation.c master-the-c-languaje/code/challenge_char_arrays.c master-the-c-languaje/code/pointers.c master-the-c-languaje/code/challenge_pointers_1.c master-the-c-languaje/code/dynamic_memory_allocation.c master-the-c-languaje/code/challenge_allocating_memory.c master-the-c-languaje/code/challenge_structs.c master-the-c-languaje/code/files.c master-the-c-languaje/code/challenge_files.c)


# ============= Advanced C Programming Course ===================
#include_directories(/Users/administaff/Desktop/libraries/bitwise)
#include_directories(${CMAKE_SOURCE_DIR}/libraries/bitwise) # used to add to search directory of includes macro

add_library(bitwise STATIC libraries/bitwise/bitwise.h libraries/bitwise/bitwise.c)
add_library(string-functions STATIC libraries/string-functions/StringFunctions.h libraries/string-functions/StringFunctions.c)

add_executable(c_course main.c code/memset.c code/bitwise.c code/bitmasks.c code/pack_data_bitmasks.c
        libraries/bitwise/bitwise.c libraries/bitwise/bitwise.h code/challenge_pack_data.c code/pack_data_bitfields.c
        code/va_functions.c code/recursion.c code/advance_control_flow.c code/io.c code/unions.c code/preprocessor.c
        code/macros.c code/predefined_macros.c code/macro_debug.c code/profiling.c code/double_pointers.c
        code/functions_pointers.c code/challenge_functions_pointers.c code/void_pointers.c)

#target_link_libraries(c_course PUBLIC "-static")
target_include_directories(c_course PUBLIC ${CMAKE_SOURCE_DIR}/libraries/bitwise) # used to add to search directory to include file.h
target_include_directories(c_course PUBLIC ${CMAKE_SOURCE_DIR}/libraries/string-functions) # used to add to search directory to include file.h

target_link_libraries(c_course ${CMAKE_SOURCE_DIR}/cmake-build-debug/libbitwise.a) # used to add the compiled libfile.a implementation of file.h
target_link_libraries(c_course ${CMAKE_SOURCE_DIR}/cmake-build-debug/libstring-functions.a) # used to add the compiled libfile.a implementation of file.h
#target_link_libraries(c_course /Users/administaff/Desktop/libraries/bitwise/cmake-build-debug/libbitwise.a)