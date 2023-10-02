#pragma once
#include <unordered_set>
#include <memory>
#include <stack>

#include "graph.h"

namespace Alg {

    template<class T, class N>
    class DFSGraphIterator {

        private:
            const DS::Graph<T, N>& graph_;
            std::unordered_set<T> visited_;
            std::stack<N> stack_;

        public:
            DFSGraphIterator(DS::Graph<T, N>& graph, T node);

            std::shared_ptr<T> next();
    };

}