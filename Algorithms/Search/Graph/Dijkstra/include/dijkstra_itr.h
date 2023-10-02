#pragma once

#include <edge.h>

#include <functional>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

#include "node.h"

namespace Alg {

/**
 * @brief Class that implements Dijkstra Algorithm for
 * Graph based on Association list
 *
 */
class DijkstraItr {
 public:
  /**
   * @brief Stores all the nodes created
   *
   */
  std::map<std::size_t, std::shared_ptr<Node>> node_directory_;

  /**
   * @brief Creates an Association list based
   * graph from the given node hashes
   *
   */
  std::map<std::size_t, std::list<Edge>> graph_;

  /**
   * @brief Contains all visited node hashes
   *
   */
  std::set<std::size_t> visited_;

  /**
   * @brief Contains the nodes to be visited
   * <top> contains nearest node to the current traversed path
   */
  std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, NodeCompare> prioque_;

  /**
   * @brief Adds and edge to the graph
   * 
   * @param a first node name
   * @param b second node name
   */
  void add_edge(std::string a, std::string b, int weight);

  /**
   * @brief Finds shortest path from start node to end node in the graph
   * 
   * @param start start node name
   * @param end  end node sname
   * @return std::vector<Node> shortest backtracked path
   */
  std::vector<std::string> find_path(std::string start, std::string end);

};

}  // namespace Alg