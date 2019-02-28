#pragma once

#include "tablicaWektorow.h"

class TabWektorowSort : public TablicaWektorow {
public:
	TabWektorowSort(TablicaWektorow & w_);
	void wstaw(Wektor & p);
	TabWektorowSort operator = (Wektor & p);
};