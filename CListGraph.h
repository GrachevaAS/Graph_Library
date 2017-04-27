#ifndef H_CLISTGRAPH
#define H_CLISTGRAPH

#include "IGraph.h"

class CListGraph : public IGraph {
public:
	explicit CListGraph(int vertexNum);
	CListGraph(const IGraph* graph);
	~CListGraph();
	void AddEdge(int from, int to);
	int VerticesCount() const;
	void GetNextVertices(int vertex, std::vector<int>& vertices) const;
	void GetPrevVertices(int vertex, std::vector<int>& vertices) const;
private:
	std::list<int>* adjLists;
	std::list<int>* adjListsReverse;
	int vertexCount;
};

#endif