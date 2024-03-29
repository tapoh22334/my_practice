cmake_minimum_required(VERSION 2.8)
project(uma_dummy_race CXX)

set(CMAKE_CXX_STANDARD, 14)
set(CMAKE_CXX_FLAGS "-Wextra -Wall")

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     ON)

find_package(Boost 1.36.0 REQUIRED
             COMPONENTS date_time system regex)

message("## Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}") 
message("## Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}") 

include_directories(${Boost_INCLUDE_DIR})

add_executable(lambda yield.cpp)
add_executable(yield yield.cpp)
add_executable(ptree ptree.cpp)

target_link_libraries(yield ${Boost_LIBRARIES})
target_link_libraries(lambda ${Boost_LIBRARIES})
target_link_libraries(ptree ${Boost_LIBRARIES})
