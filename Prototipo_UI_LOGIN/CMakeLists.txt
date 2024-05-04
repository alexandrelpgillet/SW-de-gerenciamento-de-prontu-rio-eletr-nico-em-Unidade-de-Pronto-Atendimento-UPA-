cmake_minimum_required(VERSION 3.28)
project(Projeto_Gereciamento_Hospitalar C)

set(CMAKE_C_STANDARD 23)

add_executable(Projeto_Gereciamento_Hospitalar login.c
        struct_login.h
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

target_link_libraries(Projeto_Gereciamento_Hospitalar ${GTK3_LIBRARIES})
target_compile_options(Projeto_Gereciamento_Hospitalar PRIVATE ${GTK3_CFLAGS_OTHER})
