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
    bool isComplete;
	vector<Base *> items; 

public:
	project() : Base() {
            isComplete = false;
        }
	project(string d, int p) : Base(){
		this->set_date(d);
	    isComplete = false;
	}
	project(string d,int p,vector<Base *>v) : Base(){
	    this->set_date(d);
	    isComplete = false;
	    items =v ;
	}
	
	~project();        

	void add_task();
	bool has_elements();
    void add_task(string s1, string s2, int i);
	void add_Project(project* p);
	
	void print_project();
	Base * project::search(string nm);
	
};
#endif
