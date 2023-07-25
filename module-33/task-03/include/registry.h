#ifndef REG_H
#define REG_H

#include <iostream>
#include <map>
#include <vector>


template<typename K, typename V>
struct RegistryKeyValue
{
    public:
    K m_key;
    V m_value;
};


template<typename K, typename V>
class Registry
{    
    private:

    std::vector<RegistryKeyValue<K, V>> m_registry;

    
    public:

    Registry() = default;
    Registry(const Registry&) = delete;
    Registry(Registry&&) = delete;


    void add(RegistryKeyValue<K,V>& key_value);
    void remove(const K& key);
    void print();
    void find(const K& key);
};

class RegistryExceptionAdd: public std::exception
{
    public:
    const char* what() const noexcept override;
};

class RegistryExceptionRemove: public std::exception
{
    public:
    const char* what() const noexcept override;
};

class RegistryExceptionPrint: public std::exception
{
    public:
    const char* what() const noexcept override;
};

class RegistryExceptionFind: public std::exception
{
    public:
    const char* what() const noexcept override
    {
        return "Not found";    
    }
};


#include "registry.hpp"

#endif