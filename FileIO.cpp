#include <iostream>
#include <vector>
#include <string>
#include "Base.hpp"
#include "task.hpp"
#include <fstream>

using std::string;
using std::vector;

class FileIO{
public:
    FileIO();
    ~FileIO();
    void readTask(string fileName){
        std::ifstream inFS;
        inFS.open(fileName);

        vector<Base*> taskList;

        int numVectors =0;
        std::string name;
        std::string descript;
        int priority;
        std::string date;
        bool complete;

        if (!inFS.is_open()) {
            std::cout << "Error opening " << fileName << std::endl;
        }
        inFS >> numVectors;
        for(int i =0; i<numVectors; i++){
            std::getline(inFS, name);
            std::getline(inFS,descript);
            inFS >> priority;
            std::getline(inFS, date);
            inFS >> complete;
            Base* newBase = new task(name, descript, priority, date, complete);
            taskList.push_back(newBase)
        }
    }
    void readProject(string fileName){
        std::ifstream inFS;
        inFS.open(fileName);
        int numVectors =0;
        std::string name;
        std::string descript;
        std::string date;
        bool complete;
        vector<Base*> projectList;

        if (!inFS.is_open()) {
            std::cout << "Error opening " << fileName << std::endl;
        }
        inFS >> numVectors;
        for(int i =0; i<numVectors; i++){
            std::getline(inFS, name);
            std::getline(inFS,descript);
            std::getline(inFS, date);
            inFS >> complete;
            Base* newBase = new project(name, descript, date, complete);
            projectList.push_back(newBase);

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
        bool complete;
        vector<Base*> subList;

        if (!inFS.is_open()) {
            std::cout << "Error opening " << fileName << std::endl;
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
    }
    
    void writeTask(string fileName,vector<Base*> taskList){
        std::ofstream outFS;
        outFS.open(fileName);
        outFS << taskList.size() << std::endl;
        for(int i =0; i<taskList.size(); i++){
            outFS << taskList[i]->getName() << std::endl;
            outFS << taskList[i]->getDescription() << std::endl;
            outFS << taskList[i]->getPriority() << std::endl;
            outFS << taskList[i]->getDate() << std::endl;
            outFS << taskList[i]->getComplete() << std::endl;
        }
    }
    void writeProject(string fileName,vector<Base*> projList)
    void writeSub(string fileName,vector<Base*> subtaskList)
};