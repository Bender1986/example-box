#include "elf.h"



/* Print All Node */
void Node::printNodes(Node* node) {

        if (node == nullptr) {
            node = this;
        }
                
        Node** child = node->m_child;
        int max = node->m_max;


        if (node->m_home!=nullptr) {
            std::cout << node->m_home->getName() << std::endl;
        }
                

        if (child!= nullptr) {
            for (int i = 0; i < max; i++) {
                printNodes(child[i]);
            }
        }
        
    }


/* Search Node */
bool Node::searchNode(const char* name, int& countNeighbor, Node* node){

        if (node == nullptr) {
            node = this;
        }
                
        Node** child = node->m_child;
        int max = node->m_max;
        
        if (node->m_home != nullptr) {
            
            if (std::strcmp(node->m_home->getName(), name) == 0) {
                
                if (node->getParent()->m_home == nullptr) {
                    countNeighbor += node->m_max;
                }
                else {
                    countNeighbor =+ node->m_parent->m_max;
                }

                return true;
            }
        }

        if (child!= nullptr) {
            for (int i = 0; i < max; i++) {
                if (searchNode(name, countNeighbor, child[i]))
                  return true;
            }
        }

        return false;
    }       


/* Delete All Nodes */
void Node::deleteNode(Node* node){

        if (node == nullptr) {
            node = this;
        }
                
        Node** child = node->m_child;
        int max = node->m_max;


        if (child == nullptr) {            
            std::cout << "Node " << node->m_home->getName() << " is delete" << std::endl;            
            delete node;            
            return;
        }


        if (child!= nullptr) {
            for (int i = 0; i < max; i++) {
                deleteNode(child[i]);
            }
        }

        std::cout << "Node " << node->m_home->getName() << " is delete" << std::endl;
        delete node;

    }