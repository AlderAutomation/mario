cmake_minimum_required(VERSION 3.15...4.4)

project(NotMario VERSION 1.0 DESCRIPTION "A platforming gaming in style of Mario" LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib REQUIRED)

add_executable(main 
	src/main.c
	src/Player.c
	src/Components.c  
)

target_link_libraries(main PRIVATE raylib)

target_compile_features(main PRIVATE c_std_17)

target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/include)

