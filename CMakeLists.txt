cmake_minimum_required(VERSION 3.14)
project(c_course C)

set(CMAKE_C_STANDARD 11)

add_executable(c_course main.c code/input_output.c code/printing_formats.c code/enums.c code/program_arguments.c code/challenge_rectangle.c code/challenge_enums.c code/bitwise_operators.c code/challenge_guest_the_number.c code/challenge_prime_numbers.c code/strings_manipulation.c code/challenge_char_arrays.c code/pointers.c code/challenge_pointers_1.c code/dynamic_memory_allocation.c code/challenge_allocating_memory.c)
