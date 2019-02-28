#pragma once
#include <stdio.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_native_dialog.h"
#include <iostream>
#include <allegro5/allegro_image.h> // plik nag³ówkowy
#include "plansza.h"
#include <allegro5/allegro_primitives.h> 


using namespace std;

class ¯ó³w:public plansza
{
protected:
	int wysokosc;
	int szerokosc;
	ALLEGRO_BITMAP*zolw = NULL;
	int start_x, start_y;
	int prawo = 64;
	int lewo = 0;
	int dol = 0;
	int gora = 0;
	int czek = 0;
	
public:

	int alg1();
	int alg2();
	void move();
	¯ó³w(int start_x=1*64,int start_y=1*64,int wysokosc=64, int szerokosc=64);
	void draw();
	void creat();
	~¯ó³w();
};

