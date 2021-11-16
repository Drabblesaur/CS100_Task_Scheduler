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
        Date date;
        std::vector<Base *> tasksList;
    
    public:
        Base();
        ~Base();
        void setName(std::string n);
        void setDescription(std::string d);
        void setDate(Date d);

        std::string getName();
        std::string getDescription();
        Date getDate();

        int addTask(Base t);
        int removeTask(int index);
        int editTask(int index, Base t);
        vector<Base *> getTasksList();
       
        

};

#endif