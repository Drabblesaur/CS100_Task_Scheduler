#include "gtest/gtest.h"

#include "task_test.cpp"
//#include "project_test.cpp"
//#include "date_test.cpp"



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
