#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include "edge.h"

using namespace std;

class Graph {
public:
    friend class PrimMST;
    Graph(istream &f) {
        f >> V;
        f >> E;
        adj = new vector<vector<int> >(V, vector<int>());

        for (int i = 0; i < E; i++) {
            int v, w, weight;
            f >> v >> w >> weight;
            Edge *e = new Edge(v, w, weight);
            addEdge(e);
        }
    }
    void printGraph() {
        for (int i = 0; i < V; i++) {
            if ((*adj)[i].size())
                cout << i << ": ";
            for (int j = 0; j < (*adj)[i].size(); j++) {
                cout << (*adj)[i][j] << " ";
            }
            if ((*adj)[i].size())
                cout << endl;
        }
    }

private:
    void addEdge(Edge *e) {
        int v = e->either();
        int w = e->other(v);
        (*adj)[v].push_back(w);
        (*adj)[w].push_back(v);
    }
    int V;
    int E;
    vector<vector<int> > *adj;
};