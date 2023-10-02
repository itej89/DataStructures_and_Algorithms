#include <iostream>
#include <queue>
#include <string>

#include "dijkstra_itr.h"

#ifdef _DEBUG 
#define ALG_DEBUG(X) X
#else
#define ALG_DEBUG(X)
#endif

using namespace Alg;

DijkstraItr::DijkstraItr(DS::Graph<Node, Node>& graph, Node node) : 
    graph_(graph) {
        // if(graph_.digraph_.find(node) == graph_.digraph_.end())
        //     throw std::runtime_error("Invalid start node!");

        prioque_.push(node);
}

std::shared_ptr<Node> DijkstraItr::next() {

           std::shared_ptr<Node> next_node = 
            std::make_shared<Node>() ;

        /*!
         * Skip nodes that have been already visited
        */
        do{
            if (!prioque_.empty()){
                *next_node  =prioque_.top();
                prioque_.pop();
            }
            else {
                next_node = nullptr;
            }
        }
        while(next_node != nullptr && visited_.find(*next_node) != visited_.end());

        /**
         * @brief Visit the next node
         * 
         */
        if (next_node != nullptr) {

            visited_.insert(*next_node);

            /**
             * @brief Push next nodes children in to que
             * 
             */
            for (auto v  : graph_.digraph_.at(*next_node)) {
                prioque_.push(v);
            }
          
            ALG_DEBUG({print_nodes();})

            return  next_node;
        }

    ALG_DEBUG({print_nodes();})

    return  nullptr;

}

void DijkstraItr::print_nodes() {

    std::cout << "Visited: ";
    for (auto v: visited_) {
        std::cout << v.name << " ";
    }
    std::cout << std::endl;

    std::cout << "PrioQueue: ";
    std::priority_queue<Node> copy_queue = prioque_;
    while (!copy_queue.empty())  {
        std::cout << copy_queue.top().name << " ";
        copy_queue.pop();
    }
    std::cout << std::endl;

}


