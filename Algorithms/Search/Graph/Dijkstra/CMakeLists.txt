add_library(dijkstraitr)

target_include_directories(dijkstraitr
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)



target_sources(dijkstraitr
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/dijkstra_itr.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/DijkstraItr-impl.cpp
)

target_link_libraries(dijkstraitr
    graph
)