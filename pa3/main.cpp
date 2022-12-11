#include <fstream>
#include "graph.h"
#include "edge.h"

int main(int argc, char const *argv[])
{
    ifstream input(argv[1]);

    char direct;
    input >> direct;
    Graph graph(input);

    graph.printGraph();
    return 0;
}
