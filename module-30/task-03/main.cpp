#include <iostream>
#include <map>
#include <vector>
#include <cpr/cpr.h>


const std::string url_string = "http://httpbin.org";

std::map<std::string, std::string> dictionary;

int main(int, char**) {
    
    std::string key;
    std::string value; 

    while (key != "q")
    {
            
        std::cout<<"Input name key (get/post - exicute, q - exit):";
        std::cin >> key;

        if (key == "q")
            break;
    

        if (key == "post")
        {       
            std::vector<cpr::Pair> list;
            
            for(const auto& it: dictionary)
            {
                list.push_back(cpr::Pair(it.first, it.second));
            }

            cpr::Response r = cpr::Post(cpr::Url(url_string + "/post"), 
                                        cpr::Payload(list.begin(), list.end()));
            
            std::cout<<r.text<< std::endl;
            
            /* clear dictionary */
            dictionary.clear();

            continue;
        }

        if (key == "get")
        {       
            std::string url_args = "?";

            for(const auto& it: dictionary)
            {
               url_args += it.first + "=" + it.second + "&";               
            }

            url_args.pop_back();
            
            cpr::Response r = cpr::Get(cpr::Url(url_string + "/get" + url_args));

            std::cout<<r.text<< std::endl;
            
            /* clear dictionary */
            dictionary.clear();

            continue;
        }

        auto it_find = dictionary.find(key);

        if (it_find != dictionary.end())
        {
            std::cout<<"This key is already"<<std::endl;

            continue;
        }    

        std::cout<<"Input value key:";
        std::cin>>value;

        dictionary.emplace(key, value);
    }

}
