cmake_minimum_required(VERSION 2.6)

project(nthprime)

add_executable(nthprime nthprime.c)

if (UNIX)
  TARGET_LINK_LIBRARIES(nthprime -lm)
endif ()

install (TARGETS nthprime DESTINATION bin)
