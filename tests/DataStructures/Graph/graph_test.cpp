#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "graph.h"

using namespace DS;

TEST(DS_GRAPH, CREATE) {

    
    DS::Graph<int, int> _graph;
    _graph.InsertEdge(1, 2);
    _graph.InsertEdge(1, 3);
    _graph.InsertEdge(1, 4);
    // graph.insert_edge(2, 5);
    // graph.insert_edge(2, 6);
    // graph.insert_edge(3, 7);
    // graph.insert_edge(3, 9);
    // graph.insert_edge(4, 8);
    // graph.insert_edge(4, 10);

    ;

    EXPECT_EQ(_graph.ToString(), "1 : 2->3->4->\n");
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }