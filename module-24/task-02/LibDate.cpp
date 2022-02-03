#include <iostream>
#include <fstream>
#include "LibDate.h"


// Consructor # 1
Date::Date() {
     m_day = 0;
     m_month = 0;
     m_year = 0;
}

// Consructor # 2
Date::Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {
    if (!Validate())
    {
        Date();
    }
}


// Check valid date
bool Date::Validate() {
    if (m_day < 1 || m_day > 31)
     return false;

    if (m_month < 1 || m_month > 12)
     return false;


    if (m_year < 2000 || m_year > 3000)
     return false;

    return true;    
}

// DD.MM.YYYY/ D.MM.YYYY / DD.M.YYYY
bool Date::Parse0(const string& s) {
    
    int index1 = -1;
    int index2 = -1;
    int point = 0;

    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == '.')
      {
        point++;

        if (point == 1)
        {
          index1 = i;
        }
        if (point == 2)
        {
          index2 = i;
        }  

        if (point > 2)
           return false;                 
      }
    }
    

    string ss;
    int dd;

    try
    {

      // DD
      ss = s.substr(0, index1);
      m_day = stoi(ss);
  
      // MM
      ss = s.substr(index1 + 1, index2 - index1 - 1);
      m_month = stoi(ss);
       

      // YYYY
      ss = s.substr(index2 + 1, s.length() - index2 - 1);
      m_year = stoi(ss);

    }
    catch(invalid_argument& e)
    {      
      return false;
    }        


    return true;
}


/* YYYY/MM/DD */
bool Date::Parse1(const string& s) {
    
    const int size = 10;

    int index1 = -1;
    int index2 = -1;
    int point = 0;

    if (s.length() != size)
      return false;

    if (s[4] !='/' || s[7] != '/')
        return false;
          

    string ss;
    
    try
    {

      // DD
      ss = s.substr(8);
      m_day = stoi(ss);
  
      // MM
      ss = s.substr(5, 2);
      m_month = stoi(ss);       

      // YYYY
      ss = s.substr(0, 4);
      m_year = stoi(ss);

    }
    catch(invalid_argument& e)
    {      
      return false;
    }        


    return true;
}



// Public Parse
bool Date::Parse(const string &strDate, const string &strFormat) {
             
       if (strFormat == "DD.MM.YYYY") {
        
          if (Parse0(strDate)) 
            return true;
       }

       if (strFormat == "YYYY/MM/DD") {
        
          if (Parse1(strDate))          
            return true;
       }

       
       Date();           

       return false;        
}

// To String
const string Date::ToString () const {
      
    string str_day = m_day < 10 ? "0" + to_string(m_day):to_string(m_day);
    string str_month = m_month < 10 ? "0" + to_string(m_month):to_string(m_month);
    string str_year = to_string(m_year);

    return str_day + "-" + str_month + "-" + str_year;
      
}

/* Get Day */
const int Date::Day() const {
    return m_day;
}

/* Get Month */
const int Date::Month() const {
    return m_month;
}

/* Get Year */
const int Date::Year() const {
    return m_year;
}

/* Get Local Time */
const time_t Date::LocalTime() const {
    
    tm tm_date;

    tm_date.tm_year = m_year - 1900;
    tm_date.tm_mon  = m_month - 1;
    tm_date.tm_mday = m_day;

    tm_date.tm_hour = 0;
    tm_date.tm_min = 0;
    tm_date.tm_sec = 0;

    tm_date.tm_isdst = -1;

    return mktime(&tm_date);

}



// Read from file
ifstream& operator >> (ifstream &in, Date &date) {
    
      string s;

      in >> s;
    
      date.Parse(s);    

      return in;
}