#include "phone.h"

/**************************************** Decription Record ***********************************/
/* Get number */
const std::string& Record::getNumber() const{
    return m_number;
}



/**************************************** Decription Phone ***********************************/

 /* Check number */
bool Phone::check(const std::string& number){
    
    if (number.length() == 0 || number[0] != '+' )//|| number.length() != 12)
      return false;


    for (int i = 1; i < number.length(); i++) {

        if (number[i] < '0' && number[i] > '9') {
            std::cout << "Format number is bad"<<std::endl;
            return false;
        }
    }

    return true;
}


/*Add new contact */
bool Phone::add(const std::string& name, const std::string& number){
      
    /* Check number */
    if (!check(number))
       return false;


    /* Find number */
    auto it_number = m_numbers.find(number);

    if (it_number != m_numbers.end()) {
            std::cout << "Number is exist"<<std::endl;
            return false;
    }



    /* Find contact */
    auto it_contact = m_contacts.find(name);

    if (it_contact != m_contacts.end()) {

        it_contact->second.push_back(Record{number});

        std::cout << "Number is added"<<std::endl;
        
        return true; 
    }
    

    /* New */
    std::vector<Record> vec;

    vec.push_back(Record{number});

    m_contacts.emplace(name, vec);

    m_numbers.emplace(number, name);

    std::cout << "Contact is created"<<std::endl;

    return true;
}


/*Call */
bool Phone::call(const std::string& name_number){
    
    const auto& it_name = m_contacts.find(name_number);

    if (it_name != m_contacts.end()) {
        
        std::cout<<"Call to "<< it_name->first<<" ["<<it_name->second[0].getNumber()<<"]"<<std::endl;
        
        return true;
    } 
    

    const auto& it_number = m_numbers.find(name_number);

    if (it_number!= m_numbers.end()) {

        std::cout<<"Call to "<< it_number->second<<" ["<<it_number->first<<"]"<<std::endl;

        return true;       
    }


    /* Check number */
    if (check(name_number)) {
        std::cout<<"Call to NoName ["<< name_number<<"]"<<std::endl;
        return true;
    }

        

    
    return false;
}



/*SMS */
bool Phone::sms(const std::string& name_number, const std::string& message){
    
    const auto& it_name = m_contacts.find(name_number);

    if (it_name != m_contacts.end()) {
        
        std::cout<<"SMS sending to "<< it_name->first<<" ["<<it_name->second[0].getNumber()<<"]"<<std::endl;
        
        return true;
    } 
    

    const auto& it_number = m_numbers.find(name_number);

    if (it_number!= m_numbers.end()) {

        std::cout<<"SMS sending to "<< it_number->second<<" ["<<it_number->first<<"]"<<std::endl;

        return true;       
    }


    /* Check number */
    if (check(name_number)) {
        std::cout<<"SMS sending to NoName ["<< name_number<<"]"<<std::endl;
        return true;
    }
    
        

    
    return false;
}


