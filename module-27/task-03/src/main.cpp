#include <iostream>
#include <ctime>
#include <vector>
#include "work.h"


/* Create Teams */
std::vector<Team*>* const createTeams(const int& countTeams)
{            
    std::vector<Team*>* teams = new std::vector<Team*>();

    for(int i = 0; i < countTeams; i++) {

        std::vector<Worker*>* vecWorkers = new std::vector<Worker*>();
        
        int countWorkers = 3 + std::rand() % 7;

        for (int j = 0; j < countWorkers; j++) {
            
                       
            Worker* worker = new Worker("Worker[" + std::to_string(i) + "_" + std::to_string(j) + "]");

            (*vecWorkers).push_back(worker);
        }

        Manager* manager = new Manager{"Manager[" + std::to_string(i) + "]"};
        
        Team* team = new Team{manager, vecWorkers};

        (*teams).push_back(team);
    }

    return teams;
}




/* Print All Teams */
void printTeams(std::vector<Team*>* const& teams) {
    std::cout<<"Teams count: "<< teams->size() << std::endl;
    
    for(const auto& team: *teams)
    {
        std::cout<< std::endl; 

        /* Print Manager */        
        std::cout << "Name: " << team->getManager()->getName() << " ID: "<< team->getManager()->getID()<<std::endl;
        std::cout << "      Workers("<< team->getCountWorkers()<<"):" << std::endl;


        /* Print Workers */         
        for(const auto& worker: *(team->getWorkers()))
        {
            std::cout<<"        "<< worker->getName() <<"   Task: " << worker->getTask() <<  std::endl;
        }                   
    }
}

/* Delete Teams */
void deleteTeams(std::vector<Team*>* const& teams) {

    for(const auto& team : *teams){ 
        delete team;
    }
}


int main(int, char**) {
    
          
    std::srand(std::time(nullptr));

    const int countTeams = std::rand() % 5;


    std::vector<Team*>* teams = createTeams(countTeams);       


    printTeams(teams);

    int command = -1;

    while(command != 0)
    {
        std::cout << "Input command top manager (0 - exit): ";
        std::cin >> command;

        if (command == 0)
            break;
        

        for(const auto& team: *teams)
        {
            team->setCommand(command);

            int countTask = std::rand() % (team->getCountWorkers() + 1);

            for(const auto& worker: *team->getWorkers())
            {
                countTask--;
                if (countTask == 0)
                    break;

                worker->setTask();
            }
        }

        printTeams(teams);

    }


    /* Clear Heap Memory */
    deleteTeams(teams);

}
