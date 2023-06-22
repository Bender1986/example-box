#include "my_shared_ptr.h"

template<typename T>
MySharedPtr::MySharedPtr<T>::MySharedPtr(T* resource) : m_count_ref{new int()}, m_resource{resource}
{
    *m_count_ref = 1;
}

template<typename T>
MySharedPtr::MySharedPtr<T>::MySharedPtr(const MySharedPtr& other): 
m_count_ref{other.m_count_ref}, m_resource{other.m_resource}
{
    (*m_count_ref)++; 
}

template<typename T>
MySharedPtr::MySharedPtr<T>& MySharedPtr::MySharedPtr<T>::operator = (const MySharedPtr& other)
{
    m_count_ref = other.m_count_ref;
    m_resource = other.m_resource;
    
    (*m_count_ref) ++;

    return *this; 
}

template<typename T>
MySharedPtr::MySharedPtr<T>::MySharedPtr(MySharedPtr&& other): 
m_count_ref{other.m_count_ref}, m_resource{other.m_resource}
{
     
}

template<typename T>
MySharedPtr::MySharedPtr<T>& MySharedPtr::MySharedPtr<T>::operator = (MySharedPtr&& other)
{
    m_count_ref = other.m_count_ref;
    m_resource = other.m_resource;
    
    return *this; 
}

template<typename T>
MySharedPtr::MySharedPtr<T>::~MySharedPtr()
{
    (*m_count_ref)--;

    if (*m_count_ref == 0)
    {
        delete m_resource;
        delete m_count_ref;
    } 
}

template<typename T>
T* MySharedPtr::MySharedPtr<T>::get()
{
  return m_resource;
}

template<typename T>
int MySharedPtr::MySharedPtr<T>::count()
{
  return *m_count_ref;  
}

template<typename T>
T* MySharedPtr::MySharedPtr<T>::operator -> ()
{
  return m_resource;  
}