#include "graph.h"

#include <iostream>
#include <string>

using namespace DS;

template <typename T, typename N>
Graph<T, N>::Graph(/* args */) {}

template <typename T, typename N>
Graph<T, N>::~Graph() {}

template <typename T, typename N>
void Graph<T, N>::InsertEdge(T vertex_a, N vertex_b) {
  digraph_[vertex_a].push_back(vertex_b);
  if (digraph_.find(vertex_b) == digraph_.end()) digraph_[vertex_b] = {};
}

template <typename T, typename N>
std::string Graph<T, N>::ToString() {
  std::string _string;
  for (auto v : digraph_) {
    _string += std::to_string(v.first) + " : ";
    for (auto i : v.second) {
      _string += std::to_string(i) + "->";
    }
    _string += "\n";
  }

  return _string;
}

// template<class  T>
// std::ostream& operator<< (std::ostream& stream,
//     const Graph<T>& matrix) {

//     for(auto v : matrix.digraph_) {

//         std::cout << v.first << " : ";
//         for(auto i : v.second) {
//             std::cout << i<< "->";
//         }
//         std::cout << std::endl;

//     }
// }