#include "project.hpp"
#include <iostream>
#include <ctime>
#include <string> 

project::~project(){
for (size_t i = 0; i < items.size(); i++) {
        delete items.at(i);
    }
}

string project::get_date() {
    if (datestr == "") {
        return " ";
    }
    else
        return datestr;
}

void project::set_date(string d) {
    datestr = d;
}

Date task::convert_date(){
if (datestr.size() == 0) {
        return Date(0,0,0); //if empty
}
else{ 
std::string::size_type sz;   // alias of size_t
int m = std::stoi(datestr.substr(0,2), &sz);
        int d = std::stoi(datestr.substr(3,2), &sz);
        int y = std::stoi(datestr.substr(6,4), &sz);

        return Date(m,d,y);
    }
}

void project::add_task(){
	task *newTask = new task();
	items.push_back(newTask);
}

void project::add_task(string nm, string d, int p) {
  task *newTask = new task(d, p);
  newTask->setName(nm);
  items.push_back(newTask);
}

void project::add_Project(project proj) {
  project *newProj = proj
  items.push_back(newProj);
}	

void project::print_project(){
if (items.empty()){
std::cout << "Project \""<<this -> getName()<<"\" has no projects."<<std::endl;
}
else{
	for(size_t i=0; i<items.size(); i++){
std::cout<< i+1<<". "<<items.at(i)->getName()<<": "<< items.at(i)->getDescription<<std::endl;
}
}
}

Base * project::search(string nm) {
    project *proj = nullptr;
    bool found;
    for (size_t i = 0; i < subs.size(); i++) {
        if (items.at(i)->getName() == nm) {
	proj = items.at(i);
	found = true;
}
}
if (!found){
std::cout <<'\"' << this->getName() << "\" has no project titled \"" << nm << '\"' << std::endl;
        return nullptr;
    }
    
    return proj;
}
