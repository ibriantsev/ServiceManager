set(HEADERS 
    ${CMAKE_SOURCE_DIR}/includes/ServiceManagement/Service.h 
    ${CMAKE_SOURCE_DIR}/includes/ServiceManagement/ServiceConfig.h
    ${CMAKE_SOURCE_DIR}/includes/ServiceManagement/ServiceConstants.h
    ${CMAKE_SOURCE_DIR}/includes/ServiceManagement/ServiceManager.h
    ${CMAKE_SOURCE_DIR}/includes/ServiceManagement/ServiceResult.h
)

file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/ServiceManagement/*.cpp")

add_library(ServiceManagement STATIC ${SOURCES} ${HEADERS})