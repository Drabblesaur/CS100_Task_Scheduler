#ifndef __TASK_HPP__
#define __TASK_HPP__

#include <vector>
#include <string>
#include "Date.hpp"
#include "Base.hpp"
#include "subtask.hpp"

using std::string;
using std::vector;
class task : public Base {
    private:
        string datestr;
        Date date;
        int priority;
        bool isComplete;
        vector<subtask *> subs;                           // returns true if a task has subtasks
                                                        // private helper for mark_as_complete()
    public:
        task() : Base() {
            datestr = "";
            date = convert_date();
            priority = 0;
            isComplete = false;
        }


        task(string d, int p) : Base() {
            datestr = d;
            date = convert_date();
            priority = p;
            isComplete = false;
        }

        task(string nm, string desc, string d, int p) : Base() { // for making new tasks from main
            this->setName(nm);
            this->setDescription(desc);
            datestr = d;
            date = convert_date();
            priority = p;
            isComplete = false;
        }

        task(string nm, string desc, string d, int p, bool c) : Base() { // task constructor for file i/o backup purposes
            this->setName(nm);
            this->setDescription(desc);
            datestr = d;
            date = convert_date();
            priority = p;
            isComplete = c;
        }

        ~task();
        bool has_subtasks(); 
        bool complete();                                // returns current state of completion
        Date convert_date();
        string get_date();
        vector<subtask*> get_subtasks();
        void set_date(string d);
        int get_priority();
        void set_priority(int p);
        void mark_as_complete();                        // sets current task to complete
        void mark_as_incomplete();                      // sets current task to inomplete
        void add_subtask(subtask* sub);                             // pushes new subtask to subs vector (default)
        void add_subtask(string nm, string d, int p);   // pushes new subtask to subs vector (parameterized)
        void complete_subtask(string nm);               // mark a given subtask as complete
        void print_subtasks();                          // take a guess
        subtask * search(string nm);
};

#endif