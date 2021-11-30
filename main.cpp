#include "Base.hpp"
#include "Date.hpp"
#include "task.hpp"
#include "subtask.hpp"
#include "project.hpp"
#include "TaskFactory.cpp"
#include "SubtaskFactory.cpp"
#include "ProjectFactory.cpp"
#include "FileIO.cpp"

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

FileIO Fio;
vector <project *>proj;
vector <subtask *>subt;
vector <task *>tasks; 
char option;
char s[80];

bool compare(task* t1,task*t2){
    if(t1->get_date_obj().getYear() < t2->get_date_obj().getYear())
    return true;
    if((t1->get_date_obj().getYear() == t2->get_date_obj().getYear()) && (t1->get_date_obj().getMonth() < t2->get_date_obj().getMonth()))
    return true;
    if((t1->get_date_obj().getYear() == t2->get_date_obj().getYear()) && (t1->get_date_obj().getMonth() < t2->get_date_obj().getMonth())&&(t1->get_date_obj().getDay() && t1->get_date_obj().getDay()))
    return true;

    return false;
}
void setToday(){
    const int MAXLEN = 80;
    time_t t = time(0);
    strftime(s, MAXLEN, "%m/%d/%Y", localtime(&t));

}

void printMenu(){
    cout << " Select an option from the Menu:" << endl;
    cout << " A - Add A Task" << endl;
    cout << " B - Add A Subtask" << endl; 
    cout << " C - Mark Task As Completed" << endl;
    cout << " D - Create A Project" << endl; 
    cout << " E - Mark Project As Completed" << endl;
    cout << " F - View Tasks" << endl; //ask user for all tasks today,via priority, or via date
    cout << " G - View Projects" << endl;
    cout << " Please enter Q or q to quit... " << endl; 
}

// for making new tasks
task* usertask(){
    TaskFactory * tfactory = new TaskFactory();
    string name;
    string date; 
    string description;
    int priority;
 
    cout << " Enter name of task: " << endl;
    getline(cin, name);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << " Enter task descrition: " << endl;
    getline(cin, description);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << " Enter task due date (Please enter in Month/Day/Year format): " << endl;
    getline(cin, date);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << " Enter the level of task priority from a level of 1-5 (1 being low priority, 5 being the most urgent): " << endl;
    cin >> priority; 

    task* newtask = tfactory->create(name, description, date, priority);
    tasks.push_back(newtask);
    return newtask;
    //append into tasks vector
}

// Making new sub tasks  
Base* userSubTask(){
    SubtaskFactory * sfactory = new SubtaskFactory();
    string name;
    string date; 
    string description;
    bool complete; 
    int priority;

    cout << " Enter name of sub-task: " << endl; 
    getline(cin, name);
    cin.clear();
    cin.ignore(10000, '\n');

    cout << " Enter sub-task descrition: " << endl;
    getline(cin, description);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << " Enter sub-task due date (Please enter in Month/Day/Year format): " << endl;
    getline(cin, date);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << " Enter the level of sub-task priority from a level of 1-5 (1 being low priority, 5 being the most urgent): " << endl;
    cin >> priority; 

    subtask* newtask = sfactory->createSubtask(name, description, date, priority, complete);
    subt.push_back(newtask);
}

//for making new projects
Base* userProject(){
    ProjectFactory * ffactory = new ProjectFactory(); 
    string name; 
    string description;
    string date; 
    
    cout << " Enter name of project: " << endl;
    getline(cin, name);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << " Enter project descrition: " << endl;
    getline(cin, description);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << " Enter project due date (Please enter in Month/Day/Year format): " << endl; 
    getline(cin, date);
    cin.clear();
    cin.ignore(10000, '\n');
    project* newProject = ffactory->create(name, description, date);
    proj.push_back(newProject);
} 

Base* markTaskComplete(){
    task* task = nullptr;
    string taskName = "";
    viewIncTask();
    cout << "Please type the name of the task you wish to mark complete" << endl;
    getline(cin, taskName);
    cin.clear();
    cin.ignore(10000, '\n');

    for(int i=0; i<tasks.size(); i++){
        if(tasks[i]->getName() == taskName){
            task = tasks[i];
        }
    } 
    if(task == nullptr){
        cout<<"Sorry! Can't find your task"<<endl;
    }else{
    task->mark_as_complete();
    }
}

