#include "BaseFactory.cpp"
#include "task.hpp"

class TaskFactory : public BaseFactory
{
    public:
        TaskFactory();
        ~TaskFactory();
        Base* create(std::string name, std::string description, std::string date, int priority){
            Base * newTask = new task();
            newTask.setName(name);
            newTask.setDescription(description);

            return newTask;
        }

        Base* modifyName(Base* base, std::string name){
            Base * base.setName(name);
            return base;   
        }
        Base* modifyDescription(Base* base, std::string description){
            Base * base.setDescription(description);
            return base;
        }
        Base* modifyPriority(Base* base, int priority){
            Base * base.setPriority(priortiy);
            return base; 
        }
        Base* modifyDate(Base* base, std::string date){
            Base * base.setDate(date);
            return base;
        }
};