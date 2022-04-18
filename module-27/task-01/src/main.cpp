#include <iostream>
#include <vector>
#include <ctime>

#include "elf.h"







int main(int, char**) {
    
    
    std::srand(std::time(nullptr));
    
    std::vector<Node*> trees[5];

    const int countTree = 5;

    for(int t = 0; t <countTree; t++ ) {

    /* Tree */
    std::string*  name = new std::string("Tree[" + std::to_string(t+1) + "]");
    
    Home* home = new Home(name);

    int countBigBranch = 3 + std::rand() % 3;
    
    Node* tree = new Node(home, nullptr, countBigBranch);


    for (int i = 0; i < countBigBranch; i++) {
        
        /* Big branch */
        std::string*  name = new std::string("elf_" + std::to_string(i));
                
        Home* home = new Home(name);

        int countSmallBranch = 2 + std::rand() % 2;

        Node* node0 = new Node(home, tree, countSmallBranch);        

        /* Small branch */
        for (int j = 0; j < countSmallBranch; j++) {
                        
            std::string*  name = new std::string("elf_" + std::to_string(i) + "_" + std::to_string(j));
            
            Home* home = new Home(name);

            (*node0)[j] = new Node(home, node0);
        }

        (*tree)[i] = node0; 
    }

    /* Add tree to trees */
    trees->push_back(tree);

    /* Print all nodes from tree */
    tree->printNodes();

    std::cout << std::endl;

    int countNeighbor = 0;

    /* Find node and neighbors */    
    if (tree->searchNode("elf_0_1", countNeighbor, tree))
    {
        std::cout << "Elf is found: elf_0_1" << std::endl;
        std::cout << "Count a neighbors: " << countNeighbor << std::endl;
    }

    std::cout << std::endl;

    tree->deleteNode();

    }

}
