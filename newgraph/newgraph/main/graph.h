#ifndef _GRAPH_H
#define _GRAPH_H
#include "node.h"
#include <set>
#include <string>

class Graph {
    std::set<Node*> nodes;
    Node* findNode(const std::string& name) const;

public:
    using iterator = std::set<Node*>::const_iterator;

    Graph() = default;
    explicit Graph(const std::string& file_name);
    ~Graph();

    void addNode(Node* node);
    void removeNode(Node* node);
    void addEdge(Node* begin, Node* end);
    void removeEdge(Node* begin, Node* end);
    bool contains(Node* node) const;

    iterator begin() const;
    iterator end() const;
};
#endif