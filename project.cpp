#include "project.hpp"
#include <iostream>

project::project(){
    name = "";
    date = "";
    priority = 0;
    isComplete = false;
}

project::project(string nm, string d, int p) {
    name = nm;
    date = d;
    priority = p;
    isComplete = false;
}

project::~project() {
    for (size_t i = 0; i < subs.size(); i++) {
        delete subs.at(i);
    }
}

string project::get_name() {
    return name;
}

void project::set_name(string n) {
    name = n;
}

string project::get_date() {
    return date;
}

void project::set_date(string d) {
    date = d;
}

bool task::complete() {    // returns current state of completion
    if (!has_subtasks()) { // if task has no subs, return state of current task
        return isComplete;
    }
    for (unsigned i = 0; i < subs.size(); i++) {
    	if (!(subs.at(i).complete())) { // if any one subtask is incomplete, return false
    	return false;
    }
}
    return true;                        // if task has subtasks and none are incomplete, return true
	return isComplete;
}

void task::mark_as_incomplete() {
    isComplete = false;
}

/*int project::get_priority() {
    return priority;
}

void project::set_priority(int p) {
    priority = p;
}*/
