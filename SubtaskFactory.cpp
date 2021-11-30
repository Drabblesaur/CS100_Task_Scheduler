#include "BaseFactory.cpp"
class TaskFactory : public BaseFactory
{
    public:
        TaskFactory();
        ~TaskFactory();
        Base* create(){
            //prompt user for subtask name

            //prompt user for subtask description

            //prompt user for subtask priority

            //prompt user for subtask due date

            //promt user for Task Location ?Maybe?
            

        }
        Base* modify(){
            //prompt user for task name

            //prompt user for task description

            //prompt user for task priority

            //prompt user for task due date

        }
};