#ifndef __TASK_HPP__
#define __TASK_HPP__

#include <vector>
#include <string>

using std::string;
using std::vector;
class task {
    private:
        string name; 
        string date; // how to implement date? string, custom date object etc
        int priority;
        bool isComplete;
        vector<task *> subs;
        bool has_subtasks();                            // returns true if a task has subtasks
                                                        // private helper for mark_as_complete()
    public:
        task();
        ~task();
        task(string nm, string d, int p); // potentially update depending on date format
        string get_name();
        void set_name(string n);
        string get_date();
        void set_date(string d);
        int get_priority();
        void set_priority(int p);
        bool complete();                                // returns current state of completion
        void mark_as_complete();                        // sets current task to complete
        void mark_as_incomplete();                      // sets current task to inomplete
        void add_subtask();                             // pushes new subtask to subs vector (default)
        void add_subtask(string nm, string d, int p);   // pushes new subtask to subs vector (parameterized)
        void complete_subtask(string nm);
};

#endif