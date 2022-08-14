cmake_minimum_required(VERSION 3.0)

project (cli-chess)
set (TARGET cli-chess)

#add_subdirectory(src)

# Build the unit testing framework, cmocka from source
add_subdirectory(cmocka)
add_subdirectory(tests)
