#include "DynamicProgramming.h"


DynamicProgramming::DynamicProgramming()
{
}


DynamicProgramming::~DynamicProgramming()
{
}

void DynamicProgramming::LcsBuildAuxiliaryStructures(char(&b)[maxLength][maxLength], int(&c)[maxLength][maxLength],
	std::string X, std::string Y)
{
	for (int i = 0; i < maxLength; i++)
	{
		c[i][0] = 0;
		c[0][i] = 0;
	}
	int m = X.size();
	int n = Y.size();
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
			if (X[i] == X[j])
			{
				c[i][j] = c[i - 1][j - 1];
				b[i][j] = 'D';  // Diagonal
			}
			else if (c[i - 1][j] > c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 'U';  // Up
			}
			else
			{
				c[i][j] = c[i][j-1];
				b[i][j] = 'L';  // Left
			}


}

std::string DynamicProgramming::ComputeLcs(std::string X, std::string Y)
{
	std::string result;
	LcsBuildAuxiliaryStructures(b, c, X, Y);

	return result;
}
