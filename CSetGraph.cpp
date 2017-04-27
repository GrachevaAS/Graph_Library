#include <vector>
#include <unordered_set>
#include <assert.h>
#include "CSetGraph.h"

CSetGraph::CSetGraph(int vertexNum) {
	vertexCount = vertexNum;
	adjLists = new std::unordered_set<int>[vertexNum];
	adjListsReverse = new std::unordered_set<int>[vertexNum];
}

CSetGraph::CSetGraph(const IGraph* graph): CSetGraph(graph->VerticesCount()) {
	std::vector<int> temp;
	for (int i = 0; i < vertexCount; i++) {
		graph->GetNextVertices(i, temp);
		for (int j = 0; j < temp.size(); j++)
			this->AddEdge(i, temp[j]);
		temp.clear();
	}
}

CSetGraph::~CSetGraph() {
	delete[] adjLists;
	delete[] adjListsReverse;
}

int CSetGraph::VerticesCount() const {
	return vertexCount;
}

void CSetGraph::AddEdge(int from, int to) {
	edgesCount++;
	adjLists[from].insert(to);
	adjListsReverse[to].insert(from);
}

void CSetGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
	for (std::unordered_set<int>::const_iterator it = adjLists[vertex].begin(); it != adjLists[vertex].end(); it++) {
		vertices.push_back(*it);
	}
}
void CSetGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
	for (std::unordered_set<int>::const_iterator it = adjListsReverse[vertex].begin(); it != adjListsReverse[vertex].end(); it++) {
		vertices.push_back(*it);
	}
}