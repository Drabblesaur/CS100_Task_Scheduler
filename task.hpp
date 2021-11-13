#ifndef __TASK_HPP__
#define __TASK_HPP__

#include "subtask.hpp"
#include <vector>

using std::string;
using std::vector;
class task {
    private:
        string name; 
        string date; // how to implement date? string, custom date object etc
        int priority;
        bool isComplete;
        vector<subtask *> subs;
    public:
        task();
        task(string nm, string d, int p); // potentially update depending on date format
        ~task();
        string get_name();
        void set_name(string n);
        int get_priority();
        void set_priority(int p);
        bool complete();                                // returns current state of completion
        void mark_as_complete();                        // sets current task to complete
        void add_subtask();                             // pushes new subtask to subs vector (default)
        void add_subtask(string nm, string d, int p);   // pushes new subtask to subs vector (parameterized)
        bool has_subtasks();                            // returns true if a task has subtasks
};

#endif