add_executable(dijkstragraphitr_test)


target_sources(dijkstragraphitr_test 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/DijkstraGraphItr_test.cpp
)

target_link_libraries(dijkstragraphitr_test 
    PUBLIC
    gtest
    gmock
    dijkstraitr
)