#ifndef H_CSETGRAPH
#define H_CSETGRAPH

#include "IGraph.h"
#include <unordered_set>

class CSetGraph : public IGraph {
public:
	explicit CSetGraph(int vertexNum);
	CSetGraph(const IGraph* graph);
	~CSetGraph();
	int VerticesCount() const;
	void AddEdge(int from, int to);
	bool HasEdge(int from, int to);
	void GetNextVertices(int vertex, std::vector<int>& vertices) const;
	void GetPrevVertices(int vertex, std::vector<int>& vertices) const;
private:
	std::unordered_set<int>* adjLists;
	std::unordered_set<int>* adjListsReverse;
	int vertexCount;
};

#endif