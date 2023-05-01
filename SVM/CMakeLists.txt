cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

add_executable (SVM "SVM.cpp" "SVM.h" "bytecode_processor.h" "bytecode_processor.cpp")

add_subdirectory(functions)

set_property(TARGET SVM PROPERTY CXX_STANDARD 20)