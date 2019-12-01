// ******************************************************************************************************************
//  This file is part of InitApps.
//
//  InitApps - program that executes other programs.
//  Copyright(C)  2019  James LoForti
//  Contact Info: jamesloforti@gmail.com
//
//  InitApps is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.If not, see<https://www.gnu.org/licenses/>.
//									     ____.           .____             _____  _______   
//									    |    |           |    |    ____   /  |  | \   _  \  
//									    |    |   ______  |    |   /  _ \ /   |  |_/  /_\  \ 
//									/\__|    |  /_____/  |    |__(  <_> )    ^   /\  \_/   \
//									\________|           |_______ \____/\____   |  \_____  /
//									                             \/          |__|        \/ 
//
// ******************************************************************************************************************
//
#include "OutputConstants.h"
using namespace std;

OutputConstants::OutputConstants()
{

}

OutputConstants::~OutputConstants()
{

}

int OutputConstants::modulus(int in, int iMod)
{
	int iq = (in / iMod);
	return in - (iq * iMod);
}

char OutputConstants::getChar(int iGenerator, char cBase, int iRange)
{
	return (cBase + modulus(iGenerator, iRange));
}

void OutputConstants::drawMatrix()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 2);
	clock_t start;
	double duration = 0.0;

	HWND hwnd = GetConsoleWindow();
	start = clock();
	char caRow[80];
	int j = 7;
	int k = 2;
	int l = 5;
	int m = 1;

	while (duration < 10)
	{
		int i = 0;

		while (i < 80)
		{
			if (caRow[i] != ' ')
			{
				caRow[i] = getChar(j + i * i, 33, 30);

				if (((i * i + k) % 71) == 0)
					SetConsoleTextAttribute(hConsole, 7);
				else
					SetConsoleTextAttribute(hConsole, 2);
			}

			cout << caRow[i];
			++i;
			SetConsoleTextAttribute(hConsole, 2);
		}

		j = (j + 31);
		k = (k + 17);
		l = (l + 47);
		m = (m + 67);

		caRow[modulus(j, 80)] = '-';
		caRow[modulus(k, 80)] = ' ';
		caRow[modulus(l, 80)] = '-';
		caRow[modulus(m, 80)] = ' ';

		Sleep(10);

		SwitchToThisWindow(hwnd, true);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	} // end while
} // end function