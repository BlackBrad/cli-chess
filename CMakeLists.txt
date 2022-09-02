cmake_minimum_required(VERSION 3.0)

project (cli-chess)
set (TARGET cli-chess)

# Set warnings as errors for both the tests and the executable
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Wshadow")
#add_subdirectory(src)

# Build the unit testing framework, cmocka from source
add_subdirectory(cmocka)
add_subdirectory(tests)
