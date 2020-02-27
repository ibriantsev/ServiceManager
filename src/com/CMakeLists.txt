set(MIDL_OUTPUT 
    "${CMAKE_BINARY_DIR}/generated/IServiceManager.h"
    "${CMAKE_BINARY_DIR}/generated/GUIDS.c"
    "${CMAKE_BINARY_DIR}/generated/ServiceManagerProxy.c"
    "${CMAKE_BINARY_DIR}/generated/ServiceManagerProxyDll.c"
)
set(MIDL_FILE ${CMAKE_SOURCE_DIR}/includes/com/IServiceManager.idl)
add_custom_command(
    OUTPUT ${MIDL_OUTPUT}
    COMMAND midl /h IServiceManager.h /iid GUIDS.c /proxy ServiceManagerProxy.c /dlldata ServiceManagerProxyDll.c /out generated ${MIDL_FILE}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS ${MIDL_FILE}
    MAIN_DEPENDENCY ${MIDL_FILE}
    VERBATIM
)

set(HEADERS 
    ${CMAKE_SOURCE_DIR}/includes/com/ServiceManagerObj.h 
    ${CMAKE_SOURCE_DIR}/includes/com/ServiceManagerObjFactory.h
)
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/src)

add_library(COMObjects STATIC ServiceManagerObj.cpp ServiceManagerObjFactory.cpp ${HEADERS})

target_sources(COMObjects PRIVATE ${MIDL_FILE} ${MIDL_OUTPUT})
target_link_libraries(COMObjects debug ServiceManagement)
target_link_libraries(COMObjects optimized ServiceManagement)