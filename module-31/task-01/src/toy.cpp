#include "toy.h"

Toy::Toy(const std::string& name): m_name {name}
{
    
}

Toy::~Toy()
{
    std::cout << "Toy " << m_name << " was dropped " << std::endl;
}

std::string Toy::GetName()
{
    return m_name;
}