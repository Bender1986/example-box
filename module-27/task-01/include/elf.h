#ifndef ELF_H
#define ELF_H

#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>

class Home {

    private:

    const std::string* m_name;

    public:

    Home(const std::string* name = new std::string("None")): m_name{name} {

    }

    const char* getName() const {
        return m_name->c_str();
    }

    ~Home() {
        delete m_name;
    }       

};


class Node {

    private:

    Node* m_parent = nullptr;
    Node** m_child = nullptr;

    Home* m_home = nullptr;

    int m_idx = 0;
    const int m_max;
    
  
    public:

    Node(Home* home, Node* parent = nullptr, int max = 0): m_max{max}, m_parent{parent}, m_home{home} {
        
        if (m_max == 0)
            return;
        

        m_child = new Node*[m_max];

        for (int i = 0; i < m_max; i++) {
            m_child[i] = nullptr;
        }
    } 

    

    ~Node() {
        
        delete m_home;

        delete[] m_child;                
    }

    
    Node*& operator[] (const int idx) {
        
        assert(idx >= 0 && idx < m_max);

        return m_child[idx];
    }

    const Node* const& operator[] (const int idx) const {
        
        assert(idx >= 0 && idx < m_max);

        return m_child[idx];
    }

    /* Get count */
    const int& getCount() const {
        return m_max;
    }

    /* Get child */
    const Node* const* getChild() const {
        return m_child;
    } 

    /* Get parent */
    Node const* getParent() const {
        return m_parent;
    } 


    /* Print All Node */
    void printNodes(Node* node = nullptr);


    /* Search Node */
    bool searchNode(const char* name, int& countNeighbor, Node* node); 


    /* Delete All Nodes */
    void deleteNode(Node* node = nullptr); 

};



#endif
