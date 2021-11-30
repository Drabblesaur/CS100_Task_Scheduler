#include "subtask.hpp"

bool subtask::complete() {
    return isComplete;
}

string subtask::get_date() { 
    if (datestr == "") {
        return " ";
    }
    else {
        return datestr;
    }
}

void subtask::set_date(string d) { //Takes a string of form MM/DD/YYYY -> Date obj and store in class.
    datestr = d;
}

Date subtask::convert_date(){
    std::string::size_type sz;   // alias of size_t

    int m = std::stoi(datestr.substr(0,2), &sz);
    int d = std::stoi(datestr.substr(3,2), &sz);
    int y = std::stoi(datestr.substr(6,4), &sz);

    Date dt(m,d,y);

    return dt;
}

int subtask::get_priority() {
    return priority;
}

void subtask::set_priority(int p) {
    priority = p;
}

void subtask::mark_as_complete() {          // since subtasks are the lowest order task, they can just be
    isComplete = true;                      // marked as complete whenever told
}

void subtask::mark_as_incomplete() {
    isComplete = false;
}