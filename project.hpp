#ifndef __PROJECT_HPP__
#define __PROJECT_HPP__

#include <vector>
#include <string>
#include "Date.hpp"
#include "Base.hpp"
#include "task.hpp"

using std::string;
using std::vector;

class project:public Base{
private:
        string date;
	Date datestr; 
        bool isComplete;
	vector<Base *> items; 
public:
	project() : Base() {
            datestr = "";
            date = convert_date();
	    priority = p;
            isComplete = false;
        }
	project(string d, int p) : Base(){
	    datestr = d;
	    date = convert_date();
	    priority = p;
	    isComplete = false;
	}
	project(string d,int p,vector<Base *>v){
	    datestr = d;
	    date = convert_date();
	    priority = p;
	    isComplete = false;
	    items =v ;
	}
	
	~project();        

	Date convert_date(); 
	string get_date();
        void set_date(string d);
	
	void add_task();
        void add_task(string, string, int);
	void add_Project(project);
	
	void print_project();
	project * search(string nm);
	
};
#endif
