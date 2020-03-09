cmake_minimum_required (VERSION 3.8)

project (ServiceManagerCOMClient)

add_definitions(-DUNICODE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/includes/model/com")
include_directories("${CMAKE_SOURCE_DIR}/includes/model")
include_directories("${CMAKE_SOURCE_DIR}/includes/controller")
include_directories("${CMAKE_SOURCE_DIR}/includes/view")
include_directories("../ServiceManagerCOMObject/generated")

file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/view/*.cpp" "${CMAKE_SOURCE_DIR}/src/model/*.cpp" "${CMAKE_SOURCE_DIR}/src/model/com/*.cpp" "${CMAKE_SOURCE_DIR}/src/controller/*.cpp")

add_executable (${PROJECT_NAME} WIN32 "ServiceManagerCOMClient.cpp" ${SOURCES})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)