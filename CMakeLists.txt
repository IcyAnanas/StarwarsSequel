cmake_minimum_required (VERSION 3.1)
project (zadanie6 C CXX)

set (CMAKE_CXX_STANDARD 11)

#add_executable(example starwars2_example.cc rebelfleet.h rebelfleet.cc imperialfleet.h imperialfleet.cc)

add_executable(example example.cc rebelfleet.h rebelfleet.cc imperialfleet.h imperialfleet.cc spacebattle.h spacebattle.cc)
