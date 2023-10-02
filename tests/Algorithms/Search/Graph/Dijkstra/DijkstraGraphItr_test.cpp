#include <memory>
#include <vector>

#include "dijkstra_itr.h"
#include "gmock/gmock.h"
#include "graph.h"
#include "gtest/gtest.h"

class DijkstraGraphIteratorTest : public ::testing::Test {
 protected:
  DS::Graph<int, int> graph_;

  std::shared_ptr<Alg::DijkstraItr> dfs_search_;

  virtual void SetUp() {
    dfs_search_ = std::make_shared<Alg::DijkstraItr>();

    dfs_search_->add_edge("a", "b", 2);
    dfs_search_->add_edge("a", "c", 1);
    dfs_search_->add_edge("b", "c", 1);
    dfs_search_->add_edge("c", "d", 1);
  }

  virtual void TearDown() {}
};

TEST_F(DijkstraGraphIteratorTest, FindPathTest) {
  
  std::vector<std::string> data = dfs_search_->find_path("a", "d");

  ASSERT_THAT(data, testing::ElementsAre("d", "c", "a"));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}