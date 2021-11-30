#include "../task.cpp"
#include "../Base.cpp"
#include "../subtask.cpp"
#include "../project.cpp"

TEST(constructor_test, main_constructor) {
   task testTask("test task", "mock task for testing constructor", "11/30/2021", 1);
   
   EXPECT_EQ("test task", testTask.getName());
}

TEST(constructor_test, io_constructor) {
   task testTask("test task", "mock task for testing io constructor", "11/30/2021", 1, 1);

   EXPECT_EQ(1, testTask.complete());
}

TEST(complete, is_false) {
   task testTask;

   EXPECT_FALSE(testTask.complete());
}

TEST(complete, is_true) {
   task testTask;

   testTask.mark_as_complete();

   EXPECT_TRUE(testTask.complete());
}

TEST(get_priority, default_constructor) {
   task testTask;

   EXPECT_EQ(0, testTask.get_priority());
}

TEST(get_priority, param_constructor) {
   task testTask("11/30/2021", 2);

   EXPECT_EQ(2, testTask.get_priority());
}

TEST(set_priority, set_from_default) {
   task testTask;
   testTask.set_priority(5);

   EXPECT_EQ(5, testTask.get_priority());
}

TEST(set_priority, set_from_param) {
   task testTask("11/30/2021", 5);
   testTask.set_priority(1);

   EXPECT_EQ(1, testTask.get_priority());
}

TEST(mark_as_complete, no_subtasks) {
   task testTask("11/30/2021", 1);

   testTask.mark_as_complete();
   
   EXPECT_TRUE(testTask.complete());
}

TEST(mark_as_complete, has_subtasks) {
   task testTask("11/30/2021", 1);
  
   testTask.add_subtask("test subtask", "11/30/2021", 0);

   testTask.mark_as_complete();

   EXPECT_FALSE(testTask.complete());
}

TEST(mark_as_incomplete, starting_incomplete) {
   task testTask("11/30/2021", 1);

   testTask.mark_as_incomplete();

   EXPECT_FALSE(testTask.complete());
}

TEST(mark_as_incomplete, starting_complete) {
   task testTask("test task", "task description", "11/30/2021", 4, 1);

   testTask.mark_as_incomplete();

   EXPECT_FALSE(testTask.complete());
}

TEST(add_subtask, default_fn) {
   task testTask;
   subtask *testSubtask = new subtask;

   testTask.add_subtask(testSubtask);
   testTask.mark_as_complete();

   EXPECT_FALSE(testTask.complete());
}

TEST(add_subtask, parameterized) {
   task testTask("11/30/2021", 2);
   subtask *testSubtask = new subtask("subtask 1", "dummy subtask", "11/30/2021", 0);
   testTask.add_subtask(testSubtask);

   EXPECT_FALSE(testTask.complete());
}

TEST(complete_subtask, default_subtask) {
   task testTask("11/30/2021", 2);
   subtask *testSubtask = new subtask;

   testTask.add_subtask(testSubtask);

   testTask.complete_subtask("");

   testTask.mark_as_complete();

   EXPECT_TRUE(testTask.complete());
}

TEST(complete_subtask, parameterized) {
   task testTask("11/30/2021", 2);
   subtask *testSub = new subtask("subtask 1", "dummy subtask", "11/30/2021", 0);

   testTask.add_subtask(testSub);

   testTask.complete_subtask("subtask 1");

   testTask.mark_as_complete();

   EXPECT_TRUE(testTask.complete());
}

TEST(search, search_for_existing_sub) {
   task testTask("11/30/2021", 1);
   subtask *testSub = new subtask("subtask 1", "dummy subtask", "11/30/2021", 1);
   testTask.add_subtask(testSub);

   subtask *sub = testTask.search("subtask 1");

   EXPECT_EQ(sub->getName(), "subtask 1");
}

TEST(search, search_for_nonexisting_sub) {
   task testTask("11/30/2021", 1);
   subtask *testSub = new subtask("subtask 1", "dummy subtask", "11/30/2021", 1);
   testTask.add_subtask(testSub);

   subtask *sub = testTask.search("nonexistent subtask");

   EXPECT_EQ(sub, nullptr);
}  

TEST(project_add_task, default_task) {
    project testProj;

    testProj.add_task();

    EXPECT_TRUE(testProj.has_elements());
}

TEST(project_add_task, param_task) {
    project testProj;

    testProj.add_task("new task", "11/30/2021", 1);

    EXPECT_TRUE(testProj.has_elements());
}

TEST(project_add_project, new_proj) {
    project testProj;
    
    project *subp = new project();
    testProj.add_Project(subp);

    EXPECT_TRUE(testProj.has_elements());
}

TEST(project_search, search_for_task) {
    project testProj;

    testProj.add_task("new task", "11/30/2021", 1);

    Base *task = testProj.search("new task");

    EXPECT_EQ(task->getName(), "new task");
}

TEST(project_search, search_for_task_DNE) {
    project testProj;

    testProj.add_task("new task", "11/30/2021", 1);

    Base *task = testProj.search("aoeuidhtns");

    EXPECT_EQ(task, nullptr);
}

TEST(has_elements, has_tasks) {
    project testProj;

    testProj.add_task("new task", "11/30/2021", 1);

    EXPECT_TRUE(testProj.has_elements());
}

TEST(has_elements, has_projects) {
    project testProj;

    project *proj = new project();

    testProj.add_Project(proj);

    EXPECT_TRUE(testProj.has_elements());
}

TEST(convert_date, test_month) {
    Base b("Test base", "base for unit testing", "11/30/2021");
    
    EXPECT_EQ(b.get_date_obj().getDay(), 30);
}

TEST(convert_date, test_day) {
    Base b("Test base", "base for unit testing", "11/30/2021");

    EXPECT_EQ(b.get_date_obj().getMonth(), 11);
}

TEST(convert_date, test_year) {
    Base b("Test base", "base for unit testing", "11/30/2021");

    EXPECT_EQ(b.get_date_obj().getYear(), 2021);
}

TEST(convert_date, test_blank_date) {
    Base b;

    EXPECT_EQ(b.get_date_obj().getDay(), 0);
}



