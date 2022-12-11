#pragma once
#include <exception>
using namespace std;

class Edge {
public:
    Edge(int v, int w, int weight) : v(v), w(w), weight(weight) {}
    int getWeight() {return weight;}
    int either() {return v;}
    int other(int vertex) {
        if (vertex == v)
            return w;
        else if (vertex == w)
            return v;
        else
            throw "other failed.";
    }
    bool operator<(const Edge &edge) const {
        return weight < edge.weight;
    }
    bool operator==(const Edge &edge) const {
        return (edge.v == v) && (edge.w == w) && (edge.weight == weight);
    }

private:
    int v;
    int w;
    int weight;
};