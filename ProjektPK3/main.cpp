#include <stdio.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_image.h> // plik nag��wkowy
#include <iostream>
#include "plansza.h"
#include "��w.h"
#include <allegro5/allegro_primitives.h> 


int main(int argc, char **argv) {
	//ustawianie czasu z systemu
	srand(time(NULL));
	//sprawdzanie czy biblioteka Allegro zosta�a dobrze zainicjalizowana
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");

	}
	//tworzy plansze i wykonuje na niej algorytmy, na planszy znajduj� si� g�owna p�tla programu
	plansza p1;
	p1.tworzmape();
	
	

	return 0;
}
