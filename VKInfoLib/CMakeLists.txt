project(VKInfoLib)

option(CODE_COVERAGE "Enable coverage reporting" OFF)

if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(STATUS "Code coverage enabled")
    add_compile_options(--coverage)
    add_link_options(--coverage)
endif()

add_library(${PROJECT_NAME} 
    include/atomic_metric.h
    include/export.h
    include/metric.h
    include/metrics_logger.h
    include/metrics_registry.h
    
    src/metrics_logger.cc
    src/metrics_registry.cc
)

install(TARGETS ${PROJECT_NAME} 
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
