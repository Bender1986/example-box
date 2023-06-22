#pragma once

#include <unordered_set>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

#include "graph.h"

class ListGraph: public IGraph
{
    private:

    std::map<int, std::vector<int>> m_list;

    public:

    ListGraph();
    
    void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

    virtual ~ListGraph() override;
};