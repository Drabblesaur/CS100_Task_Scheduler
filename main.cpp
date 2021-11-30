#include "Base.hpp"
#include "Date.hpp"
#include "task.hpp"
#include "subtask.hpp"
#include "project.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <Base *>proj;
vector <Base *>subt;
vector <base *>tasks; 
char option; 

cout << "Welcome to the Task Scheduler!"<<endl;

while (option != 'q' || option != 'Q'){
cout << "Select an option from the Menu:"<<endl;
cout << "A - Add A Task"<<endl;
cout << "B - Add A Subtask"<<endl; 
cout << "C - Mark Task As Completed"<<endl;
cout << "D - Create A Project"<<endl; 
cout << "E - Mark Project As Completed"<<endl;
cout << "F - View Tasks"<<endl;
cout << "G - View Projects"<<endl; 

cin >> option;
cout << endl;

if (option =='A' || option == 'a'){


}
