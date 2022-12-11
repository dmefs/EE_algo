#pragma once
#include <queue>
#include <limits>
#include "graph.h"

using namespace std;

class PrimMST {
public:
    PrimMST(Graph graph) {
        this->graph = graph;
        distTo = new vector<int>(graph.V, 0);
        edgeTo = new vector<int>(graph.V, 0);
        marked = new vector<int>(graph.V, 0);

        setDistancesToInfinityExceptS(0);
    }

    ~PrimMST() {
        delete distTo;
        delete edgeTo;
        delete marked;
    }
private:
    void setDistancesToInfinityExceptS(int s) {
        for (int i = 0; i < graph.V; i++) {
            fringe.push_back({i, numberic_limits<int>::max()});
        }
    }
    Graph graph;
    vector<int> *distTo, *edgeTo, *marked;
    priority_queue<pair<int, int>> fringe;
};
