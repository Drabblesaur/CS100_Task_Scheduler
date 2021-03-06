#include <iostream>
#include <vector>
#include <string>
#include "Base.hpp"
#include "task.hpp"
#include "project.hpp"
#include <fstream>

using std::string;
using std::vector;

class FileIO{
public:
    FileIO() {}
    ~FileIO() {}
    vector<task*> readTask(string fileName){
        std::ifstream inFS;
        inFS.open(fileName);

        vector<task*> taskList;

        int numVectors =0;
        std::string line;
        std::string name;
        std::string descript;
        int priority;
        std::string date;
        bool complete = false;

        if (!inFS.is_open()) {
            //std::cout << "Error opening " << fileName << std::endl;
            return taskList;
        }else{
            std::getline(inFS, line);
            numVectors = std::stoi(line);

            for(int i =0; i<numVectors; i++){
                std::getline(inFS, line);
                name = line;
                std::getline(inFS,line);
                descript = line;
                std::getline(inFS,line);
                priority = std::stoi(line);
                std::getline(inFS, line);
                date = line;
                std::getline(inFS, line);
                if(line == "true"){
                    complete = true;
                }
                else{
                    complete = false;
                }
                task* newBase = new task(name, descript, date, priority, complete); 
                taskList.push_back(newBase);
            }
            inFS.close();
            return taskList;
        }
    }
    void readProject(string fileName){
        std::ifstream inFS;
        inFS.open(fileName);
        int numVectors =0;
        std::string name;
        std::string descript;
        std::string date;
        bool complete = false;;
        vector<Base*> projectList;

        if (!inFS.is_open()) {
            //std::cout << "Error opening " << fileName << std::endl;
        }
        inFS >> numVectors;
        for(int i =0; i<numVectors; i++){
            std::getline(inFS, name);
            std::getline(inFS,descript);
            std::getline(inFS, date);
            inFS >> complete;
            Base* newBase = new project(name, descript, date, complete); //FIX PROJ
            projectList.push_back(newBase);

        }
        inFS.close();
        for (int i = 0; i < projectList.size(); i++) {
            delete projectList[i];
        }
    }
    void readSub(string fileName){
        std::ifstream inFS;
        inFS.open(fileName);

        int numVectors =0;
        std::string name;
        std::string descript;
        int priority;
        std::string date;
        bool complete = false;
        vector<Base*> subList;

        if (!inFS.is_open()) {
            //std::cout << "Error opening " << fileName << std::endl;
        }
        inFS >> numVectors;
        for(int i =0; i<numVectors; i++){
            std::getline(inFS, name);
            std::getline(inFS,descript);
            inFS >> priority;
            std::getline(inFS, date);
            inFS >> complete;
            Base* newBase = new subtask(name, descript, priority, date, complete);
            subList.push_back(newBase);
        }
        inFS.close();
        for (int i = 0; i < subList.size(); i++) {
            delete subList[i];
        }
    }
    void readTaskRelations(string filename, vector<task*> taskList, vector<subtask*>sublist){
        std::ifstream inFS;
        inFS.open(filename);

        int numVectors =0;
        int numSubs =0;
        std::string name;
        std::string TaskName;
        task* taskPtr = nullptr;
        subtask* subPtr = nullptr;


        if (!inFS.is_open()) {
            //std::cout << "Error opening " << filename << std::endl;
        }
        inFS >> numVectors;
        for(int i=0; i<numVectors; i++){
            std::getline(inFS, TaskName);
            //search for task using name
            for(int j=0; j<taskList.size(); j++){
                if(taskList[j]->getName() == TaskName){
                    taskPtr = taskList[j];
                }
            }
            inFS >> numSubs;
            for(int k=0; k<numSubs; k++){
                std::getline(inFS, name);
                //search for subtask using name
                for(int l=0; l<sublist.size(); l++){
                    if(sublist[l]->getName() == TaskName){
                        subPtr = sublist[l];
                    }
                }
                taskPtr->add_subtask(subPtr);
            }

        }
        inFS.close();
    }
    void readProjectRelations(string filename, vector<project*> projectList, vector<task*> taskList){
        std::ifstream inFS;
        inFS.open(filename);

        int numVectors =0;
        int numTasks =0;
        std::string name;
        std::string projectName;
        project* projectPtr = nullptr;
        Base* itemptr = nullptr;

        inFS >> numVectors;
        for(int i=0; i<numVectors; i++){
            std::getline(inFS, projectName);
            //search for project using name
            for(int j=0; j<projectList.size(); j++){
                if(projectList[j]->getName() == projectName){
                    projectPtr = projectList[j];
                }
            }
            inFS >> numTasks;
            for(int k=0; k<numTasks; k++){
                std::getline(inFS, name);
                //search for task using name
                for(int l=0; l<taskList.size(); l++){
                    if(taskList[l]->getName() == name){
                        itemptr = taskList[l];
                    }
                }
                for(int m=0; m<projectList.size(); m++){
                if(projectList[m]->getName() == projectName){
                    itemptr = projectList[m];
                }
                }
                projectPtr->add_item(itemptr);
            }
        }
        inFS.close();
    }


