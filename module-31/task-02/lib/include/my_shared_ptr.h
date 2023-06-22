#pragma once

#include <iostream>
#include <initializer_list>

namespace MySharedPtr
{
    template<typename T>
    class MySharedPtr
    {
        private:
            int* m_count_ref;
            T* m_resource;

        public:
        
        MySharedPtr(T* resource);
        
        MySharedPtr(const MySharedPtr& other);
        MySharedPtr& operator = (const MySharedPtr& other);   

        MySharedPtr(MySharedPtr&& other);
        MySharedPtr& operator = (MySharedPtr&& other);

        ~MySharedPtr();

        T* get();
        int count();
        T* operator ->();
    };

   
    template<typename T, typename ... Args>
    MySharedPtr<T> make_shared(Args ... args)
    {
       T* t = new T(args...);

       MySharedPtr<T> n(t);
       
       return n;
    }
}

#include "my_shared_ptr.hpp"



