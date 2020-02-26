cmake_minimum_required (VERSION 3.8)
project (ServiceManager)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++17")

add_definitions(-DUNICODE)

include_directories(includes/ServiceManagement)

add_subdirectory(src/ServiceManagement)

add_executable (ServiceManager "main.cpp")

target_link_libraries(ServiceManager PUBLIC ServiceManagement)
