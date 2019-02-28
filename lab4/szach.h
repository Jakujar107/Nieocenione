#pragma once
#include <iostream>

using namespace std;

class Szachownica
{
	friend class Figura;
	friend class Goniec;
	friend class Wieza;
protected:
	Figura *sz[8][8];  // tablica kontrolna zawieraj¹ca wska¿niki do ustawionych figur
					   // NULL w przypadku gdy pole jest puste;
	char wiz[8][8];  // tablica do wizualizacji : 'O' pole puste 'X' pole bite , 'G'- polo¿enie goñca,
				     // 'W' - po³o¿enie wie¿y; zapisywane przez metodê range klasy Figura
public:
	Szachownica()// tworzy pust¹ szachownicê: pola w tablicy sz ustawione na NULL , w tablicy wiz na 'O' 
	{
		clear();
	}
	void showRange(); // metoda wywo³uje na wszystkich polach tablicy sz (ró¿nych od NULL) metodê wirtualn¹ range 
	void display(); // wyœwietla szachownnice (tablica wiz)
	void clear(); // tworzy pust¹ szachownice, wywo³uje metode remove na wszystkich polach tablicy sz (ró¿nych od NULL)
				  // UWAGA usuniêcie figury nie oznacza usuniêcie z pamiêci - nie wywo³ujemy delete

};

class Figura
{
protected:
	Szachownica *s; //figura zna swoj¹ szachownice - ustawiane przez set
	int x, y; // po³o¿enie na szachownicy ustawiane przez set 
	bool set(int x, int y, char z)//pomocnicza uzywana przez range i set w sekcji public 
								  //UWAGA:(friend nie jest dziedziczony)
	{
		if (s->wiz[x][y] == 'O') {
			s->wiz[x][y] = z;//sprawdzic czy pole nie jest zajête (zwracamy wtedy false)
			return true;
		}
		else {
			return false;
		}
	};
	bool set(int x, int y, Figura *f)// ustawia pole x,y tablicy sz na wskaŸnik do klasy dziedzicz¹cej z klasy Figura (Wieza , Goniec)
	{
		if (s->sz[x][y] == NULL) {
			this->x = x;
			this->y = y;
			s->sz[x][y] = f;
			return true;
		}
		else {
			return false;
		}
	};
public:
	Figura() { s == NULL; };
	virtual bool set(Szachownica *s, int x_, int y_) = 0;
	
	// metoda ustawia figure na szachownicy
	// zwraca false gdy pole jest zajête
	// w tablicy wiz ustawia 'W' lub 'G' (dalsza czêœæ zadania)
	// za pomoc¹ set(int x,int y,Figura *f) ustawia pole w tablicy sz.

	void remove()
	{
		s->sz[x][y] = NULL;
		s->wiz[x][y] = 'O';
		s = NULL;// ustawia s na NULL - figura zdjêta z szachownicy 
	};
	virtual void range() = 0;//pokazuje zasiêg bicia na szachownicy - operuje na tablicy wiz klasy Szachownica

};

class Wieza : public Figura
{
public:
	Wieza() :Figura() {};
	bool set(Szachownica *s_, int x_, int y_)
	{
		s = s_;
		Figura::set(x_, y_, 'W');
		Figura::set(x_, y_, this);
		return true;
	}
	void range() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (s->wiz[i][j] == 'O' && (i == this->x || j == this->y)) {
					s->wiz[i][j] = 'X';
				}
			}
		}
	}
};

class Goniec : public Figura
{
public:
	Goniec() :Figura() {};
	bool set(Szachownica *s_, int x_, int y_)
	{
		s = s_;
		Figura::set(x_, y_, 'G');
		Figura::set(x_, y_, this);
		return true;
	}
	void range() {
		for (int i = x, j = y; i < 8, j < 8; i++, j++) {
			if (s->wiz[i][j] == 'O') {
				s->wiz[i][j] = 'X';
			}
		}
		for (int i = x, j = y; i >= 0, j < 8; i--, j++) {
			if (s->wiz[i][j] == 'O') {
				s->wiz[i][j] = 'X';
			}
		}
		for (int i = x, j = y; i < 8, j >= 0; i++, j--) {
			if (s->wiz[i][j] == 'O') {
				s->wiz[i][j] = 'X';
			}
		}
		for (int i = x, j = y; i >= 0, j >= 0; i--, j--) {
			if (s->wiz[i][j] == 'O') {
				s->wiz[i][j] = 'X';
			}
		}
	}
};
