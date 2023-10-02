

#include "dijkstra_itr.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <cstddef>
#include <stdexcept>

#ifdef _DEBUG
#define ALG_DEBUG(X) X
#else
#define ALG_DEBUG(X)
#endif

using namespace Alg;


void DijkstraItr::add_edge(std::string a, std::string b, int weight) {
    std::size_t a_hash = Node::get_hash(a);
    std::size_t b_hash = Node::get_hash(b);

    /*!
     * add node a
    */
    if (node_directory_.find(a_hash) == node_directory_.end()) {
        node_directory_[a_hash] = std::make_shared<Node>(a);
    }

    /*!
     * add node b
    */
    if (node_directory_.find(b_hash) == node_directory_.end()) {
        node_directory_[b_hash] = std::make_shared<Node>(b);
    }

    /*!
     * Create edge
    */
    Edge e;
    e.node_hash = b_hash;
    e.weight = weight;
    
    /*!
     * Update Associate listss
    */
    graph_[a_hash].push_back(e);

}



std::vector<std::string> DijkstraItr::find_path(std::string start, std::string end) {
    /*!
     * Initialize return vector
    */
    std::vector<std::string> shortest_path;

    /*!
     * Compute hashes
    */
    std::size_t start_hash = Node::get_hash(start);
    std::size_t end_hash = Node::get_hash(end);

    /*!
     * Reset cost_to_come for start node
     * and push start node to queue
    */
    node_directory_[start_hash]->cost_to_come = 0;
    node_directory_[start_hash]->parent_hash = -1;
    prioque_.push(node_directory_[start_hash]);


    std::size_t curent_node_hash;
    do
    {
        
        if(!prioque_.empty()) {
            /*!
            * pop node from the queue
            */
            std::shared_ptr<Node> current_node = prioque_.top();
            curent_node_hash = Node::get_hash(current_node->name);
            visited_.insert(curent_node_hash);
            prioque_.pop();

            if (graph_.find(curent_node_hash) != graph_.end()) {
                /*!
                * Iterate through child nodes
                */
                for (auto edge : graph_[curent_node_hash]) {
                    int Total_cost_to_come = edge.weight + current_node->cost_to_come;
                    
                    /*!
                    * Update child node cost
                    */
                    if ( node_directory_[edge.node_hash]->cost_to_come > 
                    Total_cost_to_come ) {
                            node_directory_[edge.node_hash]->cost_to_come = 
                                                        Total_cost_to_come;
                            node_directory_[edge.node_hash]->parent_hash = curent_node_hash;
                    }
                    
                    /*!
                    * if the node has not been visited earlier 
                    *                   then push the node into the queue
                    */
                    if (visited_.find(edge.node_hash) == visited_.end())
                        prioque_.push(node_directory_[edge.node_hash]);
                }
            }
        }
        else
        {
            if(curent_node_hash != end_hash)
                throw std::runtime_error("Path to goal node not found");
        }
    }
    while (curent_node_hash != end_hash); //loop untill target node is found
    

    std::cout << "Goal found" << std::endl;

    std::size_t parent_hash = end_hash;
    while (parent_hash != -1) {
        shortest_path.push_back(node_directory_[parent_hash]->name);
        parent_hash = node_directory_[parent_hash]->parent_hash;
        
    }

    std::for_each(shortest_path.begin(), shortest_path.end(), [](std::string& a) {
        std::cout << a;
    });

    std::cout << "\n";

    return shortest_path;
}