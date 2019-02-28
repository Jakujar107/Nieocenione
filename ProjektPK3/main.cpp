#include <stdio.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_image.h> // plik nag³ówkowy
#include <iostream>
#include "plansza.h"
#include "¯ó³w.h"
#include <allegro5/allegro_primitives.h> 


int main(int argc, char **argv) {
	srand(time(NULL));
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");

	}
	plansza p1;
	p1.tworzmape();
	
	

	return 0;
}
