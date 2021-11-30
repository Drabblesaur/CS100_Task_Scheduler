
#include "task.hpp"

class TaskFactory{
    public:
        TaskFactory();
        ~TaskFactory();
        task* create(std::string name, std::string description, std::string date, int priority){
            task* newTask = new task();
            newTask->set_date(date);
            newTask->setName(name);
            newTask->setDescription(description);
            return newTask;
        }

        Base* modifyName(task* base, std::string name){
            base->setName(name);
            return base;   
        }
        Base* modifyDescription(task* base, std::string description){
            base->setDescription(description);
            return base;
        }
        Base* modifyPriority(task* base, int priority){
            base->set_priority(priority);
            return base; 
        }
        Base* modifyDate(Base* base, std::string date){
            base->set_date(date);
            return base;
        }
};