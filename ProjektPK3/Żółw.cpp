#include "��w.h"
#include "allegro5/allegro_native_dialog.h"

using namespace std;

//kontruktor kt�ry ustawia ��wia na starcie i przypisuje mi rozmiar
��w::��w(int start_x, int start_y,int wysokosc,int szerokosc)
{
	this->start_x = start_x;
	this->start_y = start_y;

	this->wysokosc = wysokosc;
	this->szerokosc = szerokosc;
}
// funkcja tworzenia bitmapy ��wia jako burgundowy kwadrat
void ��w::creat() {
	zolw = al_create_bitmap(wysokosc, szerokosc);//ustawia bitmape na ��wia wielkosci ��wia
	if (!zolw) { // zatrzymuje program jak nie uda si� stworzy� bitmpay
		cout << "nie stworzono postaci";
		system("pause");
	}
	al_set_target_bitmap(zolw);

	al_clear_to_color(al_map_rgb(70, 20, 40)); //ustawia kolor ��wia
}

void ��w::draw() {// funkcja rysuj�ca ��wia w miejscu w kt�rym si� znaiduj� 
	
	al_draw_bitmap(zolw, start_x, start_y,0);

}
int ��w::alg1() { // pierwszy alogrytm kt�ry losowo szuka wyj�cia z labiryntu
	

		int y = (start_y) / 64; //dzielimy przez 64 zeby zgadzalo sie z polem w tablicy
		int x = (start_x) / 64;
		// warunek kt�ry sprawdza czy jeste�my na skrzy�owaniu dr�g, albo na zakr�cie
		if (tab[y-1][x] == 0 && tab[y][x+1] == 0 && czek == 0 || tab[y+1][x] == 0 && tab[y][x+1] == 0 && czek == 0 || tab[y+1][x] == 0 && tab[y][x-1] == 0 && czek == 0 || tab[y-1][x] == 0 && tab[y][x-1] == 0&&czek==0) {
			int ran; // zmienna kt�ra b�dzie losowana

			//co robi� przy r�nych przypadkach zakr�tu
			if (tab[y -1][x] == 0 && tab[y][x+1 ] == 0 && tab[y +1][x] == 2 && tab[y][x-1 ] == 2) {
				// je�eli ��w szed� w d� to teraz p�jdzie w prawo
				if (dol==64) {
					prawo = 64;
					lewo = 0;
					dol = 0;
					gora = 0;
				}
				//je�eli ��w szed� w lewo to teraz p�jdzie w g�re
				if (lewo==64) {
					prawo = 0;
					lewo = 0;
					dol = 0;
					gora = 64;
				}
			}
			if (tab[y+1][x] == 0 && tab[y][x+1] == 0 && tab[y-1][x] == 2 && tab[y][x-1] == 2) {
				if (lewo==64) {
					prawo = 0;
					lewo = 0;
					dol = 64;
					gora = 0;
				}
				if (gora==64) {
					prawo = 64;
					lewo = 0;
					dol = 0;
					gora = 0;
				}
			}
			if (tab[y][x-1] == 0 && tab[y+1][x] == 0 && tab[y-1][x] == 2 && tab[y][x+1] == 2) {
				if (gora==64) {
					prawo = 0;
					lewo = 64;
					dol = 0;
					gora = 0;
				}
				if (prawo==64) {
					prawo = 0;
					lewo = 0;
					dol = 64;
					gora = 0;
				}
			}
			if (tab[y-1][x] == 0 && tab[y][x-1] == 0 && tab[y+1][x] == 2 && tab[y][x+1] == 2) {
				if (prawo==64) {
					prawo = 0;
					lewo = 0;
					dol = 0;
					gora = 64;
				}
				if (dol==64) {
					prawo = 0;
					lewo = 64;
					dol = 0;
					gora = 0;
				}
			}
			// jak ma zachowa� si� ��w jak jest na skrzy�owaniu z 3 �cie�kami, czyli dochodzi do skrzy�owania i losuj� w kt�r� p�j�� teraz strone

			if (tab[y][x-1] == 0 && tab[y+1][x] == 0 && tab[y-1][x] == 0 && tab[y][x+1] == 2) {
				ran = (std::rand() % 3);
				if (ran == 0) {
					prawo = 0;
					lewo = 64;
					dol = 0;
					gora = 0;
				}
				if (ran == 1) {
					prawo = 0;
					lewo = 0;
					dol = 64;
					gora = 0;
				}
				if (ran == 2) {
					prawo = 0;
					lewo = 0;
					dol = 0;
					gora = 64;
				}
			}
			if (tab[y+1][x] == 0 && tab[y][x-1] == 0 && tab[y][x+1] == 0 && tab[y-1][x] == 2) {
				ran = (std::rand() % 3);
				if (ran == 0) {
					prawo = 64;
					lewo = 0;
					dol = 0;
					gora = 0;
				}
				if (ran == 1) {
					prawo = 0;
					lewo = 64;
					dol = 0;
					gora = 0;
				}
				if (ran == 2) {
					prawo = 0;
					lewo = 0;
					dol = 64;
					gora = 0;
				}
			}
			if (tab[y+1][x] == 0 && tab[y][x+1] == 0 && tab[y-1][x] == 0 && tab[y][x-1] == 2) {
				ran = (std::rand() % 3);
				if (ran == 0) {
					prawo = 64;
					lewo = 0;
					dol = 0;
					gora = 0;
				}
				if (ran == 1) {
					prawo = 0;
					lewo = 0;
					dol = 64;
					gora = 0;
				}
				if (ran == 2) {
					prawo = 0;
					lewo = 0;
					dol = 0;
					gora = 64;
				}
			}
			if (tab[y][x+1] == 0 && tab[y-1][x] == 0 && tab[y][x-1] == 0 && tab[y+1][x] == 2) {
				ran = (std::rand() % 3);
				if (ran == 0) {
					prawo = 64;
					lewo = 0;
					dol = 0;
					gora = 0;
				}
				if (ran == 1) {
					prawo = 0;
					lewo = 64;
					dol = 0;
					gora = 0;
				}
				if (ran == 2) {
					prawo = 0;
					lewo = 0;
					dol = 0;
					gora = 64;
				}
			}
			//zachowanie ��wia gdy jest skrzy�owanie z 4 drogami
			if (tab[y+1][x] == 0 && tab[y-1][x] == 0 && tab[y][x+1] == 0 && tab[y][x-1] == 0) {
				ran = (std::rand() % 4);
				if (ran == 0) {
					prawo = 64;
					lewo = 0;
					dol = 0;
					gora = 0;
				}
				if (ran == 1) {
					prawo = 0;
					lewo = 64;
					dol = 0;
					gora = 0;
				}
				if (ran == 2) {
					prawo = 0;
					lewo = 0;
					dol = 64;
					gora = 0;
				}
				if (ran == 3) {
					prawo = 0;
					lewo = 0;
					dol = 0;
					gora = 64;
				}
			}

			
			 czek = 1;
		}
		else {
		//warunki kiedy ��w ma zawr�ci�, czyli zawraca jak sko�czy si� �cie�ka
		if (tab[y][x + 1] == 2 && tab[y + 1][x] == 2 && tab[y][x - 1] == 2) {

			prawo = 0;
			lewo = 0;
			dol = 0;
			gora = 64;


		}
		if (tab[y + 1][x] == 2 && tab[y - 1][x] == 2 && tab[y][x - 1] == 2) {

			prawo = 64;
			lewo = 0;
			dol = 0;
			gora = 0;


		}
		if (tab[y][x - 1] == 2 && tab[y - 1][x] == 2 && tab[y][x + 1] == 2) {

			prawo = 0;
			lewo = 0;
			dol = 64;
			gora = 0;


		}
		if (tab[y - 1][x] == 2 && tab[y + 1][x] == 2 && tab[y][x + 1] == 2) {

			prawo = 0;
			lewo = 64;
			dol = 0;
			gora = 0;


		}
			// wszystkie za�o�enia kt�re musz� zosta� spe�nione, �eby mo�na by�o ruszy� z�wiem.
		//oraz ograniczenie ��wia kraw�dzi� planszy
			if (start_y >= 64.0 && tab[y][x] == 0) {
				start_y -= gora;
			}
			

			if (start_y <= SCREEN_H - 2 * SIZE - 64.0 && tab[y + 1][x] == 0) {
				start_y += dol;
			}
			

			if (start_x > 64.0  && tab[y][x] == 0) {
				start_x -= lewo;
			}
			

			if (start_x <= SCREEN_W - 2 * SIZE - 64.0 && tab[y][x + 1] == 0) {
				start_x += prawo;
			}
			
			czek = 0;
			if (start_x==64*18 && start_y==0) {
				
				return 1;

			}
		}
		
	

}
//drugi algorytm, kt�ry wybiera z priorytetem �ci�ke na kt�rej jeszcze go nie by�o.
int ��w::alg2() { 


	int y = (start_y) / 64; //dzielimy przez 64 zeby zgadzalo sie z polem w tablicy
	int x = (start_x) / 64;
	int p, l, g, d;

	p = tab[y][x + 1]; // zmienne kt�re reprezentuj� klocki pod, nad, z lewej i prawej strony akutalnej pozycji ��wia, nie zastosowa�em ich we wszystkich przypadkach.
	l = tab[y][x - 1];
	g = tab[y - 1][x];
	d = tab[y + 1][x];

	// warunek kt�ry sprawdza czy jeste�my na skrzy�owaniu dr�g, albo na zakr�cie

					if (tab[y - 1][x] != 2 && tab[y][x + 1] != 2 && czek == 0 || tab[y + 1][x] != 2 && tab[y][x + 1] != 2 && czek == 0 || tab[y + 1][x] != 2 && tab[y][x - 1] != 2 && czek == 0 || tab[y - 1][x] != 2 && tab[y][x - 1] != 2 && czek == 0) {
						int ran, ran2; //zmienne losowe

						//zachowanie ��wia na zakr�tach
						if (tab[y - 1][x] != 2 && tab[y][x + 1] != 2 && tab[y + 1][x] == 2 && tab[y][x - 1] == 2) {

							if (dol == 64) {
								prawo = 64;
								lewo = 0;
								dol = 0;
								gora = 0;
							}
							if (lewo == 64) {
								prawo = 0;
								lewo = 0;
								dol = 0;
								gora = 64;
							}
						}
						if (tab[y + 1][x] != 2 && tab[y][x + 1] != 2 && tab[y - 1][x] == 2 && tab[y][x - 1] == 2) {
							if (lewo == 64) {
								prawo = 0;
								lewo = 0;
								dol = 64;
								gora = 0;
							}
							if (gora == 64) {
								prawo = 64;
								lewo = 0;
								dol = 0;
								gora = 0;
							}
						}
						if (tab[y][x - 1] != 2 && tab[y + 1][x] != 2 && tab[y - 1][x] == 2 && tab[y][x + 1] == 2) {
							if (gora == 64) {
								prawo = 0;
								lewo = 64;
								dol = 0;
								gora = 0;
							}
							if (prawo == 64) {
								prawo = 0;
								lewo = 0;
								dol = 64;
								gora = 0;
							}
						}
						if (tab[y - 1][x] != 2 && tab[y][x - 1] != 2 && tab[y + 1][x] == 2 && tab[y][x + 1] == 2) {
							if (prawo == 64) {
								prawo = 0;
								lewo = 0;
								dol = 0;
								gora = 64;
							}
							if (dol == 64) {
								prawo = 0;
								lewo = 64;
								dol = 0;
								gora = 0;
							}
						}
						// jak ma zachowa� si� na skrzy�owaniach na kt�rych jeszcze go nie by�o.
						if (tab[y][x - 1] != 2 && tab[y + 1][x] != 2 && tab[y - 1][x] != 2 && tab[y][x + 1] == 2) {
							//je�eli nie by� w jakim� kierunku to losuje pomi�dzy tymi kierunkami gdzie ma i��
							if (l==0||g==0||p==0||d==0) {

								ran2 = (std::rand() % 4);
								if (ran2 = 0 && l == 0) {
									prawo = 0;
									lewo = 64;
									dol = 0;
									gora = 0;
								}
								else {
									if (ran2 = 0 && g == 0) {
										prawo = 0;
										lewo = 0;
										dol = 0;
										gora = 64;
									}
									else {
										if (ran2 = 0 && p == 0) {
											prawo = 64;
											lewo = 0;
											dol = 0;
											gora = 0;
										}
										else {
											if (ran2 = 0 && d == 0) {
												prawo = 0;
												lewo = 0;
												dol = 64;
												gora = 0;
											}
										}
									}
								}
								if (ran2 = 1 && g == 0) {
									prawo = 0;
									lewo = 0;
									dol = 0;
									gora = 64;
								}
								else {
									if (ran2 = 1 && l == 0) {
										prawo = 0;
										lewo = 64;
										dol = 0;
										gora = 0;
									}
									else {
										if (ran2 = 1 && p == 0) {
											prawo = 64;
											lewo = 0;
											dol = 0;
											gora = 0;
										}
										else {
											if (ran2 = 1 && d == 0) {
												prawo = 0;
												lewo = 0;
												dol = 64;
												gora = 0;
											}
										}
									}
								}
								if (ran2 = 2 && p == 0) {
									prawo = 64;
									lewo = 0;
									dol = 0;
									gora = 0;
								}
								else {
									if (ran2 = 2 && g == 0) {
										prawo = 0;
										lewo = 0;
										dol = 0;
										gora = 64;
									}
									else {
										if (ran2 = 2 && l == 0) {
											prawo = 0;
											lewo = 64;
											dol = 0;
											gora = 0;
										}
										else {
											if (ran2 = 2 && d == 0) {
												prawo = 0;
												lewo = 0;
												dol = 64;
												gora = 0;
											}
										}
									}
								}
								if (ran2 = 3 && d == 0) {
									prawo = 0;
									lewo = 0;
									dol = 64;
									gora = 0;
								}
								else {
									if (ran2 = 3 && g == 0) {
										prawo = 0;
										lewo = 0;
										dol = 0;
										gora = 64;
									}
									else {
										if (ran2 = 3 && p == 0) {
											prawo = 64;
											lewo = 0;
											dol = 0;
											gora = 0;
										}
										else {
											if (ran2 = 3 && l == 0) {
												prawo = 0;
												lewo = 64;
												dol = 0;
												gora = 0;
											}
										}
									}
								}

							}
							else {
								ran = (std::rand() % 3);
								if (ran == 0) {
									prawo = 0;
									lewo = 64;
									dol = 0;
									gora = 0;
								}
								if (ran == 1) {
									prawo = 0;
									lewo = 0;
									dol = 64;
									gora = 0;
								}
								if (ran == 2) {
									prawo = 0;
									lewo = 0;
									dol = 0;
									gora = 64;
								}
							}
						}
						if (tab[y + 1][x] != 2 && tab[y][x - 1] != 2 && tab[y][x + 1] != 2 && tab[y - 1][x] == 2) {
							if (l == 0 || g == 0 || p == 0 || d == 0) {
								ran = (std::rand() % 4);
								if (ran = 0 && l == 0) {
									prawo = 0;
									lewo = 64;
									dol = 0;
									gora = 0;
								}
								else {
									if (ran = 0 && g == 0) {
										prawo = 0;
										lewo = 0;
										dol = 0;
										gora = 64;
									}
									else {
										if (ran = 0 && p == 0) {
											prawo = 64;
											lewo = 0;
											dol = 0;
											gora = 0;
										}
										else {
											if (ran = 0 && d == 0) {
												prawo = 0;
												lewo = 0;
												dol = 64;
												gora = 0;
											}
										}
									}
								}
								if (ran = 1 && g == 0) {
									prawo = 0;
									lewo = 0;
									dol = 0;
									gora = 64;
								}
								else {
									if (ran = 1 && l == 0) {
										prawo = 0;
										lewo = 64;
										dol = 0;
										gora = 0;
									}
									else {
										if (ran = 1 && p == 0) {
											prawo = 64;
											lewo = 0;
											dol = 0;
											gora = 0;
										}
										else {
											if (ran = 1 && d == 0) {
												prawo = 0;
												lewo = 0;
												dol = 64;
												gora = 0;
											}
										}
									}
								}
								if (ran = 2 && p == 0) {
									prawo = 64;
									lewo = 0;
									dol = 0;
									gora = 0;
								}
								else {
									if (ran = 2 && g == 0) {
										prawo = 0;
										lewo = 0;
										dol = 0;
										gora = 64;
									}
									else {
										if (ran = 2 && l == 0) {
											prawo = 0;
											lewo = 64;
											dol = 0;
											gora = 0;
										}
										else {
											if (ran = 2 && d == 0) {
												prawo = 0;
												lewo = 0;
												dol = 64;
												gora = 0;
											}
										}
									}
								}
								if (ran = 3 && d == 0) {
									prawo = 0;
									lewo = 0;
									dol = 64;
									gora = 0;
								}
								else {
									if (ran = 3 && g == 0) {
										prawo = 0;
										lewo = 0;
										dol = 0;
										gora = 64;
									}
									else {
										if (ran = 3 && p == 0) {
											prawo = 64;
											lewo = 0;
											dol = 0;
											gora = 0;
										}
										else {
											if (ran = 3 && l == 0) {
												prawo = 0;
												lewo = 64;
												dol = 0;
												gora = 0;
											}
										}
									}
								}

							}
						else {
							ran = (std::rand() % 3);
							if (ran == 0) {
								prawo = 64;
								lewo = 0;
								dol = 0;
								gora = 0;
							}
							if (ran == 1) {
								prawo = 0;
								lewo = 64;
								dol = 0;
								gora = 0;
							}
							if (ran == 2) {
								prawo = 0;
								lewo = 0;
								dol = 64;
								gora = 0;
							}
						}
						}
						if (tab[y + 1][x] != 2 && tab[y][x + 1] != 2 && tab[y - 1][x] != 2 && tab[y][x - 1] == 2) {
							if (l == 0 || g == 0 || p == 0 || d == 0) {
								ran = (std::rand() % 4);
								if (ran = 0 && l == 0) {
									prawo = 0;
									lewo = 64;
									dol = 0;
									gora = 0;
								}
								else {
									if (ran = 0 && g == 0) {
										prawo = 0;
										lewo = 0;
										dol = 0;
										gora = 64;
									}
									else {
										if (ran = 0 && p == 0) {
											prawo = 64;
											lewo = 0;
											dol = 0;
											gora = 0;
										}
										else {
											if (ran = 0 && d == 0) {
												prawo = 0;
												lewo = 0;
												dol = 64;
												gora = 0;
											}
										}
									}
								}
								if (ran = 1 && g == 0) {
									prawo = 0;
									lewo = 0;
									dol = 0;
									gora = 64;
								}
								else {
									if (ran = 1 && l == 0) {
										prawo = 0;
										lewo = 64;
										dol = 0;
										gora = 0;
									}
									else {
										if (ran = 1 && p == 0) {
											prawo = 64;
											lewo = 0;
											dol = 0;
											gora = 0;
										}
										else {
											if (ran = 1 && d == 0) {
												prawo = 0;
												lewo = 0;
												dol = 64;
												gora = 0;
											}
										}
									}
								}
								if (ran = 2 && p == 0) {
									prawo = 64;
									lewo = 0;
									dol = 0;
									gora = 0;
								}
								else {
									if (ran = 2 && g == 0) {
										prawo = 0;
										lewo = 0;
										dol = 0;
										gora = 64;
									}
									else {
										if (ran = 2 && l == 0) {
											prawo = 0;
											lewo = 64;
											dol = 0;
											gora = 0;
										}
										else {
											if (ran = 2 && d == 0) {
												prawo = 0;
												lewo = 0;
												dol = 64;
												gora = 0;
											}
										}
									}
								}
								if (ran = 3 && d == 0) {
									prawo = 0;
									lewo = 0;
									dol = 64;
									gora = 0;
								}
								else {
									if (ran = 3 && g == 0) {
										prawo = 0;
										lewo = 0;
										dol = 0;
										gora = 64;
									}
									else {
										if (ran = 3 && p == 0) {
											prawo = 64;
											lewo = 0;
											dol = 0;
											gora = 0;
										}
										else {
											if (ran = 3 && l == 0) {
												prawo = 0;
												lewo = 64;
												dol = 0;
												gora = 0;
											}
										}
									}
								}

							}
							else {
								ran = (std::rand() % 3);
								if (ran == 0) {
									prawo = 64;
									lewo = 0;
									dol = 0;
									gora = 0;
								}
								if (ran == 1) {
									prawo = 0;
									lewo = 0;
									dol = 64;
									gora = 0;
								}
								if (ran == 2) {
									prawo = 0;
									lewo = 0;
									dol = 0;
									gora = 64;
								}
							}
						}
						if (tab[y][x + 1] != 2 && tab[y - 1][x] != 2 && tab[y][x - 1] != 2 && tab[y + 1][x] == 2) {
							if (l == 0 || g == 0 || p == 0 || d == 0) {
								ran = (std::rand() % 4);
								if (ran = 0 && l == 0) {
									prawo = 0;
									lewo = 64;
									dol = 0;
									gora = 0;
								}
								else {
									if (ran = 0 && g == 0) {
										prawo = 0;
										lewo = 0;
										dol = 0;
										gora = 64;
									}
									else {
										if (ran = 0 && p == 0) {
											prawo = 64;
											lewo = 0;
											dol = 0;
											gora = 0;
										}
										else {
											if (ran = 0 && d == 0) {
												prawo = 0;
												lewo = 0;
												dol = 64;
												gora = 0;
											}
										}
									}
								}
								if (ran = 1 && g == 0) {
									prawo = 0;
									lewo = 0;
									dol = 0;
									gora = 64;
								}
								else {
									if (ran = 1 && l == 0) {
										prawo = 0;
										lewo = 64;
										dol = 0;
										gora = 0;
									}
									else {
										if (ran = 1 && p == 0) {
											prawo = 64;
											lewo = 0;
											dol = 0;
											gora = 0;
										}
										else {
											if (ran = 1 && d == 0) {
												prawo = 0;
												lewo = 0;
												dol = 64;
												gora = 0;
											}
										}
									}
								}
								if (ran = 2 && p == 0) {
									prawo = 64;
									lewo = 0;
									dol = 0;
									gora = 0;
								}
								else {
									if (ran = 2 && g == 0) {
										prawo = 0;
										lewo = 0;
										dol = 0;
										gora = 64;
									}
									else {
										if (ran = 2 && l == 0) {
											prawo = 0;
											lewo = 64;
											dol = 0;
											gora = 0;
										}
										else {
											if (ran = 2 && d == 0) {
												prawo = 0;
												lewo = 0;
												dol = 64;
												gora = 0;
											}
										}
									}
								}
								if (ran = 3 && d == 0) {
									prawo = 0;
									lewo = 0;
									dol = 64;
									gora = 0;
								}
								else {
									if (ran = 3 && g == 0) {
										prawo = 0;
										lewo = 0;
										dol = 0;
										gora = 64;
									}
									else {
										if (ran = 3 && p == 0) {
											prawo = 64;
											lewo = 0;
											dol = 0;
											gora = 0;
										}
										else {
											if (ran = 3 && l == 0) {
												prawo = 0;
												lewo = 64;
												dol = 0;
												gora = 0;
											}
										}
									}
								}
								
							}
							else {
								ran = (std::rand() % 3);
								if (ran == 0) {
									prawo = 64;
									lewo = 0;
									dol = 0;
									gora = 0;
								}
								if (ran == 1) {
									prawo = 0;
									lewo = 64;
									dol = 0;
									gora = 0;
								}
								if (ran == 2) {
									prawo = 0;
									lewo = 0;
									dol = 0;
									gora = 64;
								}
							}
						}
						if (tab[y + 1][x] != 2 && tab[y - 1][x] != 2 && tab[y][x + 1] != 2 && tab[y][x - 1] != 2) {
							ran = (std::rand() % 4);
							if (ran == 0) {
								prawo = 64;
								lewo = 0;
								dol = 0;
								gora = 0;
							}
							if (ran == 1) {
								prawo = 0;
								lewo = 64;
								dol = 0;
								gora = 0;
							}
							if (ran == 2) {
								prawo = 0;
								lewo = 0;
								dol = 64;
								gora = 0;
							}
							if (ran == 3) {
								prawo = 0;
								lewo = 0;
								dol = 0;
								gora = 64;
							}
						}


						czek = 1;
					}
					else {
					//zachowanie ��wia w �lepej uliczce 
						if (tab[y][x + 1] == 2 && tab[y + 1][x] == 2 && tab[y][x - 1] == 2) {

							prawo = 0;
							lewo = 0;
							dol = 0;
							gora = 64;


						}
						if (tab[y + 1][x] == 2 && tab[y - 1][x] == 2 && tab[y][x - 1] == 2) {

							prawo = 64;
							lewo = 0;
							dol = 0;
							gora = 0;


						}
						if (tab[y][x - 1] == 2 && tab[y - 1][x] == 2 && tab[y][x + 1] == 2) {

							prawo = 0;
							lewo = 0;
							dol = 64;
							gora = 0;


						}
						if (tab[y - 1][x] == 2 && tab[y + 1][x] == 2 && tab[y][x + 1] == 2) {

							prawo = 0;
							lewo = 64;
							dol = 0;
							gora = 0;


						}
						// wszystkie za�o�enia kt�re musz� zosta� spe�nione, �eby mo�na by�o ruszy� z�wiem.
						if (start_y >= 64.0 && tab[y][x] != 2) {

							tab[start_y / 64][start_x / 64] = 1;


							start_y -= gora;
						}


						if (start_y <= SCREEN_H - 2 * SIZE - 64.0 && tab[y + 1][x] != 2) {

							tab[start_y / 64][start_x / 64] = 1;

							start_y += dol;
						}


						if (start_x > 64.0  && tab[y][x] != 2) {
							tab[start_y / 64][start_x / 64] = 1;

							start_x -= lewo;
						}


						if (start_x <= SCREEN_W - 2 * SIZE - 64.0 && tab[y][x + 1] != 2) {

							tab[start_y / 64][start_x / 64] = 1;

							start_x += prawo;
						}
						//ustawia mo�liwo�� wej�cia do p�tli ze skrzy�owaniami
						czek = 0;
						if (start_x == 64 * 18 && start_y == 0) {

							return 1;

						}
					}
				


	
return 0;
}
��w::~��w()
{
	//destruckja bitmapy
	al_destroy_bitmap(zolw);
}
