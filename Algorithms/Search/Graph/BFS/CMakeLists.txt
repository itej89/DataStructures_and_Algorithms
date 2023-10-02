add_library(bfsgraphitr)

target_include_directories(bfsgraphitr
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)



target_sources(bfsgraphitr
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/BFSGraphIterator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/BFSGraphIterator-impl.cpp
)

target_link_libraries(bfsgraphitr
    graph
)