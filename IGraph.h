#ifndef H_IGRAPH
#define H_IGRAPH

//#include <iostream>
#include <vector>

class IGraph {
public:
	IGraph() {}
	IGraph(IGraph* graph);
	virtual ~IGraph() {}
	virtual void AddEdge(int from, int to) = 0;
	virtual int VerticesCount() const = 0;
	virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const = 0;
	virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const = 0;
	// virtual void PrintGraph() const;
};

//void IGraph::PrintGraph() const {
//	for (int i = 0; i < VerticesCount(); i++) {
//		std::cout << i + 1 << ": ";
//		std::vector<int> next;
//		GetNextVertices(i, next);
//		for (unsigned int j = 0; j < next.size(); j++)
//			std::cout << next[j] + 1 << " ";
//		std::cout << "\n";
//	}
//}

#endif