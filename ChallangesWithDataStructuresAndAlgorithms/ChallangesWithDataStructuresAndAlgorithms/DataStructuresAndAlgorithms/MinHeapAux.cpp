// Based on  MinHeapAux from Data Structures and Algorithms
// Use only one file to simple integrate with Hakerrank Challenges


#include <vector>
#include <memory>
	// ----------------------------------------------
	// Type definitions
	// -----------------------------------------------
	using heapIndex = int;    // index of heap ADT
	using mainIndex = int;    // index of main ADT
	template <class T, class Compare = std::less<T>>
	class MinHeapAux
	{
	public:
		MinHeapAux();
		MinHeapAux(T pMainArray[], int pLength, Compare less);
		int size() const;
		heapIndex parent(heapIndex ih) const;
		heapIndex left(heapIndex ih) const;
		heapIndex right(heapIndex ih) const;
		void Insert(mainIndex im);
		void RemoveTop();
		mainIndex Top() const;
		mainIndex operator[](heapIndex ih);
		void DecreseKey(mainIndex im );
	private:
		T* mainArray;			// pointer to main array
		Compare comp;		// pointer to compare function
		std::vector<mainIndex> V;    // structure to implement the heap
		std::vector<heapIndex> locator;  // locates heap index based on main ADT
		void UpHeapBubbling(heapIndex ih);
		void DownHeapBubbling(heapIndex ih);
	public:
		~MinHeapAux();
	};

	// ----------------------------------------------
	// Type implementation
	// -----------------------------------------------

	
	template <class T, class Compare>
MinHeapAux<T, Compare>::MinHeapAux(T pMainArray[], int pLength, Compare less) : V(1), locator(1)
{
	//mainArray = std::move(pMainArray);
	mainArray = pMainArray;
	comp = less;
	// Create Min Heap from array
	for (int i = 1; i<pLength; i++)
	{
		Insert(i);
	}
}

// index 0 not used 
template <class T, class Compare>
MinHeapAux<T, Compare>::MinHeapAux() : V(1), locator(1)
{
}

template <class T, class Compare>
int MinHeapAux<T, Compare>::size() const
{
	return V.size() - 1;
}

template <class T, class Compare>
heapIndex MinHeapAux<T, Compare>::parent(heapIndex ih) const
{
	return ih / 2;
}

template <class T, class Compare>
heapIndex MinHeapAux<T, Compare>::left(heapIndex ih) const
{
	int ret;
	if ((ret = 2 * ih) > size()) return 0;	// no left leaf
	return ret;
}

template <class T, class Compare>
heapIndex MinHeapAux<T, Compare>::right(heapIndex ih) const
{
	int ret;
	if ((ret = (2 * ih + 1)) > size()) return 0; // no right leaf
	return ret;
}
template <class T, class Compare>
void MinHeapAux<T, Compare>::Insert(mainIndex im)
{
	V.push_back(im);
	locator.push_back(im);
	UpHeapBubbling(size());
}

template <class T, class Compare>
void MinHeapAux<T, Compare>::RemoveTop()
{
	if (size() == 1) V.pop_back();
	else
	{
		std::swap(locator[V[1]], locator[V[size()]]);
		std::swap(V[1], V[size()]);
		V.pop_back();
//		locator.pop_back();
		DownHeapBubbling(1);
	}
}

template <class T, class Compare>
mainIndex MinHeapAux<T, Compare>::Top() const
{
	return V[1];
}

template <class T, class Compare>
mainIndex MinHeapAux<T, Compare>::operator[](heapIndex ih)
{
	return V[ih];
}

template <class T, class Compare>
void MinHeapAux<T, Compare>::DecreseKey(mainIndex im)
{
	UpHeapBubbling(locator[im]);
}

template <class T, class Compare>
void MinHeapAux<T, Compare>::UpHeapBubbling(heapIndex ih)
{
	while ((ih > 1) && (ih <= V.size()) && comp(mainArray[V[ih]] , mainArray[V[parent(ih)]]) )
	{
		std::swap(locator[V[ih]], locator[V[parent(ih)]]);
		std::swap(V[ih], V[parent(ih)]);
		ih = parent(ih);
	}
}

template <class T, class Compare>
void MinHeapAux<T, Compare>::DownHeapBubbling(heapIndex ih)
{
	while (ih <= parent(size()))
	{
		int l = left(ih);
		int r = right(ih);
		int small;
		if ((l > 0) && (l <= V.size()) && comp(mainArray[V[l]], mainArray[V[ih]]))
			small = l;
		else
			small = ih;
		if ((r > 0) && (r <= V.size()) && comp(mainArray[V[r]], mainArray[V[small]])) small = r;
		if (small != ih)
		{
			std::swap(locator[V[small]], locator[V[ih]]);
			std::swap(V[small], V[ih]);
			ih = small;
		}
		else break;			// Down Heap Bubbling finished
	}
}

template <class T, class Compare>
MinHeapAux<T, Compare>::~MinHeapAux()
{
}