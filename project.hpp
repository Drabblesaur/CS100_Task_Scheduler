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
	//int priority;
        bool isComplete;
	string type;
public:
	project();
	~project();
	project(string nm, string d, int p);
        string get_name();
        void set_name(string n);
        string get_date();
        void set_date(string d);
        //int get_priority();
        //void set_priority(int p);
	void proj_type( string t);
	string get_type();
  	 bool complete();
	void mark_as_complete();
	void mark_as_incomplete();
	
};
#endif
