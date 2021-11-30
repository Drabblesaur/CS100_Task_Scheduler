
#include "project.hpp"
class ProjectFactory
{
    public:
        ProjectFactory();
        ~ProjectFactory();
        Base* create(std::string name, std::string description,std::string date){
            Base * newProject = new project();
            newProject->setName(name);
            newProject->setDescription(description);
            newProject->set_date(date);
            
            return newProject;
        }
        Base* modifyName(Base* base, std::string name){
            base->setName(name);
            return base;
        }
        Base* modifyDescription(Base* base, std::string description){
            base->setDescription(description);
            return base; 
        }
        Base* modifyDate(Base* base, std::string date){
            base->set_date(date);
            return base;
        }
};