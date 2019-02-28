#pragma once
#pragma once
#include <iostream>

class Punkt {
protected:
	float x;
	float y;
public:
	Punkt(Punkt & p);
	Punkt(float x_ = 0, float y_ = 0);
	void dodaj(Punkt &p);	// dodaje do siebie wsp�rz�dne punktu p(dodawanie wektor�w w przestrzeni 2d)
	void dodaj(Punkt *p);
	bool porownaj(Punkt &p);
	bool porownaj(Punkt *p);
	void drukuj();			// drukuje swoje wsp�rz�dne
	Punkt operator += (Punkt & p);
	Punkt operator = (Punkt & p);
	bool operator == (Punkt & p);
	Punkt operator + (Punkt & p);
	friend std::ostream & operator<< (std::ostream & os, Punkt & p);
	float getX();
	float getY();
};
