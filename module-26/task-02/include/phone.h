#ifndef PHONE_H
#define PHONE_H


#include <iostream>
#include <map>
#include <vector>

class Record {
    
    private:
 
    std::string m_number;
   
    public:

    Record(std::string number): m_number{number}{}

    /* Get number */
    const std::string& getNumber() const;

};



class Phone{

    private:
    std::map<std::string, std::vector<Record>> m_contacts;
    std::map<std::string, std::string> m_numbers;

    bool check(const std::string& number);
    
    public:

    Phone(){}

    /*Add new number */
    bool setContact(const std::string& name, const std::string& number);


    /*Call */
    bool call(const std::string& call);
    

    /* send Sms */
    bool sms(const std::string& contact, const std::string& message);


    

};


#endif