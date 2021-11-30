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

In this application, a user can create tasks including a title, description, classification (e.g. personal, work, study), priority, duration, and due date. Some of these features can also be optional. Users can also create task lists where each list includes multiple tasks. Task lists can represent larger tasks that have subtasks within them. Users can display, edit, and delete tasks and task lists. Users should also be able to undo these operations.

### TLDR: Features

Create Detailed Tasks  

- Title, Description, Classification, Priority, Duration, and Due Dates.
- Create Task Lists and Stacked Tasks.
- Edit and Delete Tasks.

## Class Diagram
![Class Diagram](https://github.com/cs100/final-project-jto015-nlin039-abenn031-lgonz173/blob/master/Images/New%20UML.png?raw=true)
This Class Diagram Implements 2 Design Patterns. The first design pattern is the Composite Design Pattern. This is implemented in the construction of the Project and the Tasks class being subclasses to the Abstract Class Base(Name TBD). Next is the Factory Design Pattern. This is a pseudo Abstract design pattern. (We may or may not need the abstractFactory to be implemeted) But with the Factories such as TaskFactory and ProjectFatory, the client can create these objects much faster.
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II.
 > * You should also update this README file by adding the following:
 >   * What design patterns did you use? For each design pattern you must explain in 4-5 sentences:
 >     * Why did you pick this pattern? And what feature did you implement with it?
 >     * How did the design pattern help you write better code?
 >   * An updated class diagram that reflects the design patterns you used. You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
 >   * Make sure your README file (and Project board) are up-to-date reflecting the current status of your project. Previous versions of the README file should still be visible through your commit history.
> 
> During the meeting with your TA you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
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
 
