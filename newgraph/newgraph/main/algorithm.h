#ifndef _ALGORITHM_H
#define _ALGORITHM_H
#include "graph.h"
#include <queue>
#include <set>

class BFS {
    const Graph& graph;

public:
    explicit BFS(const Graph& graph);
    bool connected(Node* start, Node* target);
    std::set<Node*> getComponent(Node* start);
};

void writeGraph(const Graph& graph, const std::string& prefix);
#endif