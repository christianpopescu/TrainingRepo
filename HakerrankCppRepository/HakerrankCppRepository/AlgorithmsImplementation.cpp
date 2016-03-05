#include "stdafx.h"
#include "AlgorithmsImplementation.h"
#include <string>
#include <iostream>

AlgorithmsImplementation::AlgorithmsImplementation()
{
}

void AlgorithmsImplementation::AngryProfessorIostream()
{
	using namespace std;
	int t, n, k, a[1000], sum;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> k;
		sum = 0;
		for (auto j = 0; j < n; j++)
		{
			cin >> a[j];
			sum += (a[j] <= 0) ? 1 : 0; // count the number of of students arrived before start
		}
		cout << ((sum < k) ? "YES\n" : "NO\n");
	}
	

}

void AlgorithmsImplementation::TheGridSearch()
{
	using namespace std;
	struct TablePoint
	{
		int row;
		int column;
	};
	int NumberOfTestCases;
	cin >> NumberOfTestCases;
	TablePoint GLastPoint,PLastPoint;
	TablePoint CurrentPointer;
	TablePoint LastPointer;
	TablePoint ComparisonPointer;
	char G[1000][1000];
	char P[1000][1000];
	
	for (int i = 0; i < NumberOfTestCases; i++)
	{
		cin >> GLastPoint.row >> GLastPoint.column;
		//TODO: Read Array G
		for (int j = 0; j < GLastPoint.row - 1; j++)
			cin.getline(G[j], 1000);

		cin >> PLastPoint.row >> PLastPoint.column;
		// TODO : Read Array P
		for (int j = 0; j < PLastPoint.row - 1; j++)
			cin.getline(P[j], 1000);

		LastPointer.row = GLastPoint.row - PLastPoint.row + 1;
		LastPointer.column = GLastPoint.column - PLastPoint.column + 1;

	}

}


AlgorithmsImplementation::~AlgorithmsImplementation()
{
}
