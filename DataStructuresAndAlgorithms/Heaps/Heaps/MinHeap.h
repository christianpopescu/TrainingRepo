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
		int size() const;
		int parent(int i) const;
		int left(int i) const;
		int right(int i) const;
		void insert(int value);
		int operator[](int i) const;
	private:
		std::vector<int> V;			// structure to implement the heap


	};

}
