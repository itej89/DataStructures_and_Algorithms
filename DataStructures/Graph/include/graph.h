#pragma once

#include <list>
#include <map>
#include <ostream>
#include <string>
#include <vector>

namespace DS {

template <typename T, typename N>
class Graph {
 public:
  std::map<T, std::list<N>> digraph_;

  Graph(/* args */);
  ~Graph();

  // template<class U>
  // friend std::ostream& operator<<(std::ostream& stream, const Graph<U>&
  // matrix );

  std::string ToString();
  void InsertEdge(T vertex_a, N vertex_b);
};

// template<class T>
// std::ostream& operator<< (std::ostream& stream,
//         const Graph<T>& matrix);

}  // namespace DS