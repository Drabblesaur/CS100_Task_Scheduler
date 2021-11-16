#ifndef __PROJECT_HPP__
#define __PROJECT_HPP__

#include <vector>
#include <string>
#include "Date.hpp"

using std::string;
using std::vector;

class project{
private:
	string name; 
        string date;
	int priority;
        bool isComplete;
public:
        string get_name();
        void set_name(string n);
        string get_date();
        void set_date(string d);
        int get_priority();
        void set_priority(int p);
        bool complete();
	void mark_as_complete();
	void mark_as_incomplete();
	
};
#endif
