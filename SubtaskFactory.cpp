#include "BaseFactory.cpp"
class SubtaskFactory : public BaseFactory
{
    public:
        SubtaskFactory();
        ~SubtaskFactory();
        Base* create(String name, String description, String date, int priority,Base* Task){
        }
        Base* modifyName(Base* task,Base* subtask, String name){
        }
        Base* modifyDescription(Base* task, Base* base, String description){
        }
        Base* modifyPriority(Base* task, Base* base, int priority){
        }
        Base* modifyDate(Base* task, Base* base, String date){
        }
};