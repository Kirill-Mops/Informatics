#include "pch.h"
#include "CppUnitTest.h"
#include "../homework/homework.cpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::vector<int> vec1 = {2, 1 ,3};
			std::vector<int> exp1 = {1, 2, 3};
			std::vector<int> act1 = MergeSort(vec1);
			std::vector<int> vec2 = { 6, 8, 1, 2, 3 };
			std::vector<int> exp2 = { 1, 2, 3, 6, 8 };
			std::vector<int> act2 = MergeSort(vec2);
			std::vector<int> vec3 = { 4, 10, 8, 123 };
			std::vector<int> exp3 = { 4, 8, 10, 123 };
			std::vector<int> act3 = MergeSort(vec3);
			std::vector<int> vec4 = { 456, 23, 0, 7 };
			std::vector<int> exp4 = { 0, 7, 23, 456 };
			std::vector<int> act4 = MergeSort(vec4);
			std::vector<int> vec5 = { 90, 54, 85, 123 };
			std::vector<int> exp5 = { 54, 85, 90, 123 };
			std::vector<int> act5 = MergeSort(vec5);

			Assert::IsTrue(vec1 == exp1, L"Значения не совпали");
			Assert::IsTrue(vec2 == exp2, L"Значения не совпали");
			Assert::IsTrue(vec3 == exp3, L"Значения не совпали");
			Assert::IsTrue(vec4 == exp4, L"Значения не совпали");
			Assert::IsTrue(vec5 == exp5, L"Значения не совпали");
		}
		
		TEST_METHOD(TestMethod2)
		{
			std::vector<int> vec1 = { 2, 1 ,3 };
			std::vector<int> exp1 = { 1, 2, 3 };
			std::vector<int> act1 = RadixSort(vec1);
			std::vector<int> vec2 = { 6, 8, 1, 2, 3 };
			std::vector<int> exp2 = { 1, 2, 3, 6, 8 };
			std::vector<int> act2 = RadixSort(vec2);
			std::vector<int> vec3 = { 4, 10, 8, 123 };
			std::vector<int> exp3 = { 4, 8, 10, 123 };
			std::vector<int> act3 = RadixSort(vec3);
			std::vector<int> vec4 = { 456, 23, 0, 7 };
			std::vector<int> exp4 = { 0, 7, 23, 456 };
			std::vector<int> act4 = RadixSort(vec4);
			std::vector<int> vec5 = { 90, 54, 85, 123 };
			std::vector<int> exp5 = { 54, 85, 90, 123 };
			std::vector<int> act5 = RadixSort(vec5);

			Assert::IsTrue(vec1 == exp1, L"Значения не совпали");
			Assert::IsTrue(vec2 == exp2, L"Значения не совпали");
			Assert::IsTrue(vec3 == exp3, L"Значения не совпали");
			Assert::IsTrue(vec4 == exp4, L"Значения не совпали");
			Assert::IsTrue(vec5 == exp5, L"Значения не совпали");
		}

		TEST_METHOD(TestMethod3)
		{
			std::vector<int> vec1 = { 2, 1 ,3 };
			std::vector<int> exp1 = { 1, 2, 3 };
			std::vector<int> act1 = make_Quick_sort(vec1);
			std::vector<int> vec2 = { 6, 8, 1, 2, 3 };
			std::vector<int> exp2 = { 1, 2, 3, 6, 8 };
			std::vector<int> act2 = make_Quick_sort(vec2);
			std::vector<int> vec3 = { 4, 10, 8, 123 };
			std::vector<int> exp3 = { 4, 8, 10, 123 };
			std::vector<int> act3 = make_Quick_sort(vec3);
			std::vector<int> vec4 = { 456, 23, 0, 7 };
			std::vector<int> exp4 = { 0, 7, 23, 456 };
			std::vector<int> act4 = make_Quick_sort(vec4);
			std::vector<int> vec5 = { 90, 54, 85, 123 };
			std::vector<int> exp5 = { 54, 85, 90, 123 };
			std::vector<int> act5 = make_Quick_sort(vec5);

			Assert::IsTrue(vec1 == exp1, L"Значения не совпали");
			Assert::IsTrue(vec2 == exp2, L"Значения не совпали");
			Assert::IsTrue(vec3 == exp3, L"Значения не совпали");
			Assert::IsTrue(vec4 == exp4, L"Значения не совпали");
			Assert::IsTrue(vec5 == exp5, L"Значения не совпали");
		}
	};
}