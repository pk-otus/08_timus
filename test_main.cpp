#include <fstream>
#include <functional>

#include <gtest/gtest.h>

#include "Tasks/current_task.h"

using timus_task = std::function<void(void)>;

const std::string strTestFolder =	std::string(TIMUS_TESTFILE_DIR) + 
									std::to_string(TIMUS_CURRENT_TASK) + '/';

std::string GetTestResult (size_t test_number, const timus_task& task_fun)
{
	std::string strInFile = strTestFolder + "in" + std::to_string(test_number) + ".txt";

	testing::internal::CaptureStdout();
	freopen(strInFile.c_str(), "r", stdin);

	task_fun(); // uses cin and cout

	std::string output = testing::internal::GetCapturedStdout();

	return output;
}

std::string GetControlResult(size_t test_number)
{
	std::string strOutFile = strTestFolder + "out" + std::to_string(test_number) + ".txt";

	std::ifstream t(strOutFile);
	std::string result((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());
	
	return result;
}

TEST(TimusTests, CurrentTask)
{
	int i = 0;
	do
	{
		++i;		
		auto control_result = GetControlResult(i);
		if (control_result.empty()) 
			break;
		ASSERT_EQ(control_result, GetTestResult(i, TIMUS_TASK_FUNCTION));
	} 
	while (true);
}
