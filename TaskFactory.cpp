#include "BaseFactory.cpp"
class TaskFactory : public BaseFactory
{
    public:
        TaskFactory();
        ~TaskFactory();
        Base* create(String name, String description,String date, int priority){
        }
        Base* modifyName(Base* base, String name){
        }
        Base* modifyDescription(Base* base, String description){
        }
        Base* modifyPriority(Base* base, int priority){
        }
        Base* modifyDate(Base* base, String date){
        }
};