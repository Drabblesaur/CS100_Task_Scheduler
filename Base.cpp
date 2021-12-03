#include "Base.hpp"
Base::Base(){
    name = "";
    description = "";
    datestr = "";
    date = convert_date();
}
Base::Base(std::string name, std::string description,std::string date){
    this->name = name;
    this->description = description;
    this->datestr = date;
    this->date = convert_date();
}
Base::~Base(){};

void Base::setName(std::string name){
    this->name = name;
};
void Base::setDescription(std::string description){
    this->description = description;
};

std::string Base::getName(){
    return name;
};
std::string Base::getDescription(){
    return description;
};

std::string Base::get_date() { 
            if (datestr == "") {
                return " ";
            }       
            else
                return datestr;
        }
void Base::set_date(std::string d){
    this->datestr = d;
}
Date Base::convert_date(){
    if (datestr.size() == 0) {
        return Date(0,0,0);          // if datestr is empty, return 0/0/0
    }
    else {
        std::string::size_type sz;   // alias of size_t

        int m = std::stoi(datestr.substr(0,2), &sz);
        int d = std::stoi(datestr.substr(3,2), &sz);
        int y = std::stoi(datestr.substr(6,4), &sz);

        return Date(m,d,y);
    }
}

Date Base::get_date_obj() {
    return date;
}
