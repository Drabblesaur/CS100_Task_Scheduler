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
        std::vector<Base *> tasksList;
    
    public:
        Base();
        ~Base();
        void setName(std::string n);
        void setDescription(std::string d);

        std::string getName();
        std::string getDescription();

        int addTask(Base* t);
        int removeTask(Base* t);
        int editTaskName(Base* nt,std::string name);
        int editTaskDescription(Base* nt, std::string description);
        Base getTask(Base* t);
        vector<Base *> getTasksList();
       
        

};

#endif