#include "¯ó³w.h"
#include "allegro5/allegro_native_dialog.h"

using namespace std;

//kontruktor który ustawia ¿ó³wia na starcie i przypisuje mi rozmiar
¯ó³w::¯ó³w(int start_x, int start_y,int wysokosc,int szerokosc)
{
	this->start_x = start_x;
	this->start_y = start_y;

	this->wysokosc = wysokosc;
	this->szerokosc = szerokosc;
}
// funkcja tworzenia bitmapy ¿ó³wia jako burgundowy kwadrat
void ¯ó³w::creat() {
	zolw = al_create_bitmap(wysokosc, szerokosc);//ustawia bitmape na ¿ó³wia wielkosci ¿ó³wia
	if (!zolw) { // zatrzymuje program jak nie uda siê stworzyæ bitmpay
		cout << "nie stworzono postaci";
		system("pause");
	}
	al_set_target_bitmap(zolw);

	al_clear_to_color(al_map_rgb(70, 20, 40)); //ustawia kolor ¿ó³wia
}

void ¯ó³w::draw() {// funkcja rysuj¹ca ¿ó³wia w miejscu w którym siê znaidujê 
	
	al_draw_bitmap(zolw, start_x, start_y,0);

}
int ¯ó³w::alg1() { // pierwszy alogrytm który losowo szuka wyjœcia z labiryntu
	

		int y = (start_y) / 64; //dzielimy przez 64 zeby zgadzalo sie z polem w tablicy
		int x = (start_x) / 64;
		// warunek który sprawdza czy jesteœmy na skrzy¿owaniu dróg, albo na zakrêcie
		if (tab[y-1][x] == 0 && tab[y][x+1] == 0 && czek == 0 || tab[y+1][x] == 0 && tab[y][x+1] == 0 && czek == 0 || tab[y+1][x] == 0 && tab[y][x-1] == 0 && czek == 0 || tab[y-1][x] == 0 && tab[y][x-1] == 0&&czek==0) {
			int ran; // zmienna która bêdzie losowana

			//co robiæ przy ró¿nych przypadkach zakrêtu
			if (tab[y -1][x] == 0 && tab[y][x+1 ] == 0 && tab[y +1][x] == 2 && tab[y][x-1 ] == 2) {
				// je¿eli ¿ó³w szed³ w dó³ to teraz pójdzie w prawo
				if (dol==64) {
					prawo = 64;
					lewo = 0;
					dol = 0;
					gora = 0;
				}
				//je¿eli ¿ó³w szed³ w lewo to teraz pójdzie w góre
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
			// jak ma zachowaæ siê ¿ó³w jak jest na skrzy¿owaniu z 3 œcie¿kami, czyli dochodzi do skrzy¿owania i losujê w któr¹ pójœæ teraz strone

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
			//zachowanie ¿ó³wia gdy jest skrzy¿owanie z 4 drogami
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
		//warunki kiedy ¿ó³w ma zawróciæ, czyli zawraca jak skoñczy siê œcie¿ka
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
			// wszystkie za³o¿enia które musz¹ zostaæ spe³nione, ¿eby mo¿na by³o ruszyæ zó³wiem.
		//oraz ograniczenie ¿ó³wia krawêdzi¹ planszy
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
//drugi algorytm, który wybiera z priorytetem œciê¿ke na której jeszcze go nie by³o.
int ¯ó³w::alg2() { 


	int y = (start_y) / 64; //dzielimy przez 64 zeby zgadzalo sie z polem w tablicy
	int x = (start_x) / 64;
	int p, l, g, d;

	p = tab[y][x + 1]; // zmienne które reprezentuj¹ klocki pod, nad, z lewej i prawej strony akutalnej pozycji ¿ó³wia, nie zastosowa³em ich we wszystkich przypadkach.
	l = tab[y][x - 1];
	g = tab[y - 1][x];
	d = tab[y + 1][x];

	// warunek który sprawdza czy jesteœmy na skrzy¿owaniu dróg, albo na zakrêcie

					if (tab[y - 1][x] != 2 && tab[y][x + 1] != 2 && czek == 0 || tab[y + 1][x] != 2 && tab[y][x + 1] != 2 && czek == 0 || tab[y + 1][x] != 2 && tab[y][x - 1] != 2 && czek == 0 || tab[y - 1][x] != 2 && tab[y][x - 1] != 2 && czek == 0) {
						int ran, ran2; //zmienne losowe

						//zachowanie ¿ó³wia na zakrêtach
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
						// jak ma zachowaæ siê na skrzy¿owaniach na których jeszcze go nie by³o.
						if (tab[y][x - 1] != 2 && tab[y + 1][x] != 2 && tab[y - 1][x] != 2 && tab[y][x + 1] == 2) {
							//je¿eli nie by³ w jakimœ kierunku to losuje pomiêdzy tymi kierunkami gdzie ma iœæ
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
					//zachowanie ¿ó³wia w œlepej uliczce 
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
						// wszystkie za³o¿enia które musz¹ zostaæ spe³nione, ¿eby mo¿na by³o ruszyæ zó³wiem.
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
						//ustawia mo¿liwoœæ wejœcia do pêtli ze skrzy¿owaniami
						czek = 0;
						if (start_x == 64 * 18 && start_y == 0) {

							return 1;

						}
					}
				


	
return 0;
}
¯ó³w::~¯ó³w()
{
	//destruckja bitmapy
	al_destroy_bitmap(zolw);
}
