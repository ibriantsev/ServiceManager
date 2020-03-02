cmake_minimum_required (VERSION 3.8)
project (ServiceManager)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++17")

add_definitions(-DUNICODE)

include_directories(includes/com)
include_directories(includes/ServiceManagement)
include_directories("${PROJECT_SOURCE_DIR}/generated")

add_subdirectory(src/ServiceManagement)
add_subdirectory(src/com)

add_dependencies(COMObjects ServiceManagement)
add_library(${PROJECT_NAME} SHARED ServiceManagementDll.cpp ServiceManagementDll.def ServiceManagement.rc)

target_link_libraries(${PROJECT_NAME} PRIVATE comsuppw.lib)
target_link_libraries(${PROJECT_NAME} PRIVATE COMObjects)

add_executable(tests main.cpp)
target_link_libraries(tests ServiceManagement)