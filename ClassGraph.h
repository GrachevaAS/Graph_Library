#ifndef H_IGRAPH
#define H_IGRAPH

#include <vector>

class IGraph {
public:
	//IGraph();
	IGraph() : vertexCount(0), edgesCount(0) {}
	IGraph(IGraph* graph);
	virtual ~IGraph() {}

	virtual void AddEdge(int from, int to) = 0;
	virtual int VerticesCount() const = 0;
	virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const = 0;
	virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const = 0;

protected:
	int vertexCount;
	int edgesCount;
};

#endif