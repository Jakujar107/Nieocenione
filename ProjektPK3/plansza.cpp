#include "plansza.h"
#include <cmath>
#include "¯ó³w.h"
 
using namespace std;

plansza::plansza()

{

}

bool plansza::check() {

	//sprawdzanie czy wszystkie elementu zosta³y dobrze zainicjalizowane 
	//timer
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return false;

	}

	//wyswietlacz
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return false;
	}

	//podloga
	if (!Background) {
		fprintf(stderr, "failed to create Background bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return false;
	}
	//sciana
	if (!Wall) {
		fprintf(stderr, "failed to create wall bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return false;
	}
	//kolejka wydarzen
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(Background);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return false;
	}
	return true;
}

void plansza::tworzmape() {
	int a; // zmienna która s³u¿y do wyboru algorytmu

	al_show_native_message_box(display, "wybor algorytmu", "wpisz w konsoli 1 lub 2", "wybierz algorytm", 0, 3); // okno które nakazuje nam wybraæ algorytm
	cin >> a;
	

	¯ó³w z1; //tworzenie obiektu ¿ó³w



	timer = al_create_timer(1.0 / FPS); // tworzenie timera
	display = al_create_display(SCREEN_W, SCREEN_H);// tworzenie wyswietlacza
	Background = al_create_bitmap(SIZE, SIZE); // tworzenie bitmapy podlogi
	Wall = al_create_bitmap(SIZE, SIZE); // przypisanie bitmapy œciany

	al_set_target_bitmap(Background); // zmiana kolory bitmap

	al_clear_to_color(al_map_rgb(0, 150, 0));

	z1.creat(); // tworzenie bitmapy ¿ó³wia

	al_set_target_bitmap(Wall);

	al_clear_to_color(al_map_rgb(0, 0, 255));
	// powrót na wyœwietlacz
	al_set_target_bitmap(al_get_backbuffer(display));
	// tworzenie kolejki wydarzeñ
	event_queue = al_create_event_queue();
	
	// rejestrowanie wydarzeñ
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();
	// wystartowanie timere czyli czêstotliwoœci odœwie¿ania
	al_start_timer(timer);

	// g³owna pêtla programu która jak zostanie przerwana to koñczy sie program

	while (1)
	{


		// przerywanie pêtli jak nie uda³o siê czegoœ zainicjalizowaæ
		if (check() == false) {
			break;
		}//jezeli nie udalo sie czegos stworzyc konczy program
		
		al_wait_for_event(event_queue, &ev);
		// wykonywanie algorytmów ¿ó³wia i warunek wygrania gry
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (a == 1) {
				z1.alg1();
				if (z1.alg1() == 1) {
					al_show_native_message_box(display, "koniec", "you won", "good job", 0, ALLEGRO_MESSAGEBOX_OK_CANCEL);
					break;
				}
			}
			if (a == 2) {
				z1.alg2();
				if (z1.alg2() == 1) {
					al_show_native_message_box(display, "koniec", "you won", "good job", 0, ALLEGRO_MESSAGEBOX_OK_CANCEL);
					break;
				}

			}

			
			
			redraw = true;
		}
		// gdy naciœniemy X na wyœwietlaczy koñczymy program
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		// gdy kolejka jest pusta nie nadrysowujemy bitmap
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));
			// tworzenie planszy na danych z tablicy
			int type;
			for (int y = 0; y < 14; y++) {
				for (int x = 0; x < 20; x++) {
					type = tab[y][x];
					if (type == 0) {
						al_draw_bitmap(Background, x * 64, y * 64, 0); // podloga
					}
					if (type == 2) {
						al_draw_bitmap(Wall, x * 64, y * 64, 0 ); //sciana
					}

				}
			}
			//rysowanie ¿ó³wia
			z1.draw();
		

			
			
		

			
			al_flip_display();
		}
	
	}// usuwanie wszystkiego z pamiêci
	al_destroy_bitmap(Background);
	al_destroy_bitmap(Wall);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
}

	

	


plansza::~plansza()
{

	


}
