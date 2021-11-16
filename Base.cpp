#include "Base.hpp"
Base::Base(){
    name = "";
    description = "";
    tasksList = new std::vector<Base*>();


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

int Base::addTask(Base* t){
    tasksList.push_back(t);
}

int Base::removeTask(Base* t){
    for(int i = 0; i < tasksList.size(); i++){
        if(tasksList[i] == t){
            tasksList.erase(tasksList.begin() + i);
            return 0;
        }
    }
    return -1;
}
int Base::editTaskName(Base* t, std::string name){
    Base task = getTask(t);
    task.setName(name);
}
int Base::editTaskDescription(Base* t, std::string description){
    Base task = getTask(t);
    task.setDescription(description);
}

Base Base::getTask(Base* t){
    for(int i = 0; i < tasksList.size(); i++){
        if(tasksList[i] == t){
            return *tasksList[i];
        }
    }
    return Base();
}
vector<Base *> Base::getTaskList(){
    return tasksList;
}