#pragma once
#include "punkt.h"


class Wektor : public Punkt {
	float length;
	float direction;
public:
	Wektor(float x_ = 0, float y_ = 0);
	Wektor(Wektor & w);
	float getLength();
	float getDirection();
	Punkt getPoint();
	void dodaj(Wektor &p);
	void dodaj(Wektor *p);
	bool porownaj(Wektor &p);
	bool porownaj(Wektor *p);
	void drukuj();
	bool operator == (Wektor & p);
	Wektor operator = (Wektor & p);
};