#include "dog.h"


/* Add talent */
void Animal::add_talent(ITalentBehavior const* talent)
{
    m_talents.push_back(talent);
}



/* Show talants l */
void Animal::show_talents() const &
{   
    std::cout << m_name << " it has some talents: \n";
    
    for(const auto& it: m_talents)
    {
        it->talent_exicute();
    }
}

/* Show talants r */
void Animal::show_talents() const &&
{  
    std::cout << m_name << " it has some no talents: \n";
}

/* Destroy */
Animal::~Animal() noexcept
{   
    std::cout<< "Destroy " << m_name << std::endl;

    for(const auto& it: m_talents)
    {
       delete it;
    }
}




/* Voice */
void Dog::voice() noexcept
{
    std::cout << "Gav!" << std::endl;
}


