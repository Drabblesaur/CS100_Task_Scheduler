#include "BaseFactory.cpp"
class ProjectFactory : public BaseFactory
{
    public:
        ProjectFactory();
        ~ProjectFactory();
        Base* create(std::string name, std::string description){
            Base * newProject = new project();
            newProject.setName(name);
            newProject.setDescription(description);
            
            return newProject;
        }
        Base* modifyName(Base* base, std::string name){
            Base * base.setName(name);
            return base;
        }
        Base* modifyDescription(Base* base, std::string description){
            Base * base.setDescription(description);
            return base; 
        }
};