#include "swim.h"



SwimWrapper::SwimWrapper(const std::vector<Swimmer>& swimmers) noexcept
{
       
    if (swimmers.size() != m_count)
        m_swimmer = std::vector<Swimmer>(m_count, Swimmer{"no name", 1});

    else 
    {    
        for(const auto& it: swimmers) 
        {
           m_swimmer.push_back(it);
        }
    }   
    

    m_start = false;

};


void SwimWrapper::process(const Swimmer& swimmer)
{
    
    while(!m_start.load())
    {}

    int s = 0;

    while(s < m_distance)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        
        s += swimmer.m_speed;

        if (s > m_distance)
            s = m_distance;

        
        /* Lock */
        mut.lock();
        
        std::cout << swimmer.m_name << " distance is " << s << std::endl;
        
        mut.unlock();    
    }


    std::lock_guard lk(mut);

    m_result.emplace(m_distance / swimmer.m_speed, swimmer.m_name);

};




void SwimWrapper::Start()
{
    std::vector<std::thread> vec_t;
    
    for(int i = 0; i < m_count; i++)
    {
        vec_t.emplace_back(&SwimWrapper::process, this, m_swimmer[i]);
    }
    

    m_start.store(true);


    for (auto& it: vec_t)
    {
        it.join();
    }


    /* Print result */
    std::cout << "\n Results: \n";
    for (const auto& it: m_result)
    {
       std::cout << "Name : " << it.second << " time: " << it.first << std::endl;
    }

};