#pragma once
#include <stdio.h>
#include <allegro5/allegro.h>                       
#include <allegro5/allegro_image.h> // plik nag��wkowy
#include "allegro5/allegro_native_dialog.h"
#include <iostream>
#include <cstdlib>


using namespace std;
class plansza
{
protected:
	const float FPS = 5;
	const int SCREEN_W = 1280;
	const int SCREEN_H = 896;
	const int SIZE = 64;//rozmiar jednej kratki
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *Background = NULL;
	ALLEGRO_EVENT ev;
	bool redraw = true;
	ALLEGRO_BITMAP *Wall = NULL;


	int tab[14][20] = {
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2 },
	{ 2,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,2,0,2 },
	{ 2,2,2,2,0,2,2,2,2,0,2,2,2,2,2,2,0,2,0,2 },
	{ 2,0,0,2,0,0,0,2,2,0,2,0,0,0,2,2,0,2,0,2 },
	{ 2,0,2,2,2,2,0,2,0,0,2,0,2,0,2,2,0,2,0,2 },
	{ 2,0,0,0,0,0,0,2,0,2,2,2,2,0,2,2,0,0,0,2 },
	{ 2,2,2,0,2,2,0,0,0,2,2,0,2,0,2,2,2,2,2,2 },
	{ 2,0,2,0,2,0,0,2,0,2,0,0,0,0,0,0,0,0,2,2 },
	{ 2,0,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,0,2,2 },
	{ 2,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,2,0,2,2 },
	{ 2,0,2,2,2,2,2,0,2,2,0,2,2,2,2,0,2,0,2,2 },
	{ 2,0,2,0,0,0,2,0,2,0,0,0,0,0,2,0,2,0,2,2 },
	{ 2,0,0,0,2,2,2,0,0,0,2,2,2,0,2,0,0,0,0,2 },
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
	};

public:
	 void tworzmape();
	 bool check();
	plansza();
	~plansza();
};

