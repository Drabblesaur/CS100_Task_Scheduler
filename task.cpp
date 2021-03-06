#include "task.hpp" // also includes vector
#include <iostream>
#include <ctime>
#include <string>
#include "subtask.hpp"

task::~task() {
    for (size_t i = 0; i < subs.size(); i++) {
        delete subs.at(i);
    }
}


int task::get_priority() {
    return priority;
}

void task::set_priority(int p) {
    priority = p;
}

bool task::complete() {    // returns current state of completion
    //if (!has_subtasks()) { // if task has no subs, return state of current task
    //    return isComplete;
    //}
    //for (unsigned i = 0; i < subs.size(); i++) {
    //    if (!(subs.at(i).complete())) { // if any one subtask is incomplete, return false
    //        return false;
    //    }
    //}
    //return true;                        // if task has subtasks and none are incomplete, return true
    return isComplete;
}

void task::mark_as_complete() {         // sets current task to complete
    if (!has_subtasks()) {
        isComplete = true;              // if task has no subs, is okay to mark as complete
    }
    else {
        bool hasIncompleteSubs = false;
        for (size_t i = 0; i < subs.size(); i++) { // check each subtasks, if any one of them is incomplete,
            if (!(subs.at(i)->complete())) {        // main task can not be marked as complete, so abort
                std::cout << "subtask \"" << subs.at(i)->getName() << "\" must be completed before \"" << this->getName() << "\" can be completed." << std::endl;
                isComplete = false;                // should be defaulted to false but better safe
                hasIncompleteSubs = true;
            }
        }
        if (hasIncompleteSubs) {
            return;
        }
        std::cout << "Task Completed"<< std::endl;
        isComplete = true; // if this point is reached, no subtasks are incomplete, so the task can be completed
    }
}

void task::mark_as_incomplete() {
    isComplete = false;
}

vector<subtask*> task::get_subtasks() {
    return subs;
}
void task::add_subtask(subtask* sub) {              // pushes new subtask to subs vector (default)
                                        // instantiate new default subtask
    subs.push_back(sub);
}

void task::add_subtask(string nm, string d, int p) { // pushes new subtask to subs vector (parameterized)
    subtask *newSub = new subtask(d, p);
    newSub->setName(nm);
    subs.push_back(newSub);
}

void task::complete_subtask(string nm) {
    subtask *sub = search(nm);

    sub->mark_as_complete();
}

bool task::has_subtasks() {                    // returns true if a task has subtasks
    return !subs.empty();                      // if subs.empty() is true, has_subtasks() == false
}                                              // basically, has_subtasks() is the negation of subs.empty()
subtask* task::remove_subtask(string nm){
    subtask *sub = search(nm);
    if (sub == nullptr) {
        return nullptr;
    }
    for (size_t i = 0; i < subs.size(); i++) {
        if (subs.at(i) == sub) {
            subs.erase(subs.begin() + i);
            return sub;
        }
    }
    return nullptr;

}
void task::print_subtasks() {
    if (subs.empty()) {
        std::cout << "Task \"" << this->getName() << "\" has no subtasks." << std::endl;
    }
    else {
        for (size_t i = 0; i < subs.size(); i++) {
            std::cout <<"S"<< (i+1) << " Name: " << subs.at(i)->getName() << std::endl;
            std::cout << "    Description: " << subs.at(i)->getDescription() << std::endl;
            std::cout << "    Due Date: " << subs.at(i)->get_date() << std::endl;
            std::cout << "    Priority: " << subs.at(i)->get_priority() << std::endl;
            std::cout << "    Completion: " << std::boolalpha << subs.at(i)->complete() << std::endl;
        }
    }
}

subtask * task::search(string nm) {
    subtask *sub = nullptr;
    bool found = false;
    for (size_t i = 0; i < subs.size(); i++) {
        if (subs.at(i)->getName() == nm) {         // if a subtask in subs has the same name as what is passed in, point subToComplete to it
            sub = subs.at(i);
            found = true;
        }
    }

    if (!found) {
        std::cout <<'\"' << this->getName() << "\" has no subtask titled \"" << nm << '\"' << std::endl;
        return nullptr;
    }

    return sub;
}
