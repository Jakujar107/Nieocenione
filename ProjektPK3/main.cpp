#include <stdio.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_image.h> // plik nag³ówkowy
#include <iostream>
#include "plansza.h"
#include "¯ó³w.h"
#include <allegro5/allegro_primitives.h> 


int main(int argc, char **argv) {
	//ustawianie czasu z systemu
	srand(time(NULL));
	//sprawdzanie czy biblioteka Allegro zosta³a dobrze zainicjalizowana
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");

	}
	//tworzy plansze i wykonuje na niej algorytmy, na planszy znajdujê siê g³owna pêtla programu
	plansza p1;
	p1.tworzmape();
	
	

	return 0;
}
