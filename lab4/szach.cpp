#include "pch.h"
#include "szach.h"

void Szachownica::clear()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			wiz[i][j] = 'O';
			sz[i][j] = NULL;
		};
};
void Szachownica::display()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << wiz[i][j]<<" ";
		cout << endl;
	}
}

void Szachownica::showRange()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (sz[i][j] != NULL)
				sz[i][j]->range();
	display();
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (wiz[i][j] = 'X')
				wiz[i][j] = 'O';
}