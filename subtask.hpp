#ifndef __SUBTASK_HPP__
#define __SUBTASK_HPP__

#include <string>
#include "Date.hpp"
#include "Base.hpp"

using std::string;

class subtask : public Base {
    private:
        string datestr;
        Date date;
        int priority;
        bool isComplete;

    public:
        subtask() : Base() {
            datestr = "";
            date = convert_date();
            priority = 0;
            isComplete = false;
        }

        subtask(string d, int p) : Base() {
            datestr = d;
            date = convert_date();
            priority = p;
            isComplete = false;
        }

        bool complete();
        string get_date();
        Date convert_date();
        void set_date(string d);
        int get_priority();
        void set_priority(int p);
        void mark_as_complete();                        // sets current task to complete
        void mark_as_incomplete();                      // sets current task to incomplete
};


#endif