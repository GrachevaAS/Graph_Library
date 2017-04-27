#include <iostream>
#include <vector>
#include <assert.h>
#include "CMatrixGraph.h"

CMatrixGraph::CMatrixGraph(int vertexNum) {
    vertexCount = vertexNum;
    Matrix = new bool*[vertexCount];
    Matrix[0] = new bool[vertexCount * vertexCount];
    for (int i = 1; i < vertexCount; i++) {
        Matrix[i] = Matrix[i - 1] + vertexCount;
    }
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            Matrix[i][j] = false;
        }
    }
}

CMatrixGraph::CMatrixGraph(const IGraph* graph): CMatrixGraph(graph->VerticesCount()) {
    std::vector<int> temp;
    for (int i = 0; i < vertexCount; i++) {
        graph->GetNextVertices(i, temp);
        for (unsigned int j = 0; j < temp.size(); j++) {
            this->AddEdge(i, temp[j]);
        }
        temp.clear();
    }

}

CMatrixGraph::~CMatrixGraph() {
    delete[] Matrix[0];
    delete[] Matrix;
}

int CMatrixGraph::VerticesCount() const {
    return vertexCount;
}

void CMatrixGraph::AddEdge(int from, int to) {
    if (!Matrix[from][to]) {
        Matrix[from][to] = true;
    }
}

void CMatrixGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
    for (int i = 0; i < vertexCount; i++) {
        if (Matrix[vertex][i])
            vertices.push_back(i);
    }
}
void CMatrixGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
    for (int i = 0; i < vertexCount; i++) {
        if (Matrix[i][vertex])
            vertices.push_back(i);
    }
}
