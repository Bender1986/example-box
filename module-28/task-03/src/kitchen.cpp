#include "kitchen.h"


/* Cooking is Work.. */
Order KitchenWrapper::cooking(const Order& order)
{
    
    std::lock_guard loc(m_mut_cooking);


    std::this_thread::sleep_for(std::chrono::seconds(std::rand()%15 + 1));

    
    return Order{order.id, order.mess, true};   
}



/* Delivering is Work.. */
Order KitchenWrapper::delivery(const Order& order)
{       
    std::lock_guard loc(m_mut_delivery);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    return Order{order.id, order.mess, true};
}



/* Cooking Orders */
void KitchenWrapper::process_cooking()
{
    int count = 0;

    while(count < m_count)
    {
        if (!m_cookings.empty())
        {
            std::packaged_task<Order()> task_cooking;

            std::future<Order> fut_cooking;
            {
                std::lock_guard loc(m_mut_process_cooking);
                
                if (m_cookings.empty())
                continue;
                
                task_cooking = std::move(m_cookings.front());

                fut_cooking = task_cooking.get_future();

                m_cookings.pop();                
            }

            std::thread t_cooking(std::move(task_cooking));

            t_cooking.detach();

                        
            Order order = fut_cooking.get();

            log(order, 1);

            if (!order.complete)
            {
                std::cout << "Error processing order \n";
            }
            else 
            {               
                std::packaged_task<Order()> task_delivery(std::bind(&KitchenWrapper::delivery, this, Order{order.id, order.mess, false}));
                {
                    std::lock_guard loc(m_mut_process_delivery);

                    m_delivers.push(std::move(task_delivery));

                    log(order, 2);
                }
            }

            count++;
        }
    }
}



/* Delivery Orders */
void KitchenWrapper::process_delivery()
{
    int count = 0;
    
    while(count < m_count)
    {
        if (!m_delivers.empty())
        {
            std::packaged_task<Order()> task_delivery;

            std::future<Order> fut_delivery;
            {
                std::lock_guard loc(m_mut_process_cooking);
                
                if (m_delivers.empty())
                continue;
                
                task_delivery = std::move(m_delivers.front());

                fut_delivery = task_delivery.get_future();

                m_delivers.pop();                
            }

            std::thread t_delivery(std::move(task_delivery));

            t_delivery.detach();

            Order order = fut_delivery.get();

            if (!order.complete)
            {
                std::cout << "Error processing order \n";
            }
            else 
            {
               log(order, 3);
            }

            count++; 
        }
        
    }

    m_complete.set_value(true);
}



/* Recive Orders */
void KitchenWrapper::process_recive()
{
    int count = 0;

    while (count < m_count)
    {       
       std::this_thread::sleep_for(std::chrono::seconds(std::rand()%10 + 5));
       
        /* Create Task from Cooking */
        {
            std::lock_guard loc(m_mut_process_cooking);

            Order order = Order{count, std::rand()%4, false};
       
            std::packaged_task<Order()> task_cooking(std::bind(&KitchenWrapper::cooking, this, order));

            m_cookings.push(std::move(task_cooking));

            log(order, 0);
        }     

       count++;
    }
}



/* Start */
void KitchenWrapper::Start()
{   
      
    
    std::thread t_recive(&KitchenWrapper::process_recive, this);

    std::thread t_cooking(&KitchenWrapper::process_cooking, this);

    std::thread t_delivery(&KitchenWrapper::process_delivery, this);

   

    t_recive.detach();

    t_cooking.detach();

    t_delivery.detach();


    auto f = m_complete.get_future();
    
    f.wait();

    std::cout <<"All orders is complete!" << std::endl;

}


/* Logs */
void KitchenWrapper::log(const Order& order, int log_id)
{
    std::lock_guard loc(m_mut_log);

    time_t t = time(nullptr);

    tm* time = localtime(&t);

    std::cout << "Time: " << std::put_time(time, "%y/%m/%d %X") << ", Order ID = " << order.id << ", Mess = " << m_mess[order.mess];

    if (log_id == 0)
    {
        std::cout << " sent to the kitchen \n";
    }

    if (log_id == 1)
    {
        std::cout << " made \n";
    }

    if (log_id == 2)
    {
        std::cout << " sent to the delivery \n";
    }
    
    if (log_id == 3)
    {
        std::cout << " is complete! \n";
    }

}