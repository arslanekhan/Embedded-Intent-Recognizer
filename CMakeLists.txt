cmake_minimum_required (VERSION 3.10.2)

project (Embedded_Intent_Recognizer VERSION 1.0)

set_property(DIRECTORY . PROPERTY CXX_STANDARD 17)

#target_include_directories(Embedded_Intent_Recognizer PUBLIC .)

include_directories(.)

set(SOURCES main.cpp Intent_Recognition.h Intent_Recognition.cpp)

# Adds the executable called "demo" that is built from the source files "main.cpp".
add_executable ( Embedded_Intent_Recognizer ${SOURCES})

# Adds the Sources subfolder of the C++ library.
#add_subdirectory )()

# Links the executable to the C++ libraries.
target_link_libraries (Embedded_Intent_Recognizer LINK_PRIVATE )
