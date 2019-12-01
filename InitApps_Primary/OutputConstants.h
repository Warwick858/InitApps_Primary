#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

class OutputConstants
{
protected:

public:

	OutputConstants();

	~OutputConstants();

	void drawMatrix();

	int modulus(int in, int iMod);

	char getChar(int iGenerator, char cBase, int iRange);
};