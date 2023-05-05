cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

add_executable (SVM "SVM.cpp" "bytecode_processor.cpp" "globals.cpp" "functions/all.h")
set_property(TARGET SVM PROPERTY CXX_STANDARD 20)

add_subdirectory("functions")