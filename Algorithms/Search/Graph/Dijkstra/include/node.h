#pragma once

#include <string>
namespace Alg {
    class Node {

        public:
            std::string name;
            std::string parent_name;
            int cost_to_go;

            Node() {};

            Node(std::string _name, int _cost_to_go) :
                name(_name), cost_to_go(_cost_to_go) {
                }

            bool operator==(const Node& otherPoint) const {
                if (this->name == otherPoint.name) return true;
                else return false;
                }

            struct HashFunction {
                size_t operator()(const Node& node) const {
                    size_t nodeHash = std::hash<std::string>()(node.name);
                    return nodeHash;
                }
            };

    };

    class MapCompNode {
        bool operator() (const Node& a, const Node& b) {
            return  a.name < b.name;
        }
    };
}