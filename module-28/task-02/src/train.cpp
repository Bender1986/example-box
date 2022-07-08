#include "train.h"



void TrainWrapper::train_movement(char name, int time)
{

    std::this_thread::sleep_for(std::chrono::seconds(time));

    std::cout << "Train " << name << " at the station and is wait \n";
   
    std::lock_guard loc(m_mut);
    
    std::string command;

    std::cout << "Input command [-depart]: \n";
    
    while (command != "depart")
    {
        std::cin >> command;

        if (command != "depart")
        {
            std::cout << "Unknow command\n";
        }
    }

    std::cout << "Train " << name << " left the station \n";

}



TrainWrapper::TrainWrapper(const std::vector<int>& times)
{
    if (times.size() == 3)
    {
        for(int i = 0; i < times.size(); i++)
        {
            m_times[i] = times[i];
        }
    }
}




void TrainWrapper::Start()
{

    std::vector<std::thread> vec_t;//(0, std::thread());
    

    for (int i = 0; i < 3; ++i)
    {
        vec_t.emplace_back(std::thread(&TrainWrapper::train_movement, this, m_names[i], m_times[i]));
    }

    for(auto& it: vec_t)
    {
        it.join();
    }




}