# CMakeList.txt : CMake project for SudokuGame, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Include sub-projects.
add_subdirectory ("resources" "headers")

# Add source to this project's executable.
add_executable (SudokuGame "main.c")

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK REQUIRED gtk+-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK_CFLAGS_OTHER})

# Add an executable compiled from hello.c
ADD_EXECUTABLE(hello main.c)

# Link the target to the GTK+ libraries
TARGET_LINK_LIBRARIES(hello ${GTK3_LIBRARIES})
# TODO: Add tests and install targets if needed.
