#include "BaseFactory.cpp"
class ProjectFactory : public BaseFactory
{
    public:
        ProjectFactory();
        ~ProjectFactory();
        Base* create(): BaseFactory::create(){
            //prompt user for project name

            //prompt user for project description

        }
        Base* modify(){
            //prompt user for project name

            //prompt user for project description


        }
};