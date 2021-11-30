#include "Base.hpp"
class BaseFactory{
public:
    BaseFactory();
    ~BaseFactory();
    virtual Base* modifyName(Base* base, std::string name) = 0;
    virtual Base* modifyDescription(Base* base, std::string description) = 0;

    
};
