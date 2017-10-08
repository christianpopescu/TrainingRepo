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

		TEST_METHOD(TwoNodesNoEdge)
		{
			// Arrange
			DisjointSetGraph dsg(2);

			// Assert
			Assert::AreEqual(2, dsg.GetNumberOfDisjointSet());

		}
		
		TEST_METHOD(TwoNodesOneEdge)
		{
			// Arrange
			DisjointSetGraph dsg(2);

			// Act 
			dsg.AddEdgeRecompute(0, 1);

			// Assert
			Assert::AreEqual(1, dsg.GetNumberOfDisjointSet());

		}

		TEST_METHOD(ZeroNodes)
		{
			// Arrange
			DisjointSetGraph dsg;

			// Assert
			Assert::AreEqual(0, dsg.GetNumberOfDisjointSet());

		}

		TEST_METHOD(TwoNodesOneEdgeCopyConstructor)
		{
			// Arrange
			DisjointSetGraph dsg(2);

			// Act 
			dsg.AddEdgeRecompute(0, 1);
			DisjointSetGraph dsgc(dsg);

			// Assert
			Assert::AreEqual(1, dsgc.GetNumberOfDisjointSet());

		}

		TEST_METHOD(FourNodesTwoEdges)
		{
			// Arrange
			DisjointSetGraph dsg(4);

			// Act 
			dsg.AddEdgeRecompute(0, 1);
			dsg.AddEdgeRecompute(1, 2);
			dsg.AddEdgeRecompute(0, 2);

			// Assert
			Assert::AreEqual(2, dsg.GetNumberOfDisjointSet());

		}

	};
}