#pragma once
#include <memory>
#include <queue>
#include <unordered_set>

#include "graph.h"

namespace Alg {

template <class T, class N>
class BFSGraphIterator {
 private:
  const DS::Graph<T, N>& graph_;
  std::unordered_set<T> visited_;
  std::queue<T> que_;

 public:
  BFSGraphIterator(DS::Graph<T, N>& graph, T node);

  std::shared_ptr<T> next();

  void print_nodes();
};

}  // namespace Alg