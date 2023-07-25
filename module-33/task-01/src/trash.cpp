#include "trash.h"
#include <exception>

void Trash::add(std::string name, int count)
{
    if (m_product.find(name) == m_product.end())
    {
        throw std::invalid_argument("name");
    }

    if (count < 0)
    {
        throw std::invalid_argument("count");
    }

    auto it = m_product.find(name);

    it->second += count;
}

void Trash::del(std::string name, int count)
{
    if (m_product.find(name) == m_product.end())
    {
        throw std::invalid_argument("name");
    }

    if (count < 0)
    {
        throw std::invalid_argument("count");
    }

    auto it = m_product.find(name);

    if (it->second < count)
    {
        throw std::invalid_argument("count");
    }

    it->second -= count;
}

Trash::Trash()
{
    m_product.emplace("banan", 1000);
    m_product.emplace("apple", 1500);
    m_product.emplace("orange", 500);
}
