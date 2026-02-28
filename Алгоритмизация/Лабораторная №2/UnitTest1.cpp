#include "pch.h"
#include "CppUnitTest.h"
#include "../homework/homework.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n = 10;
			double result1 = simpson_rule(function1, 5, 6, n);
			double result2 = simpson_rule(function2, 5, 6, n);
			double result = result1 - result2;
			Assert::AreEqual(115.333, result, 0.1, L"Значения не совпали");
		}

		TEST_METHOD(TestMethod2)
		{
			int n = 100;
			double result1 = simpson_rule(function1, 5, 6, n);
			double result2 = simpson_rule(function2, 5, 6, n);
			double result = result1 - result2;
			Assert::AreEqual(115.333, result, 0.1, L"Значения не совпали");
		}

		TEST_METHOD(TestMethod3)
		{
			int n = 1000;
			double result1 = simpson_rule(function1, 5, 6, n);
			double result2 = simpson_rule(function2, 5, 6, n);
			double result = result1 - result2;
			Assert::AreEqual(115.333, result, 0.1, L"Значения не совпали");
		}

		TEST_METHOD(TestMethod4)
		{
			int n = 10000;
			double result1 = simpson_rule(function1, 5, 6, n);
			double result2 = simpson_rule(function2, 5, 6, n);
			double result = result1 - result2;
			Assert::AreEqual(115.333, result, 0.1, L"Значения не совпали");
		}

		TEST_METHOD(TestMethod5)
		{
			int n = 100000;
			double result1 = simpson_rule(function1, 5, 6, n);
			double result2 = simpson_rule(function2, 5, 6, n);
			double result = result1 - result2;
			Assert::AreEqual(115.333, result, 0.1, L"Значения не совпали");
		}

	};
}
