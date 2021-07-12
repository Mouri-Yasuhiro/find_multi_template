cmake_minimum_required(VERSION 2.8.3)
project(find_multi_tamplate)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenCV REQUIRED)

include_directories(
  include
)

add_executable(${PROJECT_NAME} src/find_multi_tamplate.cpp)

target_link_libraries(${PROJECT_NAME}
  ${OpenCV_LIBRARIES}
)



