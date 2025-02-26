cmake_minimum_required(VERSION 3.16.3)
project(Trajectory_FOR_Autonomous VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(DATA_LIBRARY DATALIBRARY)
set(FRENET_LIBRARY FRENETLIBRARY)
set(CART_FRENET CFLIBRARY)

set(EXECUTABLE_NAME EXECUTABLE)

add_subdirectory(DataSET)
add_subdirectory(FrenetVEH)
add_subdirectory(Frenet-Cart)
add_subdirectory(Source)