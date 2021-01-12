cmake_minimum_required(VERSION 3.14)
project(c_course C)

set(CMAKE_C_STANDARD 11)

# ============= C Programming For Beginners - Master the C Language =========
#add_executable(c_course main.c master-the-c-languaje/code/input_output.c master-the-c-languaje/code/printing_formats.c master-the-c-languaje/code/enums.c master-the-c-languaje/code/program_arguments.c master-the-c-languaje/code/challenge_rectangle.c master-the-c-languaje/code/challenge_enums.c master-the-c-languaje/code/bitwise_operators.c master-the-c-languaje/code/challenge_guest_the_number.c master-the-c-languaje/code/challenge_prime_numbers.c master-the-c-languaje/code/strings_manipulation.c master-the-c-languaje/code/challenge_char_arrays.c master-the-c-languaje/code/pointers.c master-the-c-languaje/code/challenge_pointers_1.c master-the-c-languaje/code/dynamic_memory_allocation.c master-the-c-languaje/code/challenge_allocating_memory.c master-the-c-languaje/code/challenge_structs.c master-the-c-languaje/code/files.c master-the-c-languaje/code/challenge_files.c)

# ============= Advanced C Programming Course ===================
add_executable(c_course main.c code/memset.c code/bitwise.c code/bitmasks.c code/pack_data_bitmasks.c headers/bitwise.c headers/bitwise.h code/challenge_pack_data.c code/pack_data_bitfields.c code/va_functions.c code/recursion.c code/advance_control_flow.c code/io.c code/unions.c code/preprocessor.c code/macros.c code/predefined_macros.c code/macro_debug.c code/profiling.c code/double_pointers.c code/functions_pointers.c code/challenge_functions_pointers.c code/void_pointers.c)
