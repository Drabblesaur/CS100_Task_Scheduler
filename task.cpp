#include "task.hpp" // also includes vector
#include <iostream>
#include <ctime>
#include <string>
#include 

task::task() {
    name = "";
    string date = "";
    priority = 0;
    isComplete = false;
}

task::task(string nm, Date d, int p) {
    name = nm;
    date = d;
    priority = p;
    isComplete = false;
}

task::~task() {
    for (size_t i = 0; i < subs.size(); i++) {
        delete subs.at(i);
    }
}

string task::get_name() {
    return name;
}

void task::set_name(string n) {
    name = n;
}

string task::get_date() { 
    if (datestr == "") {
        return " ";
    }
    else
        return datestr;
}

void task::set_date(string d) { //Takes a string of form MM/DD/YYYY -> Date obj and store in class.
    datestr = d;
}

Date task::convert_date(){
    int d = std::stoi(datestr.substr(0,2));
    int m = std::stoi(datestr.substr(3,3));
    int y = std::stoi(datestr.substr(7,4));
    return Date(d,m,y);
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
                std::cout << "subtask \"" << subs.at(i)->get_name() << "\" must be completed before \"" << this->get_name() << "\" can be completed." << std::endl;
                isComplete = false;                // should be defaulted to false but better safe
                hasIncompleteSubs = true;
            }
        }
        if (hasIncompleteSubs) {
            return;
        }
        isComplete = true; // if this point is reached, no subtasks are incomplete, so the task can be completed
    }
}

void task::mark_as_incomplete() {
    isComplete = false;
}

void task::add_subtask() {              // pushes new subtask to subs vector (default)
    task *subtask = new task();      // instantiate new default subtask
    subs.push_back(subtask);
}

void task::add_subtask(string nm, string d, int p) { // pushes new subtask to subs vector (parameterized)
    task *subtask = new task(nm, d, p);
    subs.push_back(subtask);
}

void task::complete_subtask(string nm) {
    task *subToComplete = nullptr;
    bool found = false;
    for (size_t i = 0; i < subs.size(); i++) {
        if (subs.at(i)->get_name() == nm) {         // if a subtask in subs has the same name as what is passed in, point subToComplete to it
            subToComplete = subs.at(i);
            found = true;
        }
    }
    if (!found) {
        std::cout <<'\"' << this->get_name() << "\" has no subtask titled \"" << nm << '\"' << std::endl;
        return;
    }

    subToComplete->mark_as_complete();
}

bool task::has_subtasks() {                    // returns true if a task has subtasks
    if (!subs.empty()) { // if subs vector isn't empty, there are subtasks. return true
        return true;
    }
    return false;
}