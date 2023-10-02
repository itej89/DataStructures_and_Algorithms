/**
 * @file BFSGraphIterator.cpp
 * @author Tej Kiran (itej89@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "BFSGraphIterator.h"

#include <iostream>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <string>

#include "graph.h"

#ifdef _DEBUG
#define ALG_DEBUG(X) X
#else
#define ALG_DEBUG(X)
#endif

using namespace Alg;

/**
 * @brief Construct a new BFSGraphIterator<T>::BFSGraphIterator object
 *
 * @tparam T type of node
 * @param graph
 * @param node
 */
template <class T, class N>
BFSGraphIterator<T, N>::BFSGraphIterator(DS::Graph<T, N>& graph, T node)
    : graph_(graph) {
  if (graph_.digraph_.find(node) == graph_.digraph_.end())
    throw std::runtime_error("Invalid start node!");

  que_.push(node);
}

/**
 * @brief prints iterator state for debugging
 *
 * @tparam T
 */
template <class T, class N>
void BFSGraphIterator<T, N>::print_nodes() {
  std::cout << "Visited: ";
  for (auto v : visited_) {
    std::cout << std::to_string(v) << " ";
  }
  std::cout << std::endl;

  std::cout << "Queue: ";
  std::queue<N> copy_queue = que_;
  while (!copy_queue.empty()) {
    std::cout << copy_queue.front() << " ";

    copy_queue.pop();
  }
  std::cout << std::endl;
}

/**
 * @brief Move iterator one step ahead through the graph
 *
 * @tparam T
 * @return std::shared_ptr<T>
 */
template <class T, class N>
std::shared_ptr<T> BFSGraphIterator<T, N>::next() {
  std::shared_ptr<T> next_node = std::make_shared<T>();

  /*!
   * Skip nodes that have been already visited
   */
  do {
    if (!que_.empty()) {
      *next_node = que_.front();
      que_.pop();
    } else {
      next_node = nullptr;
    }
  } while (next_node != nullptr && visited_.find(*next_node) != visited_.end());

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
    for (auto v : graph_.digraph_.at(*next_node)) {
      que_.push(v);
    }

    ALG_DEBUG({ print_nodes(); })

    return next_node;
  }

  ALG_DEBUG({ print_nodes(); })

  return nullptr;
}
