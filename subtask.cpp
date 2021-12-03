#include "subtask.hpp"

bool subtask::complete() {
    return isComplete;
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
