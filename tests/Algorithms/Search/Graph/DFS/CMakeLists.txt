add_executable(dfsgraphitr_test)


target_sources(dfsgraphitr_test 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/DFSGraphItr_test.cpp
)

target_link_libraries(dfsgraphitr_test 
    PUBLIC
    gtest
    gmock
    graph
    dfsgraphitr
)