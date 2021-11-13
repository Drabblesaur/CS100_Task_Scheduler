#include "task.hpp" // also includes subtask.hpp, vector
#include <iostream>

task::task() {
    name = "";
    date = "";
    priority = 0;
    isComplete = false;
}

task::task(string nm, string d, int p) {
    name = nm;
    date = d;
    priority = p;
    isComplete = false;
}

string task::get_name() {
    return name;
}

void task::set_name(string n) {
    name = n;
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
        for (size_t i = 0; i < subs.size(); i++) { // check each subtasks, if any one of them is incomplete,
            if (!(subs.at(i).complete())) {        // main task can not be marked as complete, so abort
                std::cout << subs.at(i).get_name() << " must be completed first." << std::endl;
                isComplete = false;                // should be defaulted to false but better safe
                return;
            }
        }
        isComplete = true; // if this point is reached, no subtasks are incomplete, so the task can be completed
    }
}

void task::add_subtask() {              // pushes new subtask to subs vector (default)
    task *subtask = new subtask();      // instantiate new default subtask
    subs.push_back(subtask);
}

void add_subtask(string nm, string d, int p) { // pushes new subtask to subs vector (parameterized)
    task *subtask = new subtask(nm, d, p);
    subs.push_back(subtask);
}   

bool task::has_subtasks() {                    // returns true if a task has subtasks
    if (!subs.empty()) { // if subs vector isn't empty, there are subtasks. return true
        return true;
    }
    return false;
}