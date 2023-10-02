
add_executable(graph_test)

target_sources(graph_test PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/graph_test.cpp
)

target_link_libraries(graph_test PUBLIC
    gtest
    graph
)