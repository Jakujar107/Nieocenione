#include "plansza.h"
#include <cmath>
#include "¯ó³w.h"
 
using namespace std;

plansza::plansza()

{

}

bool plansza::check() {


	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return false;

	}


	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return false;
	}


	if (!Background) {
		fprintf(stderr, "failed to create Background bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return false;
	}

	if (!Wall) {
		fprintf(stderr, "failed to create wall bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return false;
	}
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
	


	¯ó³w z1;



	timer = al_create_timer(1.0 / FPS);
	display = al_create_display(SCREEN_W, SCREEN_H);
	Background = al_create_bitmap(SIZE, SIZE);
	Wall = al_create_bitmap(SIZE, SIZE);

	al_set_target_bitmap(Background);

	al_clear_to_color(al_map_rgb(0, 150, 0));

	z1.creat();

	al_set_target_bitmap(Wall);

	al_clear_to_color(al_map_rgb(0, 0, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();
	

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);



	while (1)
	{


		int time = 0;
		if (check() == false) {
			break;
		}//jezeli nie udalo sie czegos stworzyc konczy program
		
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			z1.alg1();
			if (z1.alg1() == 1) {
				al_show_native_message_box(display, "koniec", "you won", "good job", 0, ALLEGRO_MESSAGEBOX_OK_CANCEL);
				break;
			}
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			int type;
			for (int y = 0; y < 14; y++) {
				for (int x = 0; x < 20; x++) {
					type = tab[y][x];
					if (type == 0) {
						al_draw_bitmap(Background, x * 64, y * 64, 0); // podloga
					}
					if (type == 2) {
						al_draw_bitmap(Wall, x * 64, y * 64, 0 );
					}

				}
			}
			z1.draw();
			time++;

			
			
		

			
			al_flip_display();
		}
	
	}
	al_destroy_bitmap(Background);
	al_destroy_bitmap(Wall);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
}

	

	


plansza::~plansza()
{

	


}
