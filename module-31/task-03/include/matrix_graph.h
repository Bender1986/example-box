#pragma once

#include <unordered_set>
#include <vector>

#include "graph.h"


template<int size>
class MatrixGraph: public IGraph
{
    private:

    std::unordered_set<int> m_vertices;

    int m_matrix[size][size];

    public: 

    void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

    virtual ~MatrixGraph() override;
};


#include "matrix_graph.hpp"

