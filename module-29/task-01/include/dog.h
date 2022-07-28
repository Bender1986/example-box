#ifndef DOG_H
#define DOG_H


#include <iostream>
#include <vector>



/* Interface talent behavior */
class ITalentBehavior
{

    public:

    /* Exicute talent */ 
    virtual void talent_exicute() const noexcept = 0;

};


/* Swimming */
class TalentSwim: public ITalentBehavior
{

    public:

    void talent_exicute() const noexcept override
    {
        std::cout << "Swim" << std::endl;
    }
};


/* Dancing */
class TalentDance: public ITalentBehavior
{

    public:

    void talent_exicute() const noexcept override
    {
        std::cout << "Dance" << std::endl;
    }
};



/* Counting */
class TalentCount: public ITalentBehavior
{

    public:

    void talent_exicute() const noexcept override
    {
        std::cout << "Count" << std::endl;
    }
};



/* Class Animal */
class Animal
{

    protected:

    const std::string m_name;

    std::vector<ITalentBehavior const*> m_talents;

    public:

    Animal(const std::string& name) noexcept : m_name{name}{};

    Animal(Animal&&) noexcept = delete;

    virtual void voice() noexcept = 0;

    void add_talent(ITalentBehavior const* talent);

    void show_talents() const &;

    void show_talents() const &&;

    ~Animal() noexcept;
};




/* Class Dog */
class Dog: public Animal
{

    public: 

    Dog(const std::string& name): Animal::Animal(name){}; 

    virtual void voice() noexcept override;
};












#endif