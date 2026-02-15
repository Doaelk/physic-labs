cmake_minimum_required(VERSION 3.16) 
project(physic-labs)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Calc.cpp
    src/LabFactory.cpp
    src/fstream/csv/Fcsv.cpp
    src/labs/LabStruct.cpp
    src/labs/lab2\(1\)/Lab2.cpp
    src/labs/lab2\(1\)/Lab2Exp.cpp
    src/labs/lab2\(1\)/Lab2Calc.cpp
    src/labs/lab2\(1\)/Lab2Error.cpp
    src/tokens/LabToken.cpp
    src/tokens/ExperimentToken.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
