cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

add_executable (SVM "globals.h" "utils.cpp" "SVM.cpp" "bytecode_processor.cpp" "functions/all.h" "utils.cpp")
set_property(TARGET SVM PROPERTY CXX_STANDARD 20)

add_subdirectory("functions")