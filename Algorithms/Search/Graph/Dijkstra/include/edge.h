#pragma once

#include <cstddef>
namespace Alg {

/**
 * @brief edge class type
 *
 */
class Edge {
 public:
  /*!
   * hash of the next node on the edge
   */
  std::size_t node_hash;

  /*!
   * Weight of the edge
  */
  int weight;
};

/*!
 * Edge comparator for priority que reordering
*/
struct EdgeCompare {
 public:

    /*!
    * Compare function
    */
    bool operator()(const Edge& a, const Edge& b) { 
        return a.weight < b.weight; 
        }

};

}  // namespace Alg