#ifndef H_CMATRIXGRAPH
#define H_CMATRIXGRAPH

#include "IGraph.h"

class CMatrixGraph : public IGraph {
public:
	explicit CMatrixGraph(int vertexNum);
	CMatrixGraph(const IGraph* graph);
    ~CMatrixGraph();
    void AddEdge(int from, int to);
    int VerticesCount() const;
    void GetNextVertices(int vertex, std::vector<int>& vertices) const;
    virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const;
private:
    bool** Matrix;
	int vertexCount;
};

#endif