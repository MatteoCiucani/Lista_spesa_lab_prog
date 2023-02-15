cmake_minimum_required(VERSION 3.5)
project(Lista_spesa_lab_prog)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES Listonic.cpp Listonic.h ListonicObserver.cpp ListonicObserver.h Category.cpp Category.h Item.cpp Item.h User.cpp User.h)
add_executable(Lista_spesa_lab_prog main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Lista_spesa_lab_prog core)
