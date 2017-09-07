#pragma once
#include <vector>
/**
 * \brief Min Heap (Min priority queue
 */
namespace Heaps{
	class MinHeap
	{
	public:
		MinHeap();
		int size();
	private:
		std::vector<int> V;			// structure to implement the heap


	};

}
