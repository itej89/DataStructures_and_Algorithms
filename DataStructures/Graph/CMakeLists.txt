add_library(graph)

target_include_directories(graph PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
)

target_sources(graph PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/graph.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/graph-impl.cpp
)