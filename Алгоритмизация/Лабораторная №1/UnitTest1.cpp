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
			std::map<int, unsigned> dict = make_map(n);
			auto [result, execution_time] = measure_execution_time(search_map, n, dict);
			Assert::AreEqual(10, result);
		}

		TEST_METHOD(TestMethod2)
		{
			int n = 100;
			std::map<int, unsigned> dict = make_map(n);
			auto [result, execution_time] = measure_execution_time(search_map, n, dict);
			Assert::AreEqual(100, result);
		}

		TEST_METHOD(TestMethod3)
		{
			int n = 200;
			std::map<int, unsigned> dict = make_map(n);
			auto [result, execution_time] = measure_execution_time(search_map, n, dict);
			Assert::AreEqual(200, result);
		}

		TEST_METHOD(TestMethod4)
		{
			int n = 500;
			std::map<int, unsigned> dict = make_map(n);
			auto [result, execution_time] = measure_execution_time(search_map, n, dict);
			Assert::AreEqual(500, result);
		}

		TEST_METHOD(TestMethod5)
		{
			int n = 1000;
			std::map<int, unsigned> dict = make_map(n);
			auto [result, execution_time] = measure_execution_time(search_map, n, dict);
			Assert::AreEqual(1000, result);
		}

		TEST_METHOD(TestMethod6)
		{
			int n = 2000;
			std::map<int, unsigned> dict = make_map(n);
			auto [result, execution_time] = measure_execution_time(search_map, n, dict);
			Assert::AreEqual(2000, result);
		}

		TEST_METHOD(TestMethod7)
		{
			int n = 5000;
			std::map<int, unsigned> dict = make_map(n);
			auto [result, execution_time] = measure_execution_time(search_map, n, dict);
			Assert::AreEqual(5000, result);
		}

		TEST_METHOD(TestMethod8)
		{
			int n = 10000;
			std::map<int, unsigned> dict = make_map(n);
			auto [result, execution_time] = measure_execution_time(search_map, n, dict);
			Assert::AreEqual(10000, result);
		}

		TEST_METHOD(TestMethod9)
		{
			int n = 50000;
			std::map<int, unsigned> dict = make_map(n);
			auto [result, execution_time] = measure_execution_time(search_map, n, dict);
			Assert::AreEqual(50000, result);
		}

		TEST_METHOD(TestMethod10)
		{
			int n = 100000;
			std::map<int, unsigned> dict = make_map(n);
			auto [result, execution_time] = measure_execution_time(search_map, n, dict);
			Assert::AreEqual(100000, result);
		}

		TEST_METHOD(TestMethod11)
		{
			int n = 1000000;
			std::map<int, unsigned> dict = make_map(n);
			auto [result, execution_time] = measure_execution_time(search_map, n, dict);
			Assert::AreEqual(1000000, result);
		}

		TEST_METHOD(TestMethod12)
		{
			int n = 10000000;
			std::map<int, unsigned> dict = make_map(n);
			auto [result, execution_time] = measure_execution_time(search_map, n, dict);
			Assert::AreEqual(10000000, result);
		}

		TEST_METHOD(TestMethod13)
		{
			int n = 10000000;
			std::map<int, unsigned> dict = make_map(n);
			auto [result, execution_time] = measure_execution_time(search_map, n, dict);
			Assert::AreEqual(10000000, result);
		}
	};
}
