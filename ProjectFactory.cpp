#include "BaseFactory.cpp"
class ProjectFactory : public BaseFactory
{
    public:
        ProjectFactory();
        ~ProjectFactory();
        Base* create(String name, String description){
        }
        Base* modifyName(Base* base, String name){
        }
        Base* modifyDescription(Base* base, String description){
        }
};