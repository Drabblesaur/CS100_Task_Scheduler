CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD_11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
	testing/unit_test.cpp
)

ADD_EXECUTABLE(task_scheduler
	main.cpp
	Base.cpp
	ProjectFactory.cpp
	FileIO.cpp
	SubtaskFactory.cpp
	TaskFactory.cpp
	project.cpp
	subtask.cpp
	task.cpp
)




TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
