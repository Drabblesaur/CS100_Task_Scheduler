#include "project.hpp"
#include <iostream>
#include <ctime>
#include <string> 

project::~project(){
for (size_t i = 0; i < items.size(); i++) {
        delete items.at(i);
    }
}

void project::add_item(Base* b){
    items.push_back(b);
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

vector<Base*> project::get_items() {
    return items;
}