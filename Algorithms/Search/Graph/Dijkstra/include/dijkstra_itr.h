#pragma once

#include <queue>
#include <memory>
#include <string>
#include <unordered_set>

#include <graph.h>
#include "node.h"

namespace  Alg{

    /**
     * @brief Class that implements Dijkstra Algorithm for 
     * Graph based on Association list
     * 
     */
     class DijkstraItr {

        public:
            DS::Graph<Node, Node>& graph_;
            std::unordered_set<Node, Node::HashFunction> visited_;
            std::priority_queue<Node> prioque_;

            DijkstraItr(DS::Graph<Node, Node>& graph, Node node);
            std::shared_ptr<Node> next();
            void print_nodes();
     };
    
}