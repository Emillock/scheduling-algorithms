cmake_minimum_required(VERSION 3.23)
project(untitled3)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled3 main.cpp structs/output_struct.h structs/p_struct.h utils/round_func.h tests/test_cases.h algs/fcfs.h structs/test_case_struct.h algs/sjf.h algs/priority.h)
