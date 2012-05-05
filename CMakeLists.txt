#Specify the version being used aswell as the language
cmake_minimum_required(VERSION 2.6)
#Name your project here
project(nthprime)

add_executable(nthprime nthprime.c)

install (TARGETS nthprime DESTINATION bin)
