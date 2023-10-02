#pragma once

#include <functional>
#include <memory>
#include <string>
namespace Alg {

    class Node {

    public:
    /*!
     * Name of the node
    */
    const std::string name;

    /*!
     * Parent node with lowest cost to come from the start node
    */
    std::size_t parent_hash;

    /*!
     * Computed cost to come to this node from the start node
    */
    uint32_t cost_to_come = UINT32_MAX;


    Node(){};

    Node(std::string _name) : name(_name) {}

    Node(const Node* n) : name(n->name){}


    

    size_t static get_hash(std::string data) {
        return std::hash<std::string>()(data);
    }

    // bool operator< (const Node& a) const {
    //      return this->name < a.name;
    //     }

    // bool operator==(const Node& otherPoint) const {
    //     if (this->name == otherPoint.name) return true;
    //     else return false;
    //     }

    // struct HashFunction {
    //     size_t operator()(const Node& node) const {
    //         size_t nodeHash = std::hash<std::string>()(node.name);
    //         return nodeHash;
    //     }
    // };
    };

    /*!
    * Node comparator for priority que reordering
    */
    struct NodeCompare {
        public:
            /*!
            * Compare function
            */
            bool operator()(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) { 
                return a->cost_to_come < b->cost_to_come; 
            }
    };

}  // namespace Alg