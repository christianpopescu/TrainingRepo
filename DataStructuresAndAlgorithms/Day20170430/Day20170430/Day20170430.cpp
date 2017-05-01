// Day20170430.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct coord
{
public:
	coord(int pX, int pY)
	{
		x = pX;
		y = pY;
	}
	coord() {}
	int x;
	int y;
	/*	bool operator<(coord &c)
	{
	if (this->x < c.x) return true;
	else if (this->x > c.x) return false;
	else if (this->y < c.y) return true;
	}
	*/
	coord operator+(coord &vector)
	{
		this->x += vector.x;
		this->y += vector.y;
		return (*this);
	}
};

namespace std
{
	template<>
	struct less<coord>
	{
		bool operator()(const coord& k1, const coord& k2) const
		{
			if (k1.x < k2.x) return true;
			else if (k1.x > k2.x) return false;
			else if (k1.y < k2.y) return true;
			return false;
		}
	};
}
struct direction
{
public:
	direction(coord pCurrentPosition, coord pDeltaMove)
	{
		currentPosition = pCurrentPosition;
		deltaMove = pDeltaMove;
	}
	coord currentPosition;
	coord deltaMove;
};

void InitDirectionList(int pRow, int pColumn, list<direction> &pLD)
{
	{
		direction d(coord(pRow, pColumn), coord(1, 0));
		pLD.push_back(d);
	}
	{
		direction d(coord(pRow, pColumn), coord(1, 1));
		pLD.push_back(d);
	}
	{
		direction d(coord(pRow, pColumn), coord(1, -1));
		pLD.push_back(d);
	}
	{
		direction d(coord(pRow, pColumn), coord(0, 1));
		pLD.push_back(d);
	}
	{
		direction d(coord(pRow, pColumn), coord(0, -1));
		pLD.push_back(d);
	}
	{
		direction d(coord(pRow, pColumn), coord(-1, 0));
		pLD.push_back(d);
	}
	{
		direction d(coord(pRow, pColumn), coord(-1, 1));
		pLD.push_back(d);
	}
	{
		direction d(coord(pRow, pColumn), coord(-1, -1));
		pLD.push_back(d);
	}

}

int main() {
	map<coord, int> obstacles;
	list<direction>ld;
	int canAttack = 0;
	int n;
	int k;
	cin >> n >> k;
	int rQueen;
	int cQueen;
	cin >> rQueen >> cQueen;
	InitDirectionList(rQueen, cQueen, ld);
	for (int a0 = 0; a0 < k; a0++) {
		int rObstacle;
		int cObstacle;
		cin >> rObstacle >> cObstacle;
		obstacles[coord(rObstacle, cObstacle)] = 1;
	}
	for (int i = 0; i <= n + 1; i++)
	{
		obstacles[coord(0, i)] = 1;
		obstacles[coord(n+1, i)] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		obstacles[coord(i, 0)] = 1;
		obstacles[coord(i, n+1)] = 1;
	}
	cout << obstacles.size() << endl;
	while (!ld.empty())
	{
		list<direction>::iterator it;
		it = ld.begin();
		while (it != ld.end())
		{
			coord nextPosition = it->currentPosition + it->deltaMove;
			if (obstacles.find(nextPosition) != obstacles.end())
				it = ld.erase(it);
			else
			{
				canAttack++;
				++it;
			}
		}
	}
	cout << canAttack;
	return 0;
}
