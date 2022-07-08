#ifndef KITCHEN_H
#define KITCHEN_H

#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <ctime>
#include <iomanip>



struct Order
{
    int id;

    int mess;

    bool complete;
};



class KitchenWrapper
{

    private:
    
    const int m_count = 10;

    const std::string m_mess[5] = {"PIZZA", "SOUP", "STEAK", "SALAD", "SUSHI"};
    
    std::mutex m_mut_process_cooking;
    std::mutex m_mut_process_delivery;

    std::mutex m_mut_cooking;
    std::mutex m_mut_delivery;

    std::mutex m_mut_log;

    std::promise<bool> m_complete;


    std::queue<std::packaged_task<Order()>> m_cookings;

    std::queue<std::packaged_task<Order()>> m_delivers;


    /* Processing Cooking */
    void process_recive();

    /* Processing Cooking */
    void process_cooking();

    /* Processing Orders */
    void process_delivery();


    /* Processing Cooking */
    Order cooking(const Order& order);

    /* Processing Delivery */
    Order delivery(const Order& order);


    /* Log */
    void log(const Order& order, int log_id);
    
   

    public:

    KitchenWrapper() = default;

    KitchenWrapper(KitchenWrapper&& kw) = delete;
    
    void Start();
    
};







#endif