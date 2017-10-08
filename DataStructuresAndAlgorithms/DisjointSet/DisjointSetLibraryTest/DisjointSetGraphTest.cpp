#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\DisjointSetLibrary\DisjointSetGraph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DisjointSetLibraryTest
{		
	TEST_CLASS(DisjointSetLibraryTest)
	{
	public:
		
		TEST_METHOD(OneNode)
		{
			// TODO: Your test code here
			// Arrange
			DisjointSetGraph dsg(1);
			// Act
			
			// Assert
			Assert::AreEqual(1, dsg.GetNumberOfDisjointSet());
		}

	};
}