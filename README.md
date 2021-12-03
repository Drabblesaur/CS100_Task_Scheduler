# Task Scheduler
Authors: [August Bennett](https://github.com/augustpbennett), [Johnny To](https://github.com/Drabblesaur), [Lorenzo Gonzalez](https://github.com/lorenzog1), [Nick Lin](https://github.com/YYUWS)
 

# Project Description

### Why it is Important.

Either in school or work, sometimes we feel overwhelmed with the amount of tasks and instructions that we need to perform week by week. Ways to organize these task is paramount for students or even heavy workflows.

### What languages/tools/technologies do you plan to use?

This project will be written in C++ and will be run via the terminal. (This may change during development). There is ongoing discussion and research in what to do for the GUI of this project.

### I/O and Features

In this application, a user can create tasks including a title, description, classification (e.g. personal, work, study), priority, duration, and due date. Users can also create Projects that includes multiple tasks. Task lists can represent larger tasks that have subtasks within them. Tasks that have subtasks are required to have their Subtasks finished or removed before marked as complete. Users can display, edit, and delete tasks and Projects. Users can view their tasks in intuitive ways such as via Date, Priority, and even check Today's Tasks.

### TLDR: Features

Create Detailed Tasks  

- Title, Description, Classification, Priority, Duration, and Due Dates.
- Create Task Lists and Stacked Tasks.
- Edit and Delete Tasks.

## Class Diagram
![Class Diagram](https://github.com/cs100/final-project-jto015-nlin039-abenn031-lgonz173/blob/master/Images/New%20UML.png?raw=true)
This Class Diagram Implements 2 Design Patterns. The first design pattern is the Composite Design Pattern. This is implemented in the construction of the Project and the Tasks class being subclasses to the Abstract Class `Base`. Next is the Factory Design Pattern. There are 3 Factories we are creating, each represent a different essential file to be created in runtime.

## Design Patterns we used
We Picked a Base Design Pattern because it allows us to delegate certain items like marking tasks as complete in the context of a Project. For the Factories, That allows us to easily create these objects in runtime and be used by the client. They helped us to write better code by allowing us to seperate the creation and the structure of the code into two seperate items wwe can then code upon.

 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 If working in the terminal(or in hammer),
 1. Clone Repo.
 2. run `cmake3 .` to create the testing file and the task_scheduler file.
 3. run `./task_scheduler` to run the driver.
 4. run `./test` to check out all tests
 ## Testing
 This project was tested using GoogleTest.
 
