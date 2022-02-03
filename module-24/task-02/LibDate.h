#ifndef LIB_H
#define LIB_H

#include<iostream>
using namespace std;


class Date
{
    int m_day = 0;
    int m_month = 0;
    int m_year = 0;

  private:

  // Check valid
  bool Validate();
 

  // DD.MM.YYYY/ D.MM.YYYY / DD.M.YYYY
  bool Parse0(const string& s);


  /* YYYY/MM/DD */
  bool Parse1(const string& s);
    
  
  
  public:
    
    // Costructor #1
    Date();

    // Costructor #2    
    Date(int day, int month, int year);
    
    /* Parse String Date */ 
    bool Parse(const string &strDate, const string &strFormat = "DD.MM.YYYY");        

    /* Get String Date */
    const string ToString () const;

    /* Get Day */
    const int Day() const;

    /* Get Month */
    const int Month() const;

    /* Get Year */
    const int Year() const;

    /* Get Local Time */
    const time_t LocalTime() const;
       

    // Read from file
    friend ifstream& operator >> (ifstream &in, Date &date);  


};






#endif