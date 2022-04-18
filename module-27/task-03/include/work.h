#ifndef WORK_H
#define WORK_H

#include <iostream>
#include <vector>

enum class TaskType
{
    A = 65,
    B = 66,
    C = 67,

    N = 78
};


/* Class Worker */
class Worker {

    private:

    const std::string m_name;

    TaskType m_task;
     

    public: 

    Worker(std::string const name) : m_name{name}, m_task{TaskType::N} {

    }

    /* Get Name */
    std::string const& getName() const {
        return m_name;
    }

    /* Set Task */
    void setTask() {
        m_task = static_cast<TaskType>(65 + std::rand() % 3);
    }

    /* Get Task */
    const char getTask() const {
        return static_cast<char>(m_task);
    }
    
};


/* Class Manager */
class Manager {

    private:

    std::string m_name;

    int m_id;

    static int m_ID;
    
    public:

    Manager(std::string const& name): m_name{name} {
        m_id = ++m_ID;
    }

    const int& getID() const {
        return m_id;
    }

    const std::string& getName() const {
        return m_name;
    }
};

int Manager::m_ID = -1;



/* Class Team */
class Team {

    private:

    std::vector<Worker*>* m_workers;

    Manager* m_manager;

    int m_commandCurrent;
    
    public:

    Team(Manager* const& manager, std::vector<Worker*>* const& workers) : m_manager{manager}, m_workers{workers} {

    }

    ~Team()
    {
        for(const auto& worker: *m_workers) {
            delete worker;
        }
        
        delete m_workers;

        delete m_manager;
    }


    const int getCountWorkers() {
        return m_workers->size();
    }


    /* Get Manager */
    Manager* const& getManager() const {
        return m_manager;
    }

    /* Get Workers */
    std::vector<Worker*>* const& getWorkers() const {
        return m_workers;
    }

    /* Set current command */
    void setCommand(int commmand) {
       std::srand(commmand);
       
       m_commandCurrent =  std::rand() + m_manager->getID(); 
    }    

};





#endif