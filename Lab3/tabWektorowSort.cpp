#include "tabWektorowSort.h"

TabWektorowSort::TabWektorowSort(TablicaWektorow & w_) : TablicaWektorow(w_) {
	int zamiana;
	Wektor schowek;
	do
	{
		zamiana = 0;
		for (int i = 0; i<dl; i++)
		{
			if (w[i].getLength()>w[i + 1].getLength())
			{
				zamiana = zamiana + 1; 
				schowek = w[i];
				w[i] = w[i + 1];
				w[i + 1] = schowek;
			}
		}
	} while (zamiana != 0);
}

void TabWektorowSort::wstaw(Wektor & p) {
	int pozycja = 0;
	while (w[pozycja].getLength() < p.getLength() && pozycja != dl) {
		pozycja++;
	}
	Wektor * w_ = new Wektor[dl + 1];
	for (int i = 0; i < dl + 1; i++) {
		if (i < pozycja) {
			w_[i] = w[i];
		}
		else if (i == pozycja){
			w_[i] = p;
		}
		else {
			w_[i] = w[i - 1];
		}
	}
	delete[] w;

	dl++;
	w = w_;
}

TabWektorowSort TabWektorowSort::operator = (Wektor & p) {
	this->wstaw(p);
	return *this;
}