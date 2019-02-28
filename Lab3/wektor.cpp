#include "wektor.h"

Wektor::Wektor(float x_, float y_) : Punkt(x_, y_) {
	length = sqrt(x_*x_ + y_ * y_);
	direction = atan(y_ / x_);
}

Wektor::Wektor(Wektor & w) : Punkt(w.getX(), w.getY()) {
	length = w.length;
	direction = w.direction;
}

float Wektor::getLength() {
	return length;
}

float Wektor::getDirection() {
	return direction;
}

Punkt Wektor::getPoint() {
	Punkt a(this->getX(), this->getY());
	return a;
}

void Wektor::dodaj(Wektor &p) {
	x += p.getX();
	y += p.getY();
	length = sqrt(x*x + y * y);
	direction = atan(y / x);
}

void Wektor::dodaj(Wektor *p) {
	x += p->getX();
	y += p->getY();
	length = sqrt(x*x + y * y);
	direction = atan(y / x);
}

bool Wektor::porownaj(Wektor &p) {
	return (x == p.getX() && y == p.getY());
}

bool Wektor::porownaj(Wektor *p) {
	return (x == p->getX() && y == p->getY());
}

void Wektor::drukuj() {
	std::cout << "x = " << x << ", y = " << y << ", length = " << length << ", direction = " << direction << std::endl;
}

bool Wektor::operator == (Wektor & p) {
	return (x == p.getX() && y == p.getY());
}

Wektor Wektor::operator = (Wektor & p) {
	x = p.x;
	y = p.y;
	length = p.length;
	direction = p.direction;
	return *this;
}