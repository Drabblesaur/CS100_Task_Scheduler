
#include "subtask.hpp"
#include "subtask.cpp"

class SubtaskFactory
{
    public:
        SubtaskFactory();
        ~SubtaskFactory();
        subtask* createSubtask(std::string name, std::string description, std::string date,int priority, bool isComplete){
            return new subtask(name, description, priority, date, isComplete);
        }
        void modifyName( subtask* subtask, std::string name){
            subtask->setName(name);
        }
        void modifyDescription( subtask* subtask, std::string description){
            subtask->setDescription(description);
        }
        void modifyPriority( subtask* subtask, int priority){
            subtask->set_priority(priority);
        }
        void modifyDate( subtask* subtask, std::string date){
            subtask->set_date(date);
        }
};