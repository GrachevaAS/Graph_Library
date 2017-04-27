#include "CArcGraph.h"

CArcGraph::CArcGraph(int vertexNum) {
	vertexCount = vertexNum;
}

CArcGraph::CArcGraph(const IGraph* graph) {
	std::vector<int> temp;
	vertexCount = graph->VerticesCount();
	for (int i = 0; i < vertexCount; i++) {
		graph->GetNextVertices(i, temp);
		for (int j = 0; j < temp.size(); j++) {
			Edge newEdge(i, temp[j]);
			edgesList.push_back(newEdge);
		}
		temp.clear();
	}

}

CArcGraph::~CArcGraph() {}

int CArcGraph::VerticesCount() const {
	return vertexCount;
}

void CArcGraph::AddEdge(int from, int to) {
	Edge temp(from, to);
	edgesList.push_back(temp);
}

void CArcGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
	for (int i = 0; i < edgesList.size(); i++) {
		if (edgesList[i].from == vertex)
			vertices.push_back(edgesList[i].to);
	}
}
void CArcGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
	for (int i = 0; i < edgesList.size(); i++) {
		if (edgesList[i].to == vertex)
			vertices.push_back(edgesList[i].from);
	}
}