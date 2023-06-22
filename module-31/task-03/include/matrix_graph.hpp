#include "matrix_graph.h"


template<int size>
void MatrixGraph<size>::AddEdge(int from, int to)
{  
    if (from < 1 || from > size || to < 1 || to > size)
        return;
    
    m_vertices.emplace(from);
    m_vertices.emplace(to);

    m_matrix[--from][--to] = 1;
}


template<int size>
int MatrixGraph<size>::VerticesCount() const
{  
    return m_vertices.size();
}

template<int size>
void MatrixGraph<size>::GetNextVertices(int vertex, std::vector<int> &vertices) const
{  
    if (vertex < 1 || vertex > size)
        return;
    
    for (int j = 0; j < size; j++)
    {
        if (m_matrix[vertex - 1][j] == 1)
        {
            vertices.push_back(j + 1);
        }
    }
}

template<int size>
void MatrixGraph<size>::GetPrevVertices(int vertex, std::vector<int> &vertices) const
{  
    if (vertex < 1 || vertex > size)
        return;
    
    for (int i = 0; i < size; i++)
    {
        if (m_matrix[i][vertex - 1] == 1)
        {
            vertices.push_back(i + 1);
        }
    }
}

template<int size>
MatrixGraph<size>::~MatrixGraph()
{
    std::cout << "MatrixGraph is destroyed" << std::endl;
}

