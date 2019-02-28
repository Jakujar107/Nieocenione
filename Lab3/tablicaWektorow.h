#pragma once

#include "wektor.h"

class TablicaWektorow {
protected:
	int dl;			//d³ugoœæ tablicy
	Wektor * w;			//tablica
public:
	TablicaWektorow(int dl_ = 0); 						// tworzy Tablice o zadanej d³ugoœci i wype³nia wektorami (0,0)
	TablicaWektorow(TablicaWektorow & w_);				//inicjalizacja za pomoc¹ Tablicy w_
	TablicaWektorow(float *x_, float *y_, int dl_);		// inicjalizacja tablicy wektorów tablicami x -ów i y -ów

	~TablicaWektorow();

	void drukuj();
};