cmake_minimum_required(VERSION 3.15)
project(RingBuffer C)

set(CMAKE_C_STANDARD 99)

add_executable(RingBuffer main.c ring_buffer_unit_test.h ring_buffer_unit_test.c ring_buffer.c ring_buffer.h)