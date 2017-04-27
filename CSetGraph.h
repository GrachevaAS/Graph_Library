#ifndef H_CSETGRAPH
#define H_CSETGRAPH

#include "ClassGraph.h"

class CSetGraph : public IGraph {
public:
	explicit CSetGraph(int vertexNum);
	CSetGraph(const IGraph* graph);
	~CSetGraph();
	int VerticesCount() const;
	void AddEdge(int from, int to);
	void GetNextVertices(int vertex, std::vector<int>& vertices) const;
	virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const;
private:
	std::unordered_set<int>*  adjLists;
	std::unordered_set<int>* adjListsReverse;
};

#endif