#include "registry.h"


template<typename K, typename V>
void Registry<K, V>::add(RegistryKeyValue<K,V>& key_value)
{
    m_registry.push_back(key_value);
}

template<typename K, typename V>
void Registry<K, V>::remove(const K& key)
{    
    for(auto it = m_registry.begin(); it != m_registry.end(); it++)
    {
        if (it->m_key == key)
        {
            m_registry.erase(it);
        }

        if (m_registry.empty())
        {
            break;
        }
    }
}

template<typename K, typename V>
void Registry<K, V>::print()
{    
    for(auto it = m_registry.begin(); it != m_registry.end(); ++it)
    {
       std::cout << "Print Key: " << it->m_key << " Value: " << it->m_value << std::endl;
    }
}

template<typename K, typename V>
void Registry<K, V>::find(const K& key)
{    
    bool is_found = false;
    
    for(auto it = m_registry.begin(); it != m_registry.end(); ++it)
    {
        if (it->m_key == key)
        {
            std::cout << "Found Key: " << it->m_key << " Value: " << it->m_value << std::endl;

            is_found = true;
        }
    }

    if (!is_found) throw RegistryExceptionFind(); 
}