#include "Base.hpp"
class BaseFactory{
public:
    BaseFactory();
    ~BaseFactory();
    virtual Base* modifyName(Base* base, String name) = 0;
    virtual Base* modifyDescription(Base* base, String description) = 0;

    
};
