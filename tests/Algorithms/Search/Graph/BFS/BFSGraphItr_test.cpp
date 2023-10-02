#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <memory>
#include <unordered_set>
#include <vector>

#include "graph.h"
#include "BFSGraphIterator.h"

class BFSGraphIteratorTest : public ::testing::Test {

    protected:
        DS::Graph<int, int> graph_;

        std::shared_ptr<Alg::BFSGraphIterator<int, int>> bfs_search_;

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
            bfs_search_ = std::make_shared<Alg::BFSGraphIterator<int, int>>(graph_, 2);

        }

        virtual void TearDown() {
            
        }

};

TEST_F(BFSGraphIteratorTest, SearchOrderTest) {  
    
        std::vector<int> nodes;
        std::shared_ptr<int> pnode = bfs_search_->next();

        while (pnode != nullptr) {
            nodes.push_back(*pnode);
            pnode = bfs_search_->next();
        }

        ASSERT_THAT(nodes, testing::ElementsAre(2,3,5,7,1,4));
    }

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }