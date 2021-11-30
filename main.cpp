#include "Base.hpp"
#include "Date.hpp"
#include "task.hpp"
#include "subtask.hpp"
#include "project.hpp"
#include "TaskFactory.cpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <project *>proj;
vector <subtask *>subt;
vector <task *>tasks; 
char option; 


void printMenu(){
    cout << " Select an option from the Menu:"<<endl;
    cout << " A - Add A Task"<<endl;
    cout << " B - Add A Subtask"<<endl; 
    cout << " C - Mark Task As Completed"<<endl;
    cout << " D - Create A Project"<<endl; 
    cout << " E - Mark Project As Completed"<<endl;
    cout << " F - View Tasks"<<endl;
    cout << " G - View Projects"<<endl;
}

// for making new tasks
Base* usertask(){
    TaskFactory * tfactory = new TaskFactory();
    string name;
    string date; 
    string description;
    int priority;

    cout<<" Enter name of task:"<<endl;
    getline(cin, name);

    cout << " Enter task descrition:" <<endl;
    getline(cin,description);

    cout<<" Enter task due date:"<<endl;
    getline(cin,date);

    cout<<" Enter the level of task priority from a level of 1-5 (1 being low priority, 5 being the most urgent)"<<endl;
    cin >> priority; 

    task* newtask = 
    return Task;  
}

// Making new sub tasks  
Base* userSubTask(){

}

//for making new projects
Base* userProj(){
    string name; 
    string description;
} 

int main(){
    
    cout<< " Welcome to the Task Scheduler! "<<endl;
    
    do{ 
        printMenu();
        cin >> option;
        cout << endl;

        if (option =='A' || option == 'a'){
            Base* Task = usertask();
            tasks.push_back(Task);
        }

        else if (option == 'B' || option =='b'){

        }
        else if(option =='C' || option == 'c'){

        }

        else if(option == 'D' || option == 'd'){
            Base* Proj = userProj();
            proj.push_back(Proj);
        }
        else if(option == 'E' || option == 'e'){

        }

        else if(option == 'F' || option == 'f'){

        }

        else if(option == 'G' || option == 'g'){

        }

        
}while(option != 'q' || option != 'Q');
