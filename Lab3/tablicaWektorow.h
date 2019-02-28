#pragma once

#include "wektor.h"

class TablicaWektorow {
protected:
	int dl;			//d�ugo�� tablicy
	Wektor * w;			//tablica
public:
	TablicaWektorow(int dl_ = 0); 						// tworzy Tablice o zadanej d�ugo�ci i wype�nia wektorami (0,0)
	TablicaWektorow(TablicaWektorow & w_);				//inicjalizacja za pomoc� Tablicy w_
	TablicaWektorow(float *x_, float *y_, int dl_);		// inicjalizacja tablicy wektor�w tablicami x -�w i y -�w

	~TablicaWektorow();

	void drukuj();
};