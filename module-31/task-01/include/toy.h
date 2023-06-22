#pragma once

#include <iostream>

class Toy
{
    private:

    std::string m_name;

    public: 

    Toy(const std::string& name);

    ~Toy();

    std::string GetName();    
};