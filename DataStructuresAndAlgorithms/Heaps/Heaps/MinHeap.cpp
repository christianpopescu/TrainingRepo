#include "MinHeap.h"

Heaps::MinHeap::MinHeap() : V(1)
{
}

inline int Heaps::MinHeap::size() const
{
	return V.size() - 1;
}

int Heaps::MinHeap::parent(int i) const
{
	//if (i < 1 || i > size()) return -1; // error
	return i / 2;
}

int Heaps::MinHeap::left(int i) const
{
	int ret;
	if ( (ret = 2 * i) > size()) return 0;	// no left leaf
	return ret;

}

int Heaps::MinHeap::right(int i) const
{
	int ret;
	if ((ret = (2 * i + 1)) > size()) return 0; // no right leaf
	return ret;
}

void Heaps::MinHeap::Insert(int value)
{
	V.push_back(value);
	UpHeapBubbling(size());
}

void Heaps::MinHeap::RemoveTop()
{
	if (size() == 1) V.pop_back();
	else
	{
		std::swap(V[1], V[size()]);
		V.pop_back();
		DownHeapBubbling(1);
	}
}

int Heaps::MinHeap::Top() const
{
	return V[1];
}

int Heaps::MinHeap::operator[](int i) const
{
	return V[i];
}

void Heaps::MinHeap::UpHeapBubbling(int i)
{
	while (i > 1 && V[i] < V[parent(i)])
	{
		std::swap(V[i], V[parent(i)]);
		i = parent(i);
	}
}

void Heaps::MinHeap::DownHeapBubbling(int i)
{

	while (i <= parent(size()))
	{
		int l = left(i);
		int r = right(i);
		int small;
		if (l > 0 && V[i] > V[l])
			small = l;
		else
			small = i;
		if (r > 0 && V[small] > V[r]) small = r;
		if (small != i)
		{
			std::swap(V[small], V[i]);
			i = small;
		}
		else break;			// Down Heap Bubbling finished
	}
}