Base* makeProjectComplete(){
    char op2;
    cout<< "WARNING: Any Items in the project will be marked as completed"<<endl;
    cout<<"proceed? (Y/N)"<<endl;
    cin >> op2;
    if (op2 =='Y' || op2 == 'y'){
            viewProject();
        }
        else if (op2 == 'N' || op2 =='n'){
            return;
        }
        else{
            cout << "INVALID RESPONSE" << endl;
        }

}
void TaskSelect(){
    char op1;
    cout << "Would you like to select a Task? (Y/N)" << endl;
    cin >> op1;
    if (op1 =='Y' || op1 == 'y'){
            PromptTask();
        }
        else if (op1 == 'N' || op1 =='n'){
            return;
        }
        else{
            cout << "INVALID RESPONSE" << endl;
        }
}
void viewTaskMenu(){
    cout << " Select an option from the Menu:" << endl;
    cout << " A - Show Today's tasks" << endl;
    cout << " B - Show tasks via date" << endl; 
    cout << " C - Show tasks via priority" << endl;
    cout << " D - Show Completed Tasks" << endl; 
    cout << " E - Show Incomplete Tasks" << endl;
}
void promptTaskView(){
    viewTaskMenu();
    if (option =='A' || option == 'a'){
            viewTodayTask();
        }
        else if (option == 'B' || option =='b'){
            viewDateTask();
        }
        else if(option =='C' || option == 'c'){
            viewPriorityTask();
        }
        else if(option == 'D' || option == 'd'){
            viewComTask();
        }
        else if(option == 'E' || option == 'e'){
            viewIncTask();
        }else{
            cout << "INVALID RESPONSE" << endl;
        }
    TaskSelect();
}
void viewIncTask(){ //prints Incomplete tasks no sorting
    for(int i=0; i<tasks.size(); i++){
        if(!tasks[i]->complete()){
            cout << tasks[i] ->getName() << endl;
            cout << "    " << tasks[i] ->getDescription() << endl;
            if (tasks[i] ->get_date() != " "){
                if(tasks[i]->get_priority() != 0){
                    cout << "    " << tasks[i] ->get_date() << endl;
                    cout << "    " << tasks[i]->get_priority() << endl;
                }
            }
        }
    }
}
void viewComTask(){ //prints Complete tasks no sorting
    for(int i=0; i<tasks.size(); i++){
        if(tasks[i]->complete()){
            cout << tasks[i] ->getName() << endl;
            cout << "    " << tasks[i] ->getDescription() << endl;
            if (tasks[i] ->get_date() != " "){
                if(tasks[i]->get_priority() != 0){
                    cout << "    " << tasks[i] ->get_date() << endl;
                    cout << "    " << tasks[i]->get_priority() << endl;
                }
            }
        }
    }
}
void viewTodayTask(){
    cout <<"Today's Tasks"<< endl;
    for(int i=0; i<tasks.size();i++){
        if(tasks[i]->get_date() == s){
            if(!tasks[i]->complete()){
                cout << tasks[i] ->getName() << endl;
                cout << "    " << tasks[i] ->getDescription() << endl;
                if (tasks[i] ->get_date() != " "){
                    if(tasks[i]->get_priority() != 0){
                        cout << "    " << tasks[i] ->get_date() << endl;
                        cout << "    " << tasks[i]->get_priority() << endl;
                    }
                }
            }
        }
    }
}
void viewDateTask(){
    vector<task*> dateSorted(tasks);
    sort(dateSorted.begin(),dateSorted.end(),compare);
    for(int i=0; i<dateSorted.size(); i++){
        if(!dateSorted[i]->complete()){
            cout << dateSorted[i] ->getName() << endl;
            cout << "    " << dateSorted[i] ->getDescription() << endl;
            if (dateSorted[i] ->get_date() != " "){
                if(dateSorted[i]->get_priority() != 0){
                    cout << "    " << dateSorted[i] ->get_date() << endl;
                    cout << "    " << dateSorted[i]->get_priority() << endl;
                }
            }
        }
    }
}
void viewPriorityTask(){
    for(int i =0; i<tasks.size(); i++){
        if(tasks[i]->get_priority() == 5){
            cout << tasks[i] ->getName() << endl;
            cout << "    " << tasks[i] ->getDescription() << endl;
            if (tasks[i] ->get_date() != " "){
                if(tasks[i]->get_priority() != 0){
                    cout << "    " << tasks[i] ->get_date() << endl;
                    cout << "    " << tasks[i]->get_priority() << endl;
                }
            }
        }
    }
        for(int i =0; i<tasks.size(); i++){
        if(tasks[i]->get_priority() == 4){
            cout << tasks[i] ->getName() << endl;
            cout << "    " << tasks[i] ->getDescription() << endl;
            if (tasks[i] ->get_date() != " "){
                if(tasks[i]->get_priority() != 0){
                    cout << "    " << tasks[i] ->get_date() << endl;
                    cout << "    " << tasks[i]->get_priority() << endl;
                }
            }
        }
    }
        for(int i =0; i<tasks.size(); i++){
        if(tasks[i]->get_priority() == 3){
            cout << tasks[i] ->getName() << endl;
            cout << "    " << tasks[i] ->getDescription() << endl;
            if (tasks[i] ->get_date() != " "){
                if(tasks[i]->get_priority() != 0){
                    cout << "    " << tasks[i] ->get_date() << endl;
                    cout << "    " << tasks[i]->get_priority() << endl;
                }
            }
        }
    }
        for(int i =0; i<tasks.size(); i++){
        if(tasks[i]->get_priority() == 2){
            cout << tasks[i] ->getName() << endl;
            cout << "    " << tasks[i] ->getDescription() << endl;
            if (tasks[i] ->get_date() != " "){
                if(tasks[i]->get_priority() != 0){
                    cout << "    " << tasks[i] ->get_date() << endl;
                    cout << "    " << tasks[i]->get_priority() << endl;
                }
            }
        }
    }
        for(int i =0; i<tasks.size(); i++){
        if(tasks[i]->get_priority() == 1){
            cout << tasks[i] ->getName() << endl;
            cout << "    " << tasks[i] ->getDescription() << endl;
            if (tasks[i] ->get_date() != " "){
                if(tasks[i]->get_priority() != 0){
                    cout << "    " << tasks[i] ->get_date() << endl;
                    cout << "    " << tasks[i]->get_priority() << endl;
                }
            }
        }
    }
        for(int i =0; i<tasks.size(); i++){
        if(tasks[i]->get_priority() == 0){
            cout << tasks[i] ->getName() << endl;
            cout << "    " << tasks[i] ->getDescription() << endl;
            if (tasks[i] ->get_date() != " "){
                if(tasks[i]->get_priority() != 0){
                    cout << "    " << tasks[i] ->get_date() << endl;
                    cout << "    " << tasks[i]->get_priority() << endl;
                }
            }
        }
    }

    
}
void PromptTask(){
    task* task = nullptr;
    string taskName = "";
    viewIncTask();
    cout << "Please type the name of the task you wish to select." << endl;
    getline(cin, taskName);
    cin.clear();
    cin.ignore(10000, '\n');

    for(int i=0; i<tasks.size(); i++){
        if(tasks[i]->getName() == taskName){
            task = tasks[i];
        }
    }
    if(task == nullptr){
        cout<<"Sorry! Can't find your task"<<endl;
    }else{
        if(task->has_subtasks()){
            cout << "This task has subtasks, do you like to view? (Y/N)"<<endl;
            char subview;
            cin >> subview;
            if (subview =='Y' || subview == 'y'){
                showSubtasks(task);
            }
            else if (subview == 'N' || subview =='n'){
            return;
            }   
            else{
            cout << "INVALID RESPONSE" << endl;
            }
        }else{
            cout << "Sorry no avaliable options for this task"<<endl;
        }
    }
}
void showSubtasks(task* t){
    t->print_subtasks();
}

