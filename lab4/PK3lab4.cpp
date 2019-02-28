// PK3lab4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "szach.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	Szachownica *s1 = new Szachownica();
	Szachownica *s2 = new Szachownica();
	Szachownica *s3 = new Szachownica();

	Goniec *g1 = new Goniec();
	Goniec *g2 = new Goniec();
	Wieza *w1 = new Wieza();
	Wieza *w2 = new Wieza();

	g1->set(s1, 2, 2);
	g2->set(s3, 2, 2);
	w1->set(s2, 5, 6);
	w2->set(s3, 5, 6);

	s1->showRange();
	cout << endl << endl;
	s2->showRange();
	cout << endl << endl;
	s3->showRange();

	system("pause");
}
