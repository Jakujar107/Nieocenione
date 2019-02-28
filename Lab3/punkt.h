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
	void dodaj(Punkt &p);	// dodaje do siebie wspó³rzêdne punktu p(dodawanie wektorów w przestrzeni 2d)
	void dodaj(Punkt *p);
	bool porownaj(Punkt &p);
	bool porownaj(Punkt *p);
	void drukuj();			// drukuje swoje wspó³rzêdne
	Punkt operator += (Punkt & p);
	Punkt operator = (Punkt & p);
	bool operator == (Punkt & p);
	Punkt operator + (Punkt & p);
	friend std::ostream & operator<< (std::ostream & os, Punkt & p);
	float getX();
	float getY();
};
