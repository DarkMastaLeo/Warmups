#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
using namespace std;
//function to detect collision
//paramaters are x & y coordinates of top left corner of first box, then its width and height
//then same for other box
int bounding_box_collision(int b1_x, int b1_y, int b1_w, int b1_h, int b2_x, int b2_y, int b2_w, int b2_h);

//using constants in this game so you have sensible words, not unknown numbers in code
const float FPS = 60;
const int SCREEN_W = 800;
const int SCREEN_H = 800;
const int BOUNCER_SIZE = 32;

//an enumeration is like a user-defined variable, with all the given values it can hold
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};
enum MYKEYS2 {
	KEY_W, KEY_S, KEY_A, KEY_D
};


int main()
{
	//allegro variables
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *bouncer2 = NULL;

	//initalize variables
	al_init();
	al_init_primitives_addon();
	al_install_keyboard();

	al_init_font_addon(); 
	al_init_ttf_addon();
	ALLEGRO_FONT *font = al_load_ttf_font("Butcherman-Regular.ttf",74,0 );
	ALLEGRO_FONT *barq = al_load_ttf_font("barq.ttf",20,0 );
	timer = al_create_timer(1.0 / FPS);
	display = al_create_display(SCREEN_W, SCREEN_H);
	event_queue = al_create_event_queue();

	//regular variables
	int speed = 4;
	int lives=3;
	float bouncer_x = 30; //put the first box in the middle of the screen
	float bouncer_y = 40;
	bool key[4] = { false, false, false, false };
	float bouncer2_x = 30;
	float bouncer2_y = 40;
	bool key2[4] = { false, false, false, false };
	bool redraw = true;
	bool doexit = false;

	//audio stuff

	ALLEGRO_SAMPLE *sample=NULL; //variable to hold the audio file

	//these two functions initalize the two included audio libraries
	al_install_audio();

	al_init_acodec_addon();

	al_reserve_samples(1);//decides how many samples we're using, creates a default mixer

	//returns a memory address to the music file. make sure it's in your project folder!
	sample = al_load_sample( "omnom.wav" );
	//end audio stuff
	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);

	bouncer2 = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);

	al_set_target_bitmap(bouncer);

	al_clear_to_color(al_map_rgb(255, 0, 255));

	al_set_target_bitmap(bouncer2);

	al_clear_to_color(al_map_rgb(0, 255, 255));

	al_set_target_bitmap(al_get_backbuffer(display));


	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	//draw the initial screen, start up the timer
	al_clear_to_color(al_map_rgb(0,0,0));

	al_flip_display();

	al_start_timer(timer);

	while(!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		cout<<bouncer_x<<" , "<<bouncer_y<<endl;
		cout<<lives<<endl;
		//if a clock ticks, check if we should be moving a square (by checking key or key2)
		if(ev.type == ALLEGRO_EVENT_TIMER) {
			if (lives == 0){
				al_clear_to_color(al_map_rgb(0,0,0));
				al_flip_display();
				al_draw_text(font, al_map_rgb(255,255,255), 400, 400,ALLEGRO_ALIGN_CENTRE, "Game Over");
				al_flip_display();
				al_play_sample(sample, 1.0, 0.0,1,ALLEGRO_PLAYMODE_ONCE,NULL);
				al_rest(3);
				al_destroy_bitmap(bouncer);
				al_destroy_timer(timer);
				al_destroy_display(display);
				al_destroy_event_queue(event_queue);
			}

			
			if(key[KEY_UP] && bouncer_y >= 4.0) {
				bouncer_y -= speed;
			}

			if(key[KEY_DOWN] && bouncer_y <= SCREEN_H - BOUNCER_SIZE - 4.0) {
				bouncer_y += speed;
			}

			if(key[KEY_LEFT] && bouncer_x >= 4.0) {
				bouncer_x -= speed; 
			}

			if(key[KEY_RIGHT] && bouncer_x <= SCREEN_W - BOUNCER_SIZE - 4.0) {
				bouncer_x += speed;
			}
			al_draw_filled_rectangle(750,350,700,300,al_map_rgb(0,0,0));
			al_flip_display();
		

			if(key2[KEY_W] && bouncer2_y >= 4.0) {
				bouncer2_y -= 4.0;
			}

			if(key2[KEY_S] && bouncer2_y <= SCREEN_H - BOUNCER_SIZE - 4.0) {
				bouncer2_y += 4.0;
			}

			if(key2[KEY_A] && bouncer2_x >= 4.0) {
				bouncer2_x -= 4.0;
			}

			if(key2[KEY_D] && bouncer2_x <= SCREEN_W - BOUNCER_SIZE - 4.0) {
				bouncer2_x += 4.0;
			}

			redraw = true;
		}
		//kill program if window "X" has been clicked
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		//update key/key2 if a key has been pressed
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch(ev.keyboard.keycode) {

			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;

			case ALLEGRO_KEY_LEFT: 
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;

			case ALLEGRO_KEY_W:
				key2[KEY_W] = true;
				break;

			case ALLEGRO_KEY_S:
				key2[KEY_S] = true;
				break;

			case ALLEGRO_KEY_A: 
				key2[KEY_A] = true;
				break;

			case ALLEGRO_KEY_D:
				key2[KEY_D] = true;
				break;


			}
		}
		//update key/key2 if a key has been released
		else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch(ev.keyboard.keycode) {

			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_LEFT: 
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;

			case ALLEGRO_KEY_W:
				key2[KEY_W] = false;
				break;

			case ALLEGRO_KEY_S:
				key2[KEY_S] = false;
				break;

			case ALLEGRO_KEY_A: 
				key2[KEY_A] = false;
				break;

			case ALLEGRO_KEY_D:
				key2[KEY_D] = false;
				break;


			}
		}

		//RENDER SECTION
		//clears screen to black
		al_clear_to_color(al_map_rgb(0,0,0));
		//drawing walls b
		al_draw_filled_rectangle(200, 0, 250, 700, al_map_rgb(0,0,250));
		al_draw_filled_rectangle(200, 400, 700, 450, al_map_rgb(0,0,250));
		al_draw_filled_rectangle(700, 400, 650, 700, al_map_rgb(0,0,250));
		//drawing deathwalls
		al_draw_filled_rectangle(500, 600, 550, 800, al_map_rgb(250,0,0));
		al_draw_filled_rectangle(350, 600, 400, 800, al_map_rgb(250,0,0));
		al_draw_filled_rectangle(800, 250, 350, 200, al_map_rgb(250,0,0));
		//piece to collect
		al_draw_filled_rectangle(425,725,475,775,al_map_rgb(0,150,0));
		al_draw_filled_rectangle(75,400,125,450,al_map_rgb(0,150,0));
		al_draw_filled_rectangle(750,350,700,300,al_map_rgb(0,150,0));
		//winning piece
		al_draw_filled_rectangle(700,100,750,150,al_map_rgb(240,255,0));
		al_draw_text(barq, al_map_rgb(255,255,255),700,0,ALLEGRO_ALIGN_CENTRE,"lives");
		al_draw_textf(barq, al_map_rgb(255,255,255),740,0,ALLEGRO_ALIGN_CENTRE, "%d", lives);



		al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);

		al_draw_bitmap(bouncer2, bouncer2_x, bouncer2_y, 0);

		//call the bounding box function. if it returns 1, print out your collision message
		//blueboxes
	

		al_flip_display();
	}
		

	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	return 0;
}

int bounding_box_collision(int b1_x, int b1_y, int b1_w, int b1_h, int b2_x, int b2_y, int b2_w, int b2_h)
{
	if ((b1_x > b2_x + b2_w - 1) || // is b1 on the right side of b2?
		(b1_y > b2_y + b2_h - 1) || // is b1 under b2?
		(b2_x > b1_x + b1_w - 1) || // is b2 on the right side of b1?
		(b2_y > b1_y + b1_h - 1))   // is b2 under b1?
	{
		// no collision
		return 0;
	}

	// collision
	return 1; 
}
