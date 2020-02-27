set(HEADERS 
    ${CMAKE_SOURCE_DIR}/includes/ServiceManagement/Service.h 
    ${CMAKE_SOURCE_DIR}/includes/ServiceManagement/ServiceConfig.h
    ${CMAKE_SOURCE_DIR}/includes/ServiceManagement/ServiceConstants.h
    ${CMAKE_SOURCE_DIR}/includes/ServiceManagement/ServiceManager.h
    ${CMAKE_SOURCE_DIR}/includes/ServiceManagement/ServiceResult.h
)

add_library(ServiceManagement STATIC ServiceConfig.cpp Service.cpp ServiceManager.cpp ${HEADERS})