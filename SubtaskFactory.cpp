#include "BaseFactory.cpp"

class SubtaskFactory : public BaseFactory
{
    public:
        SubtaskFactory();
        ~SubtaskFactory();
        Base* create(std::string name, std::string description, std::string date, int priority, Base* Task){
            Base * subTask = new subTask();
            newsubTask.setName(name);
            newsubTask.setDescription(description);
            newsubTask.setDate(date);
            newsubTask.setPriority(priority);
            task.append(subTask); 

            return subTask; 

        }
        Base* modifyName(Base* task, Base* subtask, std::string name){
            Base
        }
        Base* modifyDescription(Base* task, Base* base, std::string description){
        }
        Base* modifyPriority(Base* task, Base* base, int priority){
        }
        Base* modifyDate(Base* task, Base* base, std::string date){
        }
};