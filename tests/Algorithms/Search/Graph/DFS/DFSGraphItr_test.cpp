#include <memory>
#include <vector>

#include "DFSGraphIterator.h"
#include "gmock/gmock.h"
#include "graph.h"
#include "gtest/gtest.h"

class DFSGraphIteratorTest : public ::testing::Test {
 protected:
  DS::Graph<int, int> graph_;

  std::shared_ptr<Alg::DFSGraphIterator<int, int>> dfs_search_;

  virtual void SetUp() {
    graph_.InsertEdge(1, 2);
    graph_.InsertEdge(1, 3);
    graph_.InsertEdge(1, 4);

    graph_.InsertEdge(2, 3);
    graph_.InsertEdge(2, 5);

    graph_.InsertEdge(3, 7);
    graph_.InsertEdge(3, 1);

    graph_.InsertEdge(4, 2);
    graph_.InsertEdge(4, 3);

    std::cout << graph_.ToString() << std::endl;
    dfs_search_ = std::make_shared<Alg::DFSGraphIterator<int, int>>(graph_, 1);
  }

  virtual void TearDown() {}
};

TEST_F(DFSGraphIteratorTest, SearchOrderTest) {
  std::vector<int> nodes;
  std::shared_ptr<int> pnode = dfs_search_->next();

  while (pnode != nullptr) {
    nodes.push_back(*pnode);
    pnode = dfs_search_->next();
  }

  ASSERT_THAT(nodes, testing::ElementsAre(1, 2, 3, 4, 5, 7));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}