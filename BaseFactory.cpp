#include "Base.hpp"
class BaseFactory{
public:
    BaseFactory();
    ~BaseFactory();
    virtual Base* create() = 0;
};
