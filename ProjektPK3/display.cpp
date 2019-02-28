#include "display.h"
#include <stdio.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_native_dialog.h"
#include <iostream>

using namespace std;

okno::okno(int H, int W)
{
	display = NULL;
	display = al_create_display(W, H);
	if (!display) {
		cout << "failed to initialize display!\n" << endl;
	}

}


okno::~okno()
{
	al_destroy_display(display);
}
