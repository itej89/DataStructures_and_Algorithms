add_executable(bfsgraphitr_test)


target_sources(bfsgraphitr_test 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/BFSGraphItr_test.cpp
)

target_link_libraries(bfsgraphitr_test 
    PUBLIC
    gtest
    gmock
    graph
    bfsgraphitr
)