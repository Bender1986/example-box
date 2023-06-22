#include <iostream>
#include <vector>
#include <memory>

#include "graph.h"
#include "matrix_graph.h"
#include "list_graph.h"

class GraphControl
{
    private:

    std::shared_ptr<IGraph> m_graph_ptr;    

    public:

    GraphControl(IGraph* graph)
    {
       m_graph_ptr = std::shared_ptr<IGraph>(graph);
    } 

    void add_edge(int from, int to)
    {
        if (m_graph_ptr.get() == nullptr)
        {
            return;
        }

        m_graph_ptr->AddEdge(from, to);
    }
    
    void print_vertices_count()
    {
        if (m_graph_ptr.get() == nullptr)
        {
            return;
        }
        
        std::cout << "Vertices count this graph:" << m_graph_ptr->VerticesCount() << std::endl;
    }


    void print_vertices_next(int vertex)
    {        
        if (m_graph_ptr.get() == nullptr)
        {
            return;
        }        
        
        std::vector<int> vec;
        
        m_graph_ptr->GetNextVertices(vertex, vec);

        std::cout << "Vertex next [" << vertex << "]: " << std::endl;

        for(const auto& it: vec)
        {
            std::cout << it << std::endl;
        }    
    }


    void print_vertices_prev(int vertex)
    {
        if (m_graph_ptr.get() == nullptr)
        {
            return;
        }
        
        std::vector<int> vec;
        
        m_graph_ptr->GetPrevVertices(vertex, vec);

        std::cout << "Vertex prev [" << vertex << "]: " << std::endl;

        for(const auto& it: vec)
        {
            std::cout << it << std::endl;
        }    
    }
};




int main(int, char**){

      
    GraphControl graph_control_matrix(new MatrixGraph<10>());
    
    graph_control_matrix.add_edge(1, 1);
    graph_control_matrix.add_edge(1, 2);
    graph_control_matrix.add_edge(3, 1);  
    graph_control_matrix.add_edge(2, 3);       

    graph_control_matrix.print_vertices_count();
    graph_control_matrix.print_vertices_next(1);
    graph_control_matrix.print_vertices_prev(3);       
    

    GraphControl graph_control_list(new ListGraph());
    
    graph_control_list.add_edge(1, 1);
    graph_control_list.add_edge(1, 2);
    graph_control_list.add_edge(3, 1);  
    graph_control_list.add_edge(2, 3);       

    graph_control_list.print_vertices_count();
    graph_control_list.print_vertices_next(1);
    graph_control_list.print_vertices_prev(3);  
}
