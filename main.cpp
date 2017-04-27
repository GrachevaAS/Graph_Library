#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include "ClassGraph.h"
#include "CListGraph.h"
#include "CMatrixGraph.h"
#include "CSetGraph.h"
#include "CArcGraph.h"

int main() {
    int vertex = 0;
    int edges = 0;
    std::cin >> vertex;
    std::cin >> edges;
    int from, to = 0;
    CArcGraph test(vertex);
    for (int i = 0; i < edges; i++) {
        std::cin >> from >> to;
        test.AddEdge(from, to);
    }
    CMatrixGraph test2(&test);
    std::vector<int> testArr;

    std::cout << "getNext: ";
    std::cin >> from;
    test.GetNextVertices(from, testArr);
    for (int i = 0; i < testArr.size(); i++)
        std::cout << testArr[i] << " ";
    testArr.clear();

    std::cout << "getPrev: ";
    std::cin >> to;
    test.GetPrevVertices(to, testArr);
    for (int i = 0; i < testArr.size(); i++)
        std::cout << testArr[i] << " ";
    testArr.clear();

    std::cout << "getNext: ";
    std::cin >> from;
    test2.GetNextVertices(from, testArr);
    for (int i = 0; i < testArr.size(); i++)
        std::cout << testArr[i] << " ";
    testArr.clear();

    std::cout << "getPrev: ";
    std::cin >> to;
    test2.GetPrevVertices(to, testArr);
    for (int i = 0; i < testArr.size(); i++)
        std::cout << testArr[i] << " ";

    return 0;
}

