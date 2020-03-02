cmake_minimum_required (VERSION 3.8)

project (ServiceManagerCOMClient)

include_directories("${CMAKE_SOURCE_DIR}/includes/model/com")
include_directories("../ServiceManagerCOMObject/generated")

file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/model/com/*.cpp")

add_executable (${PROJECT_NAME} "ServiceManagerCOMClient.cpp" ${SOURCES})