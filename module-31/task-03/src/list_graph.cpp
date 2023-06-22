#include "list_graph.h"



void ListGraph::AddEdge(int from, int to)
{  
    if (from < 1 || to < 1)
        return;   
   
    
    m_list.emplace(from, std::vector<int>());
    

    m_list[from].push_back(to);    
}


int ListGraph::VerticesCount() const
{  
    return m_list.size();
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
{  
    auto it = m_list.find(vertex);

    if (it == m_list.end())
        return;  
    
    for(const auto& elem: it->second)
    {
        vertices.push_back(elem);
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const
{  
    for(const auto& it: m_list)
    {
        if (std::find(it.second.begin(), it.second.end(), vertex) != it.second.end())
        {
            vertices.push_back(it.first);
        }        
    }
}

ListGraph::ListGraph()
{

}

ListGraph::~ListGraph()
{
    std::cout << "ListGraph is destroyed" << std::endl;
}
