#include "stdafx.h"
#include "ProjectEuler.h"


ProjectEuler::ProjectEuler()
{
}


ProjectEuler::~ProjectEuler()
{
}

void ProjectEuler::Problem001()
{
	using namespace std;
	long t;
	cin >> t;
	vector<long> numbers(t);
	for (int a0 = 0; a0 < t; a0++) {
		
		cin >> numbers[a0];
	}

	for (int a0 = 0; a0 < t; a0++) 
	{
		long n3 = (numbers[a0] - 1) / 3;
		long n5 = (numbers[a0] - 1) / 5;
		long n15 = (numbers[a0] - 1) / 15;

		cout << 3 * n3*(n3 + 1) / 2 + 5 * n5*(n5 + 1) / 2 - 15 * n15*(n15 + 1) / 2 << endl;

		
	}

}