    void writeTask(string fileName,vector<task*> taskList){
        std::ofstream outFS;
        outFS.open(fileName);
        outFS << taskList.size() << std::endl;
        for(int i =0; i<taskList.size(); i++){
            outFS << taskList[i]->getName() << std::endl;
            outFS << taskList[i]->getDescription() << std::endl;
            outFS << taskList[i]->get_priority() << std::endl;
            outFS << taskList[i]->get_date() << std::endl;
            outFS << taskList[i]->complete() << std::endl;
        }
        outFS.close();
    }
    void writeProject(string fileName,vector<project*> projList){
         std::ofstream outFS;
        outFS.open(fileName);
        outFS << projList.size() << std::endl;
        for(int i =0; i<projList.size(); i++){
            outFS << projList[i]->getName() << std::endl;
            outFS << projList[i]->getDescription() << std::endl;
            outFS << projList[i]->get_date() << std::endl;
        }
        outFS.close();
    }
    void writeSub(string fileName,vector<subtask*> subtaskList){
        std::ofstream outFS;
        outFS.open(fileName);
        outFS << subtaskList.size() << std::endl;
        for(int i =0; i<subtaskList.size(); i++){
            outFS << subtaskList[i]->getName() << std::endl;
            outFS << subtaskList[i]->getDescription() << std::endl;
            outFS << subtaskList[i]->get_priority() << std::endl;
            outFS << subtaskList[i]->get_date() << std::endl;
            outFS << subtaskList[i]->complete() << std::endl;
        }
        outFS.close();
    }
    void writeTaskRelations(string fileName,vector<task*> taskList){
        std::ofstream outFS;
        outFS.open(fileName);
        outFS << taskList.size() << std::endl;
        for(int i =0; i<taskList.size(); i++){
            if(taskList[i]->has_subtasks()){
                outFS << taskList[i]->getName() << std::endl;
                vector<subtask*> stask = taskList[i]->get_subtasks();
                outFS << stask.size() << std::endl;
                for(int j =0; j<stask.size(); j++){
                    outFS << stask[j]->getName() << std::endl;
                }
            }
        }
        outFS.close();
    }
    void writeProjectRelations(string fileName,vector<project*> projList){
        std::ofstream outFS;
        outFS.open(fileName);
        outFS << projList.size() << std::endl;
        for(int i; i<projList.size(); i++){
            if(projList[i]->has_elements()){
                outFS << projList[i]->getName() << std::endl;
                vector<Base*> items = projList[i]->get_items();
                for(int j =0; j<items.size(); j++){
                    outFS << items[j]->getName() << std::endl;
                }
            }else{
                outFS << projList[i]->getName() << std::endl;
                outFS << 0 << std::endl;
            }
        }
        outFS.close();
    }
};
