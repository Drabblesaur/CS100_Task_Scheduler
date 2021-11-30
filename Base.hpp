#ifndef __BASE_HPP__
#define __BASE_HPP__
#include <chrono>
#include <string>
#include <vector>
#include "Date.hpp"

class Base{
    private:
        std::string name;
        std::string description;
        std::string datestr;
        Date date;

    
    public:
        Base();
        Base(std::string name, std::string description,std::string date);
        ~Base();
        void setName(std::string n);
        void setDescription(std::string d);

        std::string getName();
        std::string getDescription();

        std::string get_date();
        void set_date(std::string d);    //Takes a string of form MM/DD/YYYY -> Date obj and store in class.
        Date convert_date();
        Date get_date_obj();
       
};

#endif