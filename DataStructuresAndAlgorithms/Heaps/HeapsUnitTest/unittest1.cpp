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
			// Assert::AreEqual(1, 1);
		}

	};
}