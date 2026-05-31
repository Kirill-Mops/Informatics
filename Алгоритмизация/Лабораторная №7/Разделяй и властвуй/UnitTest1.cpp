#include "pch.h"
#include "CppUnitTest.h"
#include "../homework/homework.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
		TEST_METHOD(Test1)
		{
			std::vector<int> nums = { 2, 5, 5, 5, 6, 6, 8, 9, 9, 9 };
			int target = 5;
			int exp = 1;
			int act = find(nums, target, true);
			Assert::AreEqual(exp, act);
		}

		TEST_METHOD(Tes2)
		{
			std::vector<int> nums = { 2, 5, 5, 5, 6, 6, 8, 9, 9, 9 };
			int target = 5;
			int exp = 3;
			int act = find(nums, target, false);
			Assert::AreEqual(exp, act);
		}

		TEST_METHOD(Test3)
		{
			std::vector<int> nums = { 2, 5, 5, 5, 6, 6, 8, 9, 9, 9 };
			int target = 4;
			int exp = -1;
			int act = find(nums, target, false);
			Assert::AreEqual(exp, act);
		}
	};
}