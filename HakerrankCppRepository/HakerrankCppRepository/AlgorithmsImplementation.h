#pragma once
#include <string>
#include <vector>
#include <utility>
class AlgorithmsImplementation
{
public:
	AlgorithmsImplementation();
	~AlgorithmsImplementation();
	void static AngryProfessorIostream();
	void static TheGridSearch();
	void static AppleAndOrange();
	void static FlipMatrixWithOutput(int n, int (&matrix)[256][256]);
	void static FlippingTheMatrix();
	void static insertionSort(int ar_size, int *  ar);
	void static MaximumSubarraySum();
	void static MaximumSubarraySumReadAll();
	void static CircularArrayRotation();
	void static RepeatedString();
	void static StrangeCounter();
	void static CavityMap();
	bool static inline TestPalindrome(const std::string &s);
	
	void static PalindromeIndex();
	void static MissingNumbers();
	void static Pairs();
	void static BeautifulBinaryString();
	void static AbsoluteElementSums();   // not transmited as false algorithm
	bool static Compare(std::pair<int, int> p1, std::pair<int, int> p2);
	void static JimAndTheOthers();
};

