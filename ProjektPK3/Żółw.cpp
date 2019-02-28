#include "¯ó³w.h"
#include "allegro5/allegro_native_dialog.h"

using namespace std;


¯ó³w::¯ó³w(int start_x, int start_y,int wysokosc,int szerokosc)
{
	this->start_x = start_x;
	this->start_y = start_y;

	this->wysokosc = wysokosc;
	this->szerokosc = szerokosc;
}

void ¯ó³w::creat() {
	zolw = al_create_bitmap(wysokosc, szerokosc);
	if (!zolw) {
		cout << "nie stworzono postaci";
		system("pause");
	}
	al_set_target_bitmap(zolw);

	al_clear_to_color(al_map_rgb(70, 20, 40));
}

void ¯ó³w::draw() {
	
	al_draw_bitmap(zolw, start_x, start_y,0);

}
int ¯ó³w::alg1() {
	

		int y = (start_y) / 64; //dzielimy przez 64 zeby zgadzalo sie z polem w tablicy
		int x = (start_x) / 64;
		
		if (tab[y-1][x] == 0 && tab[y][x+1] == 0 && czek == 0 || tab[y+1][x] == 0 && tab[y][x+1] == 0 && czek == 0 || tab[y+1][x] == 0 && tab[y][x-1] == 0 && czek == 0 || tab[y-1][x] == 0 && tab[y][x-1] == 0&&czek==0) {
			int ran;


			if (tab[y -1][x] == 0 && tab[y][x+1 ] == 0 && tab[y +1][x] == 2 && tab[y][x-1 ] == 2) {
				
				if (dol==64) {
					prawo = 64;
					lewo = 0;
					dol = 0;
					gora = 0;
				}
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
int ¯ó³w::alg2() {


	int y = (start_y) / 64; //dzielimy przez 64 zeby zgadzalo sie z polem w tablicy
	int x = (start_x) / 64;
	int p, l, g, d;

	p = tab[y][x + 1];
	l = tab[y][x - 1];
	g = tab[y - 1][x];
	d = tab[y + 1][x];


					if (tab[y - 1][x] != 2 && tab[y][x + 1] != 2 && czek == 0 || tab[y + 1][x] != 2 && tab[y][x + 1] != 2 && czek == 0 || tab[y + 1][x] != 2 && tab[y][x - 1] != 2 && czek == 0 || tab[y - 1][x] != 2 && tab[y][x - 1] != 2 && czek == 0) {
						int ran;


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
						if (tab[y][x - 1] != 2 && tab[y + 1][x] != 2 && tab[y - 1][x] != 2 && tab[y][x + 1] == 2) {
							if (l==0||g==0||p==0||d==0) {
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

						czek = 0;
						if (start_x == 64 * 18 && start_y == 0) {

							return 1;

						}
					}
				


	
return 0;
}
¯ó³w::~¯ó³w()
{
	al_destroy_bitmap(zolw);
}
