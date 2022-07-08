#ifndef SWIM_H
#define SWIM_H

#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <map>
#include <atomic>
#include <iostream>
#include <map>




struct Swimmer
{
   const char* m_name;
   
   const int m_speed;

   Swimmer(const char* name, int speed): m_name{name}, m_speed{speed}{}      

};



class SwimWrapper
{   
    private:

    const int m_distance = 100;

    const int m_count = 6;
          
    std::vector<Swimmer> m_swimmer;

    std::atomic<bool> m_start;

    std::mutex mut;  

    std::multimap<double, std::string> m_result;  

    void process(const Swimmer& swimmer);

    

    public:

    SwimWrapper(const std::vector<Swimmer>& swimmers) noexcept;

    SwimWrapper(const SwimWrapper&  s) = delete;    
    SwimWrapper(SwimWrapper&& s) = delete;
    

    void Start();
    
};







#endif