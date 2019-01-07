cmake_minimum_required (VERSION 3.1)
project (zadanie6 C CXX)

set (CMAKE_CXX_STANDARD 17)

#add_executable(example starwars2_example.cc rebelfleet.h rebelfleet.cc imperialfleet.h imperialfleet.cc)

add_executable(example starwars2_example.cc rebelfleet.h rebelfleet.cc
        imperialfleet.h imperialfleet.cc helper.h helper.cc battle.h battle.cc)
