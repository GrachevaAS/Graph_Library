#ifndef H_ARCGRAPH
#define H_ARCGRAPH

#include "ClassGraph.h"

struct Edge {
    Edge(int begin, int end) : from(begin), to(end) {}
    ~Edge() {}
    int from;
    int to;
};

class CArcGraph : public IGraph {
public:
    explicit CArcGraph(int vertexNum);
    CArcGraph(const IGraph* graph);
    ~CArcGraph();
    int VerticesCount() const;
    void AddEdge(int from, int to);
    void GetNextVertices(int vertex, std::vector<int>& vertices) const;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const;
private:
    std::vector<Edge> edgesList;
};

#endif