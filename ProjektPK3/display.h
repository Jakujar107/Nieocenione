#pragma once
#include <stdio.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_native_dialog.h"
#include <iostream>

using namespace std;

class okno
{
	int H;
	int W;
	

public:
	ALLEGRO_DISPLAY *display;
	okno(int H, int W);
	~okno();
};

