#include <iostream>
#include <cpr/cpr.h>



int main(int, char**) {
    
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"), 
                               cpr::Header{{"Accept", "text/html"}});

    const std::string html_text = r.text;

    int index_start = html_text.find("<h1>");
    int index_stop =  html_text.find("</h1>");

    if(index_start == std::string::npos || index_stop == std::string::npos)
        return 0;

    const std::string html_head = html_text.substr(index_start + 4, index_stop- index_start -4); 

    std::cout<< html_head << std::endl;       

}
