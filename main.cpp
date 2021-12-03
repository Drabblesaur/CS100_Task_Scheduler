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
#include <algorithm>

using namespace std;

FileIO Fio;
vector <project *>proj;
vector <subtask *>subt;
vector <task *>tasks; 
char option;
char s[80];

void viewAllTask();
void viewIncTask();
void viewProject();
void PromptTask();
void viewTodayTask();
void viewDateTask();
void viewPriorityTask();
void viewComTask();
void viewIncTask();
void viewDateTask();
void showSubtasks(task *t);

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
task* taskSearch(string name){
    for(int i=0; i<tasks.size(); i++){
        if(tasks[i]->getName() == name){
            return tasks[i];
        }
    } 
    return NULL;
}
project* projectSearch(string name){
    for(int i=0; i<proj.size(); i++){
        if(proj[i]->getName() == name){
            return proj[i];
        }
    } 
    return NULL;
}
subtask* subtaskSearch(string name){
    for(int i=0; i<subt.size(); i++){
        if(subt[i]->getName() == name){
            return subt[i];
        }
    } 
    return NULL;
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

// Creates a Task
task* usertask(){
    TaskFactory * tfactory = new TaskFactory();
    string name;
    string date; 
    string description;
    int priority;
 
    cout << " Enter name of task: " << endl;
    getline(cin >> ws, name);
    //cin.clear();
    //cin.ignore(10000, '\n');
    cout << " Enter task description: " << endl;
    getline(cin >> ws, description);
    //cin.clear();
    //cin.ignore(10000, '\n');
    cout << " Enter task due date (Please enter in Month/Day/Year format): " << endl;
    getline(cin >> ws, date);
    //cin.clear();
   // cin.ignore(10000, '\n');
    cout << " Enter the level of task priority from a level of 1-5 (1 being low priority, 5 being the most urgent): " << endl;
    cin >> priority; 

    task* newtask = tfactory->create(name, description, date, priority);
    tasks.push_back(newtask);
    return newtask;
    //append into tasks vector
}

// Asks for an existing Incomplete task and creates a Subtask to be assigned.
Base* userSubTask(){
    SubtaskFactory * sfactory = new SubtaskFactory();
    string taskname;
    task* t;
    string name;
    string date; 
    string description;
    bool complete; 
    int priority;
    viewIncTask();
    cout << " Enter name of Task: " << endl;

    getline(cin >> ws, taskname);
    //cin.clear();
    //cin.ignore(10000, '\n');

    t = taskSearch(taskname);
    if (t == NULL){
        cout << " Task not found. Please try again." << endl;
    }else{
        //cin.clear();
        //cin.ignore(10000, '\n');
        cout << " Enter name of sub-task: " << endl; 
        getline(cin >> ws, name);
        //cin.clear();
      //  cin.ignore(10000, '\n');

        cout << " Enter sub-task description: " << endl;
        getline(cin.ignore() >> ws, description);
        //cin.clear();
        //cin.ignore(10000, '\n');
        cout << " Enter sub-task due date (Please enter in Month/Day/Year format): " << endl;
        getline(cin >> ws, date);
        //cin.clear();
        //cin.ignore(10000, '\n');
        cout << " Enter the level of sub-task priority from a level of 1-5 (1 being low priority, 5 being the most urgent): " << endl;
        cin >> priority; 
        subtask* newtask = sfactory->createSubtask(name, description, date, priority, complete);
        subt.push_back(newtask);
        t->add_subtask(newtask);
    }
}

// Creates an Empty Project
Base* userProject(){
    ProjectFactory * ffactory = new ProjectFactory(); 
    string name; 
    string description;
    string date; 
    
    cout << " Enter name of project: " << endl;
    getline(cin >> ws, name);
    //cin.clear();
 //   cin.ignore(10000, '\n');
    cout << " Enter project description: " << endl;
    getline(cin >> ws, description);
    //cin.clear();
    //cin.ignore(10000, '\n');/
    cout << " Enter project due date (Please enter in Month/Day/Year format): " << endl; 
    getline(cin >> ws, date);
    //cin.clear();
    //cin.ignore(10000, '\n');
    project* newProject = ffactory->create(name, description, date);
    proj.push_back(newProject);
} 

// Marks a task as complete (need to check subtasks)
Base* markTaskComplete(){
    task* task = nullptr;
    string taskName = "";
    viewIncTask();
    cout << "Please type the name of the task you wish to mark complete" << endl;
    getline(cin >> ws, taskName);
    //cin.clear();
    //cin.ignore(10000, '\n');
    task = taskSearch(taskName);
    if (task == NULL){
        cout << "Task not found. Please try again." << endl;
    }else{
        task->mark_as_complete();
    }
}

//INCOMPLETE 
Base* makeProjectComplete(){
    char op2;
    cout<< "WARNING: Any Items in the project will be marked as completed"<<endl;
    cout<<"proceed? (Y/N)"<<endl;
    cin >> op2;
    if (op2 =='Y' || op2 == 'y'){
            viewProject();
        }
        else if (op2 == 'N' || op2 =='n'){
            return nullptr;
        }
        else{
            cout << "INVALID RESPONSE" << endl;
        }

}
//Ask user if they wish to select a particular task.
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
            return;
        }
}
//prints Tasks Menu
void viewTaskMenu(){
    cout << " Select an option from the Menu:" << endl;
    cout << " A - Show Today's tasks" << endl;
    cout << " B - Show tasks via date" << endl; 
    cout << " C - Show tasks via priority" << endl;
    cout << " D - Show Completed Tasks" << endl; 
    cout << " E - Show Incomplete Tasks" << endl;
    cout << " F - Show All Tasks" << endl;
    cout << " Q - Return to Main Menu" << endl;
}
//Print Task Operation Menu
void printTaskOperations(){
    cout << " Select an option from the Menu:" << endl;
    cout << " A - Mark Task Incomplete (Completed Tasks Only)" << endl;
    cout << " B - Remove Subtask" << endl;
    cout << " C - View Subtasks" << endl;
    cout << " D - View Full Task Details" << endl;
    cout << " Q - Return to Main Menu" << endl;
}
// View Tasks and check in tasks is empty
void promptTaskView(){
    bool hascompleted = false;
    bool isIncomplete = false;
    char op5;
    viewTaskMenu();
    cin >> op5;
    if (op5 =='A' || op5 == 'a'){
        if (tasks.empty()){
            cout<<"No tasks to show"<<endl;
        }else{
            viewTodayTask();
            TaskSelect();
        }
        }
        else if (op5 == 'B' || op5 =='b'){
            if (tasks.empty()){
                cout<<"No tasks to show"<<endl;
            }else{
                viewDateTask();
                TaskSelect();
            }
        }
        else if(op5 =='C' || op5 == 'c'){
            if (tasks.empty()){
                cout<<"No tasks to show"<<endl;
            }else{
                viewPriorityTask();
                TaskSelect();
            }
        }
        else if(op5 == 'D' || op5 == 'd'){
            for (int i = 0; i < tasks.size(); i++){
                if (tasks[i]->complete() == true){
                    hascompleted = true;
                }
            }
            if (hascompleted == false){
                cout << "No completed tasks" << endl;
            }else{
                viewComTask();
                TaskSelect();
            }
        }
        else if(op5 == 'E' || op5 == 'e'){
            for (int i = 0; i < tasks.size(); i++){
                if (tasks[i]->complete() == false){
                    isIncomplete = true;
                }
            }
            if (isIncomplete == true){
                viewIncTask();
                TaskSelect();
            }else{
                cout << "All Tasks Complete!" << endl;
            }
        }else if(op5 == 'F' || op5 == 'f'){
            if (tasks.empty()){
                cout<<"No tasks to show"<<endl;
            }else{
                viewAllTask();
                TaskSelect();
            }
        }else if(op5 == 'Q' || op5 == 'q'){
            return;
        }else{
            cout << "Invalid input. Please try again." << endl;
        }
}
//ALL TASK PRINTS
void viewAllTask(){
    for (int i = 0; i < tasks.size(); i++){
        cout << "Name: " << tasks[i]->getName() << endl;
        cout << "    Description: " << tasks[i]->getDescription() << endl;
        cout << "    Due Date: " << tasks[i]->get_date() << endl;
        cout << "    Priority: " << tasks[i]->get_priority() << endl;
        cout << "    Completion: " << boolalpha << tasks[i]->complete() << endl;
        cout << "    Has Subtasks: " << boolalpha<< tasks[i]->has_subtasks() << endl;
    }
}
void viewIncTask(){ //prints Incomplete tasks no sorting
    for(int i=0; i<tasks.size(); i++){
        if(!tasks[i]->complete()){
            cout << "Name: " << tasks[i]->getName() << endl;
            cout << "    Description: " << tasks[i]->getDescription() << endl;
            if (tasks[i] ->get_date() != " "){
                if(tasks[i]->get_priority() != 0){
                    cout << "    Due Date: " << tasks[i]->get_date() << endl;
                    cout << "    Priority: " << tasks[i]->get_priority() << endl;
                }
            }
            cout << "    Has Subtasks: " << boolalpha << tasks[i]->has_subtasks() << endl;
        }
    }
}
void viewComTask(){ //prints Complete tasks no sorting
    for(int i=0; i<tasks.size(); i++){
        if(tasks[i]->complete()){
            cout << "Name: " << tasks[i]->getName() << endl;
            cout << "    Description: " << tasks[i]->getDescription() << endl;
            if (tasks[i] ->get_date() != " "){
                if(tasks[i]->get_priority() != 0){
                    cout << "    Due Date: " << tasks[i]->get_date() << endl;
                    cout << "    Priority: " << tasks[i]->get_priority() << endl;
                }
            }
            cout << "    Has Subtasks: " << boolalpha << tasks[i]->has_subtasks() << endl;
        }
    }
}
void viewTodayTask(){
    cout <<"Today's Tasks"<< endl;
    for(int i=0; i<tasks.size();i++){
        if(tasks[i]->get_date() == s){
            if(!tasks[i]->complete()){
                cout << "Name: " << tasks[i]->getName() << endl;
                cout << "    Description: " << tasks[i]->getDescription() << endl;
                if (tasks[i] ->get_date() != " "){
                    if(tasks[i]->get_priority() != 0){
                        cout << "    Due Date: " << tasks[i]->get_date() << endl;
                        cout << "    Priority: " << tasks[i]->get_priority() << endl;
                    }
                }
                cout << "    Has Subtasks: " << boolalpha << tasks[i]->has_subtasks() << endl;
            }
        }
    }
}
void viewDateTask(){
    vector<task*> dateSorted(tasks);
    sort(dateSorted.begin(),dateSorted.end(),compare);
    for(int i=0; i<dateSorted.size(); i++){
        if(!dateSorted[i]->complete()){
            cout << "Name: " << tasks[i]->getName() << endl;
            cout << "    Description: " << tasks[i]->getDescription() << endl;
            if (dateSorted[i] ->get_date() != " "){
                if(dateSorted[i]->get_priority() != 0){
                    cout << "    Due Date: " << tasks[i]->get_date() << endl;
                    cout << "    Priority: " << tasks[i]->get_priority() << endl;
                }
            }
            cout << "    Has Subtasks: " << boolalpha << tasks[i]->has_subtasks() << endl;
        }
    }
}
void viewPriorityTask(){
    for(int j =5; j <= 0; j--){
        for(int i =0; i<tasks.size(); i++){
            if(tasks[i]->get_priority() == j){
                cout << "Name: " << tasks[i]->getName() << endl;
                cout << "    Description: " << tasks[i]->getDescription() << endl;
                if (tasks[i] ->get_date() != " "){
                    if(tasks[i]->get_priority() != 0){
                        cout << "    Due Date: " << tasks[i]->get_date() << endl;
                        cout << "    Priority: " << tasks[i]->get_priority() << endl;
                    }
                }
                cout << "    Has Subtasks: " << boolalpha << tasks[i]->has_subtasks() << endl;
            }
        }
    }
}
//Searchs for the task and asks what to do with it
void PromptTask(){
    task* task;
    string taskName = "";
    viewIncTask();
    cout << "Please type the name of the task you wish to select." << endl;
    getline(cin >> ws, taskName);
    //cin.clear();
    //cin.ignore(10000, '\n');
    task = taskSearch(taskName);
    if (task == NULL){
        cout << "Task not found. Please try again." << endl;
    }else{
        printTaskOperations();
        char op6;
        cin >> op6;
        if (op6 == 'A' || op6 == 'a'){
            if(task->complete()){
                task->mark_as_incomplete();
                cout << "Task marked as incomplete." << endl;
            }else{
                cout << "Task already marked as incomplete." << endl;
            }
        }else if (op6 == 'B' || op6 == 'b'){
            subtask* sub;
            string subName;
            showSubtasks(task);
            cout << "Please Select a Subtask to remove" << endl;
            getline(cin >> ws, subName);
            //cin.clear();
            //cin.ignore(10000, '\n');
            sub = task->remove_subtask(subName);
            for (size_t i = 0; i < subt.size(); i++) {
                if (subt.at(i) == sub) {
                    subt.erase(subt.begin() + i);
                }
            }
            cout << "Subtask removed." << endl;
        }else if (op6 == 'C' || op6 == 'c'){
            showSubtasks(task);
        }else if (op6 == 'D' || op6 == 'd'){
            cout << "Name: " << task->getName() << endl;
            cout << "    Description: " << task->getDescription() << endl;
            cout << "    Due Date: " << task->get_date() << endl;
            cout << "    Priority: " << task->get_priority() << endl;
            cout << "    Completion: " << task->complete() << endl;
            cout << "    Subtasks: " << task->has_subtasks() << endl;
            if(task->has_subtasks()){
                showSubtasks(task);
            }
        }else if (op6 == 'Q' || op6 == 'Q'){
            return;
        }else{
            cout << "Invalid input. Please try again." << endl;
            return;
        }
    }
    /*
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
    */
}
//Shows Subtasks from a task
void showSubtasks(task* t){
    t->print_subtasks();
}

void viewProject(){
    for(int i=0; i<proj.size(); i++){
        cout << "Name: " << proj[i]->getName() <<endl;
        cout << "    Description: "  << proj[i]->getDescription() << endl;
        if (tasks[i] ->get_date() != " "){
            cout << "    Due Date: " << proj[i]->getDescription() << endl;
        }
    }

}
void establishConnection(task* newtask){
    project* Addedproj = nullptr;
    string projectName= "";
    viewProject();
    cout << "select the project you wish to add this task"<< endl;
    getline(cin >> ws, projectName);
    //cin.clear();
    //cin.ignore(10000, '\n');

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
