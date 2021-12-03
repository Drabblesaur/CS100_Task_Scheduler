#ifndef __SUBTASK_HPP__
#define __SUBTASK_HPP__

#include <string>
#include "Date.hpp"
#include "Base.hpp"

using std::string;

class subtask : public Base {
    private:
        int priority;
        bool isComplete;

    public:
        subtask() : Base() {
            priority = 0;
            isComplete = false;
        }

        subtask(string d, int p) : Base() {
            this->set_date(d);
            priority = p;
            isComplete = false;
        }
        subtask(string nm, string desc, string d, int p) : Base() { // for making new subtasks from main
            this->setName(nm);
            this->setDescription(desc);
            this->set_date(d);
            priority = p;
            isComplete = false;
        }

        subtask(string nm, string desc, int p, string d, bool c) : Base() { // subtask constructor for file i/o backup purposes
            this->setName(nm);
            this->setDescription(desc);
            this->set_date(d);
            priority = p;
            isComplete = c;
        }

        bool complete();
        int get_priority();
        void set_priority(int p);
        void mark_as_complete();                        // sets current task to complete
        void mark_as_incomplete();                      // sets current task to incomplete
};


#endif