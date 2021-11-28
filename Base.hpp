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
    
    public:
        Base();
        ~Base();
        void setName(std::string n);
        void setDescription(std::string d);

        std::string getName();
        std::string getDescription();
       
};

#endif