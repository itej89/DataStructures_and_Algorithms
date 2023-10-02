#include "DFSGraphIterator.h"

#include <iostream>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <string>

#include "graph.h"

using namespace Alg;

template <class T, class N>
DFSGraphIterator<T, N>::DFSGraphIterator(DS::Graph<T, N>& graph, T node)
    : graph_(graph) {
  if (graph_.digraph_.find(node) == graph_.digraph_.end())
    throw std::runtime_error("Invalid start node!");

  stack_.push(node);
}

template <class T, class N>
std::shared_ptr<T> DFSGraphIterator<T, N>::next() {
  std::shared_ptr<N> next_node = std::make_shared<N>();

  do {
    if (!stack_.empty()) {
      *next_node = stack_.top();
      stack_.pop();
    } else {
      next_node = nullptr;
    }
  } while (next_node != nullptr && visited_.find(*next_node) != visited_.end());

  if (next_node != nullptr) {
    visited_.insert(*next_node);

    for (auto v : graph_.digraph_.at(*next_node)) {
      stack_.push(v);
    }

    std::cout << "Visited: ";
    for (auto v : visited_) {
      std::cout << std::to_string(v) << " ";
    }
    std::cout << std::endl;

    std::cout << "Stack: ";
    std::stack<T> copy_stack = stack_;
    while (!copy_stack.empty()) {
      std::cout << copy_stack.top() << " ";

      copy_stack.pop();
    }
    std::cout << std::endl;

    return next_node;
  }

  std::cout << "Visited: ";
  for (auto v : visited_) {
    std::cout << std::to_string(v) << " ";
  }
  std::cout << std::endl;

  std::cout << "Stack: ";
  std::stack<T> copy_stack = stack_;
  while (!copy_stack.empty()) {
    std::cout << copy_stack.top() << " ";

    copy_stack.pop();
  }
  std::cout << std::endl;

  return nullptr;
}
