#include <iostream>

#include <vector>
#include <list>
#include <assert.h>
#include "CListGraph.h"

CListGraph::CListGraph(int vertexNum) {
	vertexCount = vertexNum;
	adjLists = new std::list<int>[vertexCount];
	adjListsReverse = new std::list<int>[vertexCount];
}

CListGraph::CListGraph(const IGraph* graph): CListGraph(graph->VerticesCount()) {
	std::vector<int> temp;
	for (int i = 0; i < vertexCount; i++) {
		graph->GetNextVertices(i, temp);
		for (int j = 0; j < temp.size(); j++) {
			this->AddEdge(i, temp[j]);
		}
		temp.clear();
	} 
}

CListGraph::~CListGraph() {
	delete[] adjLists;
	delete[] adjListsReverse;
}

int CListGraph::VerticesCount() const {
	return vertexCount;
}

void CListGraph::AddEdge(int from, int to) {
	edgesCount++;
	adjLists[from].push_back(to);
	adjListsReverse[to].push_back(from);
}

void CListGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
	for (std::list<int>::const_iterator it = adjLists[vertex].begin(); it != adjLists[vertex].end(); it++) {
		vertices.push_back(*it);
	}
}

void CListGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
	for (std::list<int>::const_iterator it = adjListsReverse[vertex].begin(); it != adjListsReverse[vertex].end(); it++) {
		vertices.push_back(*it);
	}
}
