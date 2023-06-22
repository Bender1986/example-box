#pragma once

#include <iostream>
#include <memory>
#include "toy.h"

class Dog
{
    private: 
    
    std::string m_name;
    std::shared_ptr<Toy> m_toy;
    
    public:

    Dog(const std::string& name);

    Dog(const Dog&) = delete;
    Dog(Dog&&) = delete;
    Dog& operator = (const Dog&) = delete;
    Dog& operator = (Dog&&) = delete;

    void GetToy(std::shared_ptr<Toy>& toy) &;
    void DropToy() &;
};