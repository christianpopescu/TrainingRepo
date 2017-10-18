#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Heaps\MinHeap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HeapsUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(MinHeapCreationTest)
		{
			Heaps::MinHeap mh{};
			// TODO: Your test code here
			Assert::AreEqual(mh.size(), 0);
						
		}
		TEST_METHOD(InsertOneNode)
		{
			Heaps::MinHeap mh{};
			mh.Insert(10);
			Assert::AreEqual(mh[1],10);
		}
		TEST_METHOD(SimpleUpBublle)
		{
			Heaps::MinHeap mh{};
			mh.Insert(10);
			mh.Insert(5);
			Assert::AreEqual(mh[1], 5);
		}

	};
}