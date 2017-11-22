cmake_minimum_required(VERSION 2.8)

project(MyBot)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall -Wno-unused-function -std=c++14 -pedantic -DM_PI=3.14159265358979323846")

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/hlt)

file(GLOB HLT_SOURCES "${CMAKE_SOURCE_DIR}/hlt/*.cpp")

add_executable(MyBot "MyBot.cpp" ${HLT_SOURCES} src/SmartShip.cpp header/SmartShip.hpp src/ShipManager.cpp header/ShipManager.hpp src/Task.cpp header/Task.hpp src/ConquerTask.cpp header/ConquerTask.hpp src/SupportTask.cpp header/SupportTask.hpp src/AttackTask.cpp header/AttackTask.hpp header/Utility.hpp header/Validation.hpp header/ShipIssue.hpp header/Singleton.hpp header/DataCore.hpp)
