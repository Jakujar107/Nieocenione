#include "punkt.h"

Punkt::Punkt(Punkt & p) {
	x = p.x;
	y = p.y;
}

Punkt::Punkt(float x_, float y_) {
	x = x_;
	y = y_;
}

void Punkt::dodaj(Punkt &p) {
	x += p.x;
	y += p.y;
}

void Punkt::dodaj(Punkt *p) {
	x += p->x;
	y += p->y;
}

bool Punkt::porownaj(Punkt &p) {
	if (x == p.x && y == p.y) {
		return true;
	}
	else {
		return false;
	}
}

bool Punkt::porownaj(Punkt *p) {
	if (x == p->x && y == p->y) {
		return true;
	}
	else {
		return false;
	}
}

void Punkt::drukuj() {
	std::cout << "x = " << x << ", y = " << y << std::endl;
}

Punkt Punkt::operator += (Punkt & p) {
	x += p.x;
	y += p.y;
	return *this;
}

Punkt Punkt::operator = (Punkt & p) {
	x = p.x;
	y = p.y;
	return *this;
}

bool Punkt::operator == (Punkt & p) {
	if (x == p.x && y == p.y) {
		return true;
	}
	else {
		return false;
	}
}

Punkt Punkt::operator + (Punkt & p) {
	x += p.x;
	y += p.y;
	return  *this;
}

std::ostream & operator<< (std::ostream & os, Punkt & p) {
	os << "x = " << p.x << ", y = " << p.y << std::endl;
	return os;
}

float Punkt::getX() {
	return x;
}

float Punkt::getY() {
	return y;
}