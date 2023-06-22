#pragma once

#include <iostream>

class Toy
{
    private:

    std::string m_name;

    public: 

    Toy(const std::string& name);

    Toy(const Toy&) = delete;
    Toy(Toy&&) = delete;
    Toy& operator = (const Toy&) = delete;
    Toy& operator = (Toy&&) = delete;

    ~Toy();

    std::string GetName();    
};