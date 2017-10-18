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
		void Insert(int value);
		void RemoveTop();
		int Top() const;
		int operator[](int i) const;
	private:
		std::vector<int> V;			// structure to implement the heap
		void UpHeapBubbling(int i);
		void DownHeapBubbling(int i);

	};

}
