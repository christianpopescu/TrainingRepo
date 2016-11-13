#include "stdafx.h"
#include "AlgorithmsImplementation.h"
#include <string>
#include <iostream>
#include <vector>

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

void AlgorithmsImplementation::AppleAndOrange()
{
	using namespace std;
	int s;
	int t;
	cin >> s >> t;
	int a;
	int b;
	cin >> a >> b;
	int m;
	int n;
	cin >> m >> n;
	vector<int> apple(m);
	int dAppleMin = s - a;
	int dAppleMax = t - a;
	int dOrangeMin = s - b;
	int dOrangeMax = t - b;
	int applesInTheHouse = 0;
	int orangesInTheHouse = 0;
	for (int apple_i = 0; apple_i < m; apple_i++) {
		cin >> apple[apple_i];
		if (apple[apple_i] >= dAppleMin && apple[apple_i] <= dAppleMax) applesInTheHouse++;
	}
	vector<int> orange(n);
	for (int orange_i = 0; orange_i < n; orange_i++) {
		cin >> orange[orange_i];
		if (orange[orange_i] >= dOrangeMin && orange[orange_i] <= dOrangeMax) orangesInTheHouse++;
	}
	cout << applesInTheHouse << endl;
	cout << orangesInTheHouse << endl;
}

void AlgorithmsImplementation::FlipMatrixWithOutput(int n, int(&matrix)[256][256])
{
	using namespace std;
	int max = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			// find max of the 4 positions
			for (int k = i, kk = 0; kk < 2; k = 2 * n - i - 1, kk++)
			{
				for (int l = j, ll=0; ll < 2; l = 2 * n - j - 1, ll++)
					if (k == i && l == j)
					{
						max = matrix[k][l];
					}
					else
						if (max < matrix[k][l]) max = matrix[k][l];
			}
			sum += max;
		}
	cout << sum << endl;
}

void AlgorithmsImplementation::FlippingTheMatrix()
{
	using namespace std;
	int q;
	cin >> q;
	int matrix[256][256];
	for (int i = 0; i < q; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j <= 2 * n - 1; j++)
			for (int k = 0; k <= 2 * n - 1; k++)
				cin >> matrix[j][k];
		FlipMatrixWithOutput(n, matrix);
	}
}

void AlgorithmsImplementation::insertionSort(int ar_size, int *  ar)
{
	using namespace std;

	for (int i = 1; i < ar_size; i++)
	{
		int elementToInsert = ar[i];
		int insertionIndex = i;
		for (int j = i-1; j >= 0; j--)
			if (elementToInsert < ar[j])
			{
				ar[j + 1] = ar[j];
				insertionIndex = j;
			}
			else 
			{
				break;
			}
		ar[insertionIndex] = elementToInsert;
		for (int k = 0; k < ar_size; k++)
			cout << ar[k] << " ";
		cout << endl;
	}
}

AlgorithmsImplementation::~AlgorithmsImplementation()
{
}
