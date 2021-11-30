#include "BaseFactory.cpp"
class TaskFactory : public BaseFactory
{
    public:
        TaskFactory();
        ~TaskFactory();
        Base* create(){
            //prompt user for task name

            //prompt user for task description

            //prompt user for task priority

            //prompt user for task due date

        }
        Base* modify(){
            //prompt user for task name

            //prompt user for task description

            //prompt user for task priority

            //prompt user for task due date

        }
};