#include "tabWektorowSort.h"


int main() {

	Wektor A(3, 4);
	std::cout << A.getDirection() << std::endl << A.getLength() << std::endl;

	Wektor B(A);
	std::cout << B.getDirection() << std::endl << B.getLength() << std::endl;

	//std::cout << A.getPoint();

	B.dodaj(A);
	std::cout << B.getDirection() << std::endl << B.getLength() << std::endl;
	std::cout << A.getDirection() << std::endl << A.getLength() << std::endl;

	std::cout << B.porownaj(A) << std::endl;
	std::cout << A.porownaj(A) << std::endl;

	B.drukuj();
	A.drukuj();

	std::cout << (A == B) << std::endl << (B == B);

	float a[10] = { 1, 3, 5, 8, 3, 6.5, 10.2, sqrt(5), 9, 21.46 };
	float b[10] = { 11, 31, 55, 82, 0.3, 6.7, 10.2235821, sqrt(50), 2.9, 5 };
	TablicaWektorow Tab(a, b, 10);
	Tab.drukuj();

	TabWektorowSort TabSort(Tab);
	TabSort.drukuj();

	TabSort.wstaw(A);
	TabSort.drukuj();

	TabSort = B;
	TabSort.drukuj();

	return 0;
}
