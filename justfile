# CC specifies which compiler we're using
CC := "g++"

# COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS := "-w"

# LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS := "-lSDL2"

# OBJS specifies which files to compile as part of the project
OBJS := "src/main.cpp"

# OBJ_NAME specifies the name of our exectuable
OBJ_NAME := "sdl_tut"

default:
    just -l

alias b := build
# Compiles the executable
build:
    {{CC}} {{COMPILER_FLAGS}} {{LINKER_FLAGS}} {{OBJS}} -o {{OBJ_NAME}}

alias r := run
# Build then run
run:
    just build
    ./sdl_tut
