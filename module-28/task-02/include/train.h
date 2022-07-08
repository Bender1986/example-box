#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>



class TrainWrapper
{

    private:

    const char m_names[3] = {'A', 'B', 'C'};

    int m_times[3] = {1, 5, 3};

    std::mutex m_mut;
    
    
    /* Movement Trains */
    void train_movement(char name, int time);
    

    public:

    /* Initialize */
    TrainWrapper(const std::vector<int>& times); 

    /* Delete default operation Copy, Move */
    TrainWrapper(TrainWrapper&& t) = delete;
    

    /* Start movement trains  */
    void Start();




};







#endif