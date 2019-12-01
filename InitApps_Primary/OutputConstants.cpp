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