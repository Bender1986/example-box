#ifndef TRASH_H
#define TRASH_H

#include <iostream>
#include <map>


class Trash
{
    private:

    std::map<std::string, int> m_product;    
    
    public:

    Trash();


    void add(std::string name, int count);
    void del(std::string name, int count);
};




#endif