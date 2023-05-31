#include <iostream>
#include <cpr/cpr.h>


class HTTPCommandTest
{        
    private:

    const std::string m_url_string = "http://httpbin.org";

    public:
        

    void display_request_get()
    {
        cpr::Response r = cpr::Get(cpr::Url(m_url_string + "/get"));

        std::cout<< r.text << std::endl;
    }

    void display_request_post()
    {
        std::string name = "noname";
        std::string city = "Rio";

        cpr::Response r = cpr::Post(cpr::Url(m_url_string + "/post"), 
                                    cpr::Payload({{"name", name.c_str()},{"city", city.c_str()}}));
        
        std::cout<< r.text << std::endl;
    }

    void display_request_put()
    {
        std::string name = "noname";
        std::string city = "Algir";

        cpr::Response r = cpr::Put(cpr::Url(m_url_string + "/put"), 
                                   cpr::Payload({{"name", name.c_str()},{"city", city.c_str()}}));
        
        std::cout<< r.text << std::endl;
    }  
    
    void display_request_delete()
    {
        cpr::Response r = cpr::Delete(cpr::Url(m_url_string + "/delete"));

        std::cout<< r.text << std::endl;
    } 


   void display_request_patch()
    {
        std::string name = "user";
        
        cpr::Response r = cpr::Patch(cpr::Url(m_url_string + "/patch"), 
                                   cpr::Payload({{"name", name.c_str()}}));
        
        std::cout<< r.text << std::endl;
    }   
    
};




int main(int, char**) {
    
    std::string command;

    HTTPCommandTest test;

    while(true)
    {

        std::cout<<"Input command (exit, get, post, put, delete, path): ";
        
        std::getline(std::cin, command);

        if (command == "exit")
          return 0;
        
        if (command == "get")
        {
            test.display_request_get();
        }
        if (command == "post")
        {
            test.display_request_post();
        }
        if (command == "put")
        {
            test.display_request_put();
        }
        if (command == "path")
        {
            test.display_request_patch();
        }
        if (command == "delete")
        {
            test.display_request_delete();
        }          
    }
}
