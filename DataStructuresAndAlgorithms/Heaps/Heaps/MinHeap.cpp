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

void Heaps::MinHeap::insert(int value)
{
	V.push_back(value);
}

int Heaps::MinHeap::operator[](int i) const
{
	return V[i];
}
