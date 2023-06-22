#include "dog.h"


Dog::Dog(const std::string& name): m_name{name}
{
    
}

void Dog::GetToy(std::shared_ptr<Toy>& toy) &
{    
    Toy* this_toy = m_toy.get();
    
    if (this_toy == toy.get())
    {
        std::cout << "I already have this toy" << std::endl;

        return;
    }

    m_toy = toy;

    if (m_toy.use_count() > 2)
    {
        std::cout << "Another dog is playing with this toy" << std::endl;

        return;
    }
}

void Dog::DropToy() &
{
    if (m_toy.get() == nullptr)
    {
        std::cout << "Nothing to drop" << std::endl;
    }

    m_toy.reset();
}