void viewProject(){
    for(int i=0; i<proj.size(); i++){
        cout << proj[i]->getName() <<endl;
        cout << "    " << proj[i]->getDescription() << endl;
        if (tasks[i] ->get_date() != " "){
            cout << "    " << proj[i]->getDescription() << endl;
        }
    }

}
void establishConnection(task* newtask){
    project* Addedproj = nullptr;
    string projectName= "";
    viewProject();
    cout << "select the project you wish to add this task"<< endl;
    getline(cin, projectName);
    cin.clear();
    cin.ignore(10000, '\n');

    for(int i=0; i<proj.size(); i++){
        if(proj[i]->getName() == projectName){
            Addedproj = proj[i];
        }
    } 
    if (Addedproj == nullptr){
        cout<<"Sorry! Can't find your project"<<endl;
    }else{
        Addedproj->add_item(newtask);
        cout << "Added task to Project" <<endl;
    }

}
void promptPTConnection(task* newtask){
    char op3;
    
    if(!proj.empty()){
        cout << "Would you like to add this task to a Project?(Y/N)" << endl;
        cin >> op3;
        if (op3 =='Y' || op3 == 'y'){
            establishConnection(newtask);
        }
        else if (op3 == 'N' || op3 =='n'){
            return;
        }
        else{
            cout << "INVALID RESPONSE" << endl;
        }
    }else{
        return;
    }
}
int main(){
    Fio.readTask("tasks.txt");
    Fio.readSub("sub.txt");
    Fio.readProject("proj.txt");
    Fio.readTaskRelations("task_rel.txt",tasks,subt);
    Fio.readProjectRelations("proj_rel.txt",proj,tasks);


    setToday();
    cout<< " Welcome to the Task Scheduler! "<<endl;
    
    do{ 
        printMenu();
        cin >> option;
        cout << endl;

        if (option =='A' || option == 'a'){
            task* newtask = usertask();
            promptPTConnection(newtask);
        }
        else if (option == 'B' || option =='b'){
            userSubTask();
        }
        else if(option =='C' || option == 'c'){
            markTaskComplete();
        }
        else if(option == 'D' || option == 'd'){
            userProject();
        }
        else if(option == 'E' || option == 'e'){
            makeProjectComplete();
        }
        else if(option == 'F' || option == 'f'){
            promptTaskView();
        }
        else if(option == 'G' || option == 'g'){
            viewProject();
        }
           
}while(option != 'q' && option != 'Q');

Fio.writeTask("tasks.txt",tasks);
Fio.writeSub("sub.txt",subt);
Fio.writeProject("proj.txt",proj);
Fio.writeTaskRelations("task_rel.txt",tasks);
Fio.writeProjectRelations("proj_rel.txt",proj);
}
