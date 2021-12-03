 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Task Scheduler
Authors: [August Bennett](https://github.com/augustpbennett), [Johnny To](https://github.com/Drabblesaur), [Lorenzo Gonzalez](https://github.com/lorenzog1), [Nick Lin](https://github.com/YYUWS)
 

# Project Description

### Why it is Important.

Either in school or work, sometimes we feel overwhelmed with the amount of tasks and instructions that we need to perform week by week. Ways to organize these task is paramount for students or even heavy workflows.

### What languages/tools/technologies do you plan to use?

This project will be written in C++ and will be run via the terminal. (This may change during development). There is ongoing discussion and research in what to do for the GUI of this project.

### I/O and Features

In this application, a user can create tasks including a title, description, classification (e.g. personal, work, study), priority, duration, and due date. Users can also create Projects that includes multiple tasks. Task lists can represent larger tasks that have subtasks within them. Tasks that have subtasks are required to have their Subtasks finished or removed before marked as complete. Users can display, edit, and delete tasks and Projects. Users can view their tasks in intuitive ways such as via Date, Priority, and even check Today's Tasks. After ending the program, the system will store the created objects in a file such that when you start up the progrma again they automatically load the relavant objects.

### TLDR: Features

Create Detailed Tasks  

- Title, Description, Classification, Priority, Duration, and Due Dates.
- Create Task Lists and Stacked Tasks.
- Edit and Delete Tasks.

## Class Diagram
![Class Diagram](https://github.com/cs100/final-project-jto015-nlin039-abenn031-lgonz173/blob/master/Images/New%20UML.png?raw=true)
This Class Diagram Implements 2 Design Patterns. The first design pattern is the Composite Design Pattern. This is implemented in the construction of the Project and the Tasks class being subclasses to the Abstract Class Base. Next is the Factory Design Pattern. There are 3 Factories we are creating, each represent a different essential file to be created in runtime.

## Design Patterns we used
We Picked a Base Design Pattern because it allows us to delegate certain items like marking tasks as complete in the context of a Project. For the Factories, That allows us to easily create these objects in runtime and be used by the client. They helped us to write better code by 

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
