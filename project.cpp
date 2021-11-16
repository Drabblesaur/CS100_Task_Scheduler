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

int project::get_priority() {
    return priority;
}

void project::set_priority(int p) {
    priority = p;
}
