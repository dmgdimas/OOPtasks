#include "algorithm.h"
#include <fstream>
#include <queue>
#include <set>

BFS::BFS(const Graph& graph) : graph(graph) {}

bool BFS::connected(Node* start, Node* target) {
    if (!start || !target) return false;

    std::queue<Node*> q;
    std::set<Node*> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        Node* current = q.front(); q.pop();
        if (current == target) return true;

        for (auto it = current->nb_begin(); it != current->nb_end(); ++it) {
            if (visited.find(*it) == visited.end()) {
                visited.insert(*it);
                q.push(*it);
            }
        }
    }

    return false;
}

std::set<Node*> BFS::getComponent(Node* start) {
    std::set<Node*> component;
    if (!start) return component;

    std::queue<Node*> q;
    std::set<Node*> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        Node* current = q.front(); q.pop();
        component.insert(current);

        for (auto it = current->nb_begin(); it != current->nb_end(); ++it) {
            if (visited.find(*it) == visited.end()) {
                visited.insert(*it);
                q.push(*it);
            }
        }
    }

    return component;
}

void writeGraph(const Graph& graph, const std::string& prefix) {
    std::set<Node*> unvisited(graph.begin(), graph.end());
    BFS bfs(graph);
    int componentIndex = 0;

    while (!unvisited.empty()) {
        Node* start = *unvisited.begin();
        std::set<Node*> component = bfs.getComponent(start);

        std::string fileName = prefix + std::to_string(componentIndex++) + ".txt";
        std::ofstream out(fileName);
        out << "Source\tTarget\n";

        for (Node* node : component) {
            for (auto it = node->nb_begin(); it != node->nb_end(); ++it) {
                if (component.count(*it) && node->getName() < (*it)->getName()) {
                    out << node->getName() << "\t" << (*it)->getName() << "\n";
                }
            }
        }

        for (Node* n : component) {
            unvisited.erase(n);
        }
    }
}