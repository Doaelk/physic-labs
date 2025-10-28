cmake_minimum_required(VERSION 3.16)
project(physic-labs)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include_directories(include)
include_directories(include/work2)
include_directories(include/work3)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/calc.cpp

    src/Work2/OberbeckLab.cpp
    src/Work2/CalculatedDataOberbeck.cpp
    src/Work2/ErrorOberbeck.cpp

    src/Work3/PendulumLab.cpp
    src/Work3/CalculatedDataPendulum.cpp
    src/Work3/ErrorPendulum.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
