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
			int exp = 2;
			int act = base(2);
			Assert::AreEqual(exp, act);
		}

		TEST_METHOD(Tes2)
		{
			int exp = 5;
			int act = base(3);
			Assert::AreEqual(exp, act);
		}

		TEST_METHOD(Test3)
		{
			int exp = 14;
			int act = base(4);
			Assert::AreEqual(exp, act);
		}
	};
}