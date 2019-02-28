#include "tablicaWektorow.h"



TablicaWektorow::TablicaWektorow(int dl_) {						// tworzy Tablice o zadanej d³ugoœci i wype³nia wektorami (0,0)
	if (dl_) {
		w = new Wektor[dl_];
		dl = dl_;
		for (int i = 0; i < dl_; i++) {
			Wektor A(0,0);
			w[i] = A;
		}
	}
}

TablicaWektorow::TablicaWektorow(TablicaWektorow & w_) {					//inicjalizacja za pomoc¹ Tablicy w_
	dl = w_.dl;
	w = new Wektor[dl];
	for (int i = 0; i < dl; i++) {
		w[i] = w_.w[i];
	}
}

TablicaWektorow::TablicaWektorow(float * x_, float * y_, int dl_) {	// inicjalizacja tablicy wektorów tablicami x -ów i y -ów
	dl = dl_;
	w = new Wektor[dl];
	for (int i = 0; i < dl; i++) {
		Wektor A(x_[i], y_[i]);
		w[i] = A;
	}
}

TablicaWektorow::~TablicaWektorow() {
	delete[] w;
}

void TablicaWektorow::drukuj() {
	for (int i = 0; i < dl; i++) {
		w[i].drukuj();
	}
}