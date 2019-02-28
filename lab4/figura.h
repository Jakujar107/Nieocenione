#pragma once
#include "szach.h"

class Figura
{
protected:
	Szachownica *s; //figura zna swoj� szachownice - ustawiane przez set
	int x, y; // po�o�enie na szachownicy ustawiane przez set 
	bool set(int x, int y, char z)//pomocnicza uzywana przez range i set w sekcji public 
								  //UWAGA:(friend nie jest dziedziczony)
	{
		if (s->wiz[x][y] == 'O') {
			s->wiz[x][y] = z;//sprawdzic czy pole nie jest zaj�te (zwracamy wtedy false)
			return true;
		}
		else {
			return false;
		}
	};
	bool set(int x, int y, Figura *f)// ustawia pole x,y tablicy sz na wska�nik do klasy dziedzicz�cej z klasy Figura (Wieza , Goniec)
	{
		s->sz[x][y] = f;//sprawdzic czy pole nie jest zaj�te (zwracamy wtedy false)
		return true;
	};
public:
	Figura() { s == NULL; };
	virtual bool set(Szachownica *s, int x_, int y_) = 0; //metoda ustawia figure na szachownicy
	// zwraca false gdy pole jest zaj�te
	// w tablicy wiz ustawia 'W' lub 'G' (dalsza cz�� zadania)
	// za pomoc� set(int x,int y,Figura *f) ustawia pole w tablicy sz.

	void remove()		//TODO: REDO THIS !!!!!!!!!!!!!!!!
	{
		//s->sz[x][y] = s = NULL;
		//s->wiz[x][y] = 'O';
		//s = NULL;// ustawia s na NULL - figura zdj�ta z szachownicy 
	};
	virtual void range() = 0;//pokazuje zasi�g bicia na szachownicy - operuje na tablicy wiz klasy Szachownica

};

class Wieza : public Figura
{
public:
	Wieza() :Figura() {};
	bool set(Szachownica *s_, int x_, int y_)
	{
		s = s_;
		Figura::set(x_, y_, 'W');
		// wywo�a� set(int x,int y,Figura *f) z odpowiednim parametrem
		return true;
	}
	void range(); //zdefiniowa� zasi�g bicia dla Wie�y
};

class Goniec : public Figura
{
	// uzupe�ni�
};
