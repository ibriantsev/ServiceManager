set(MIDL_OUTPUT 
    "${PROJECT_SOURCE_DIR}/generated/IServiceManager.h"
    "${PROJECT_SOURCE_DIR}/generated/GUIDS.c"
    "${PROJECT_SOURCE_DIR}/generated/ServiceManagement.tlb"
)
set(MIDL_FILE ${CMAKE_SOURCE_DIR}/includes/com/IServiceManager.idl)
add_custom_command(
    OUTPUT ${MIDL_OUTPUT}
    COMMAND midl /h IServiceManager.h /iid GUIDS.c /tlb ServiceManagement.tlb /out generated ${MIDL_FILE}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    DEPENDS ${MIDL_FILE}
    MAIN_DEPENDENCY ${MIDL_FILE}
    VERBATIM
)

set(HEADERS
    ${CMAKE_SOURCE_DIR}/includes/util/Util.h
    ${CMAKE_SOURCE_DIR}/includes/com/ServiceManagerObj.h 
    ${CMAKE_SOURCE_DIR}/includes/com/ServiceManagerObjFactory.h
    ${CMAKE_SOURCE_DIR}/includes/com/ServiceInfoConverter.h
)
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_library(COMObjects STATIC ../util/Util.cpp ServiceInfoConverter.cpp ServiceManagerObj.cpp ServiceManagerObjFactory.cpp ${HEADERS})

target_sources(COMObjects PRIVATE ${MIDL_FILE} ${MIDL_OUTPUT})
target_link_libraries(COMObjects debug ServiceManagement)
target_link_libraries(COMObjects optimized ServiceManagement)