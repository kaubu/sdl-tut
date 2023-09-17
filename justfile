# CC specifies which compiler we're using
CC := "g++"

# COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS := "-w"

# LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS := "-lSDL2"

# OBJS specifies which files to compile as part of the project
OBJS := "01_hello_SDL.cpp"

# OBJ_NAME specifies the name of our exectuable
OBJ_NAME := "01_hello_SDL"

default:
    just -l

# Compiles the executable
build:
    {{CC}} {{COMPILER_FLAGS}} {{LINKER_FLAGS}} {{OBJS}} -o {{OBJ_NAME}}
