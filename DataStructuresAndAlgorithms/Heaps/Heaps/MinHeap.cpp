#include "MinHeap.h"

Heaps::MinHeap::MinHeap() : V(1)
{
}

int Heaps::MinHeap::size()
{
	return V.size() - 1;
}
