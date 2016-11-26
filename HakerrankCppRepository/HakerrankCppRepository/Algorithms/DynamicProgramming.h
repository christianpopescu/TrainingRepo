#include "stdafx.h"
#pragma once
#include <string>
class DynamicProgramming
{
public:
	DynamicProgramming();
	~DynamicProgramming();
	static const int maxLength = 1000;
	int c[maxLength][maxLength];
	char b[maxLength][maxLength];
	void LcsBuildAuxiliaryStructures(char (&b)[maxLength][maxLength], int (&c)[maxLength][maxLength],
		std::string X, std::string Y);
	std::string ComputeLcs(std::string X, std::string Y);
};


