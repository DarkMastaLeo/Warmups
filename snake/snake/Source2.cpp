//#include <stdio.h>
//#include <allegro5/allegro.h>
//#include <iostream>
//#include <allegro5\allegro_audio.h>
//#include <allegro5\allegro_acodec.h>
//#include <allegro5\allegro_primitives.h>
//#include <allegro5\allegro_image.h>
//#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_ttf.h>
//#include<vector>
//#include <cstdlib>
//#include<Windows.h>
//#include<time.h>
//
//using namespace std;
//
//const int LEFT = 1;
//const int UP = 2;
//const int RIGHT = 3;
//const int DOWN = 4;
//const double CLOCK = .1;
//const int SNEKSIZE = 40;
//
//
//
//int main() {
//	//    allegro variables////////////////////////////////////////////////////////////////////////////////////////////
//	ALLEGRO_DISPLAY *display = NULL;
//	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
//	ALLEGRO_TIMER *timer = NULL;
//	ALLEGRO_BITMAP *snek = NULL;
//	ALLEGRO_SAMPLE *sample = NULL;
//	ALLEGRO_SAMPLE_INSTANCE *instance1 = NULL;
//
//
//
//	//initalize game variables
//	int food_x = 5;
//	int food_y = 5;
//	int score = 0;
//	bool key[4] = { false, false, false, false };
//	bool redraw = true;
//	bool doexit = false;
//	int tailX[100], tailY[100];
//	int lives = 10;
//	int tailLength = 0;
//	int x = 10;
//	int y = 10;
//	bool gotfood = false;
//	int prevX = tailX[0];
//	int prevY = tailY[0];
//	int prev2X, prev2Y;
//	tailX[0] = x;
//	tailY[0] = y;
//
//	//initalize allegro and helper libraries/////////////////////////////////////////////////////////////////////////////////////////
//	al_init();
//	al_install_keyboard();
//	al_install_audio();
//	al_init_acodec_addon();
//	al_init_primitives_addon();
//	al_init_image_addon();
//	al_init_font_addon();
//	al_init_ttf_addon();
//
//
//
//
//
//	//create game items/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	timer = al_create_timer(CLOCK);
//	display = al_create_display(800, 800);
//
//
//	int grid[20][20];
//	for (int i = 0; i < 20; i++) 
//		for (int j = 0; j < 20; j++) 
//			grid[i][j] = 0;
//		
//	grid[food_x][food_y] = 2;
//
//	srand(time(NULL));
//
//
//
//
//
//	al_set_target_bitmap(al_get_backbuffer(display));
//
//	event_queue = al_create_event_queue();
//
//	al_reserve_samples(10);
//
//	//sample = al_load_sample("chirp.ogg");
//
//	ALLEGRO_FONT *font = al_load_ttf_font("hearts.ttf", 28, 0);
//
//	//instance1 = al_create_sample_instance(sample);
//
//
//	//al_set_sample_instance_playmode(instance1, ALLEGRO_PLAYMODE_LOOP);
//
//	//al_attach_sample_instance_to_mixer(instance1, al_get_default_mixer());
//
//
//	//set up event queue items for event queue to catch////////////////////////////////////////////////////////////////
//	al_register_event_source(event_queue, al_get_display_event_source(display));
//
//	al_register_event_source(event_queue, al_get_timer_event_source(timer));
//
//	al_register_event_source(event_queue, al_get_keyboard_event_source());
//
//
//	//start the game//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	al_clear_to_color(al_map_rgb(0, 0, 0));
//
//	al_flip_display();
//
//	al_start_timer(timer);
//
//	//al_play_sample_instance(instance1);
//
//
//	while (true) { //game loop
//		ALLEGRO_EVENT ev;
//		al_wait_for_event(event_queue, &ev);
//
//		//draw map to console
//		//for (int i = 0; i < 20; i++){
//		//for (int j = 0; j < 20; j++) 
//		//cout << grid[i][j];
//		//cout << endl;
//		//}
//
//		if (ev.type == ALLEGRO_EVENT_TIMER) {
//
//			//wipe map
//			for (int i = 0; i < 20; i++)
//				for (int j = 0; j < 20; j++) {
//					if (grid[i][j] == 1)
//						grid[i][j] = 0;
//				}
//
//			//draw the snek tail
//			for (int i = 1; i < tailLength; i++)
//			{
//				prev2X = tailX[i];
//				prev2Y = tailY[i];
//				tailX[i] = prevX;
//				tailY[i] = prevY;
//				prevX = prev2X;
//				prevY = prev2Y;
//			}
//
//			//check if food has been reached, set new food is true
//			if (gotfood == true) {
//				//erase old food
//				grid[food_x][food_y] = 0;
//
//				//generate new point for food
//				food_x = rand() % 20;
//				food_y = rand() % 20;
//				grid[food_x][food_y] = 2;
//				tailLength += 2;
//				gotfood = false;
//			}
//
//			//pacman movement
//			//pacman's directions: 1 is right, 2 is down, 3 is left, 4 is up.
//			if (key[0]) {
//
//				y -= 1;
//			}
//			if (key[1]) {
//
//				y += 1;
//			}
//			if (key[2]) {
//
//				x -= 1;
//			}
//			if (key[3]) {
//
//				x += 1;
//
//			}
//
//			//check if player has gotten food
//
//			if (grid[food_x] == grid[x] && grid[food_y] == grid[y]) {
//				gotfood = true;
//				Beep(200, 200);
//				tailLength++;
//			}
//
//			//put snek head into map
//			grid[x][y] = 1;
//			//cout << "snek is at " << x << " , " << y << endl;
//
//
//
//
//			redraw = true;
//		}//end timer section
//
//		 /////////////////////////////////////////////////////////////////////////////////////////////////////
//		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
//			break;
//		}
//
//		////////////////////////////////////////////////////////////////////////////////////////////////////
//		//here's the algorithm that turns key presses into events
//		//a "key down" event is when a key is pushed
//		//while a "key up" event is when a key is released
//
//		//has something been pressed on the keyboard?
//		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
//
//			//"keycode" holds all the different keys on the keyboard
//			switch (ev.keyboard.keycode) {
//
//				//    if the up key has been pressed
//			case ALLEGRO_KEY_UP:
//				//cout << "up key pressed";
//				key[0] = true;
//				break;
//
//				//    if the down key has been pressed
//			case ALLEGRO_KEY_DOWN:
//				key[1] = true;
//				break;
//
//				//    if the left key has been pressed
//			case ALLEGRO_KEY_LEFT:
//				key[2] = true;
//				break;
//
//				//if the right key has been pressed
//			case ALLEGRO_KEY_RIGHT:
//				key[3] = true;
//				break;
//			}
//		}
//		//has something been released on the keyboard?
//		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
//			switch (ev.keyboard.keycode) {
//			case ALLEGRO_KEY_UP:
//				key[0] = false;
//				break;
//
//			case ALLEGRO_KEY_DOWN:
//				key[1] = false;
//				break;
//
//			case ALLEGRO_KEY_LEFT:
//				key[2] = false;
//				break;
//
//			case ALLEGRO_KEY_RIGHT:
//				key[3] = false;
//				break;
//
//				//kill the program if someone presses escape
//			case ALLEGRO_KEY_ESCAPE:
//				doexit = true;
//				break;
//			}
//		}
//
//		//    RENDER SECTION
//		if (redraw && al_is_event_queue_empty(event_queue)) {
//
//			redraw = false;
//
//			al_clear_to_color(al_map_rgb(0, 0, 0));
//
//
//
//			//draw map
//			cout << "snek is at " << x << " , " << y << endl;
//			cout << "grid at snek is " << grid[x][y] << endl;
//			for (int i = 0; i < 20; i++)
//				for (int j = 0; j < 20; j++) {
//
//					if (grid[i][j] == 1) {
//
//						al_draw_filled_rectangle(i*SNEKSIZE, j*SNEKSIZE, i*SNEKSIZE + SNEKSIZE, j*SNEKSIZE + SNEKSIZE, al_map_rgb(50, 250, 50));
//					}
//					if (grid[i][j] == 0)
//						al_draw_rectangle(i*SNEKSIZE, j*SNEKSIZE, i*SNEKSIZE + SNEKSIZE, j*SNEKSIZE + SNEKSIZE, al_map_rgb(150, 250, 150), 4);
//
//					if (grid[i][j] == 2) {
//
//						al_draw_filled_rectangle(i*SNEKSIZE, j*SNEKSIZE, i*SNEKSIZE + SNEKSIZE, j*SNEKSIZE + SNEKSIZE, al_map_rgb(50, 50, 150));
//					}
//
//				}
//
//			al_flip_display();
//
//		}//end render
//	}//end game loop
//
//
//
//	al_destroy_sample_instance(instance1);
//	al_destroy_sample(sample);
//	al_destroy_bitmap(snek);
//
//	al_destroy_timer(timer);
//	al_destroy_display(display);
//	al_destroy_event_queue(event_queue);
//
//	return 0;
//
//
//
//
//}