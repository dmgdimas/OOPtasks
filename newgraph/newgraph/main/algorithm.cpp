#include "algorithm.h"
#include <fstream>
#include <queue>
#include <set>
#include <vector>

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

std::vector<Graph*> BFS::getComponent(Node* start) {
    std::vector<Graph*> components;
    if (!start) return components;

    std::queue<Node*> q;
    std::set<Node*> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        Node* current = q.front(); q.pop();
        for (auto it = current->nb_begin(); it != current->nb_end(); ++it) {
            if (visited.find(*it) == visited.end()) {
                visited.insert(*it);
                q.push(*it);
            }
        }
    }
    Graph* componentGraph = new Graph();
    for (Node* node : visited) {
        componentGraph->addNode(node);
    }
    components.push_back(componentGraph);

    return components;
}


void writeGraph(const Graph& graph, const std::string& prefix) {
    std::set<Node*> unvisited(graph.begin(), graph.end());
    BFS bfs(graph);
    int componentIndex = 0;

    while (!unvisited.empty()) {
        Node* start = *unvisited.begin();
        std::vector<Graph*> componentGraphs = bfs.getComponent(start);

        for (Graph* comp : componentGraphs) {
            std::string fileName = prefix + std::to_string(componentIndex++) + ".txt";
            std::ofstream out(fileName);
            out << "Source\tTarget\n";

            
            for (Node* node : *comp) {
                for (auto it = node->nb_begin(); it != node->nb_end(); ++it) {
                    if (comp->contains(*it) && node->getName() < (*it)->getName()) {
                        out << node->getName() << "\t" << (*it)->getName() << "\n";
                    }
                }
            }

            for (Node* n : *comp) {
                unvisited.erase(n);
            }

            delete comp;  
        }
    }
}
