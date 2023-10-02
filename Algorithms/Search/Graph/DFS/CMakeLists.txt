add_library(dfsgraphitr)

target_include_directories(dfsgraphitr
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(dfsgraphitr
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DFSGraphIterator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/DFSGraphIterator-impl.cpp
)

target_link_libraries(dfsgraphitr
    graph
)