#include "BaseFactory.cpp"
#include "subtask.hpp"
#include "subtask.cpp"

class SubtaskFactory : public BaseFactory
{
    public:
        SubtaskFactory();
        ~SubtaskFactory();
        subtask* createSubtask(std::string name, std::string description, std::string date,int priority, bool isComplete){
            return new subtask(name, description, priority, date, isComplete);
        }
        Base* modifyName(Base* task, Base* subtask, std::string name){
        }
        Base* modifyDescription(Base* task, Base* base, std::string description){
        }
        Base* modifyPriority(Base* task, Base* base, int priority){
        }
        Base* modifyDate(Base* task, Base* base, std::string date){
        }
};