/*Brockway, Khatiri, Tiner
Final Project
Last update: 11-21-16
Purpose: header file for end window--third window in a gui sequence*/

#ifndef END_GUARD
#define END_GUARD

#include "game_window.h"
#include "login_window.h"
#include "h_Person.h"
//#include "h_dictionary.h"

#include <iostream>
#include <sstream>
#include <vector>
#include "Graph.h"
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

struct end_window: Graph_lib::Window {
	
	end_window(Point xy, int w, int h, const string& title);//will need to pass in player vector and unique player
	end_window(Point xy, int w, int h, const string& title, vector<Person>& people, Person& pp, int score);
	vector<Person> peeps;
	Person the_player;
	int final_score;
	
	Button play_again;
	Button exit_button;
	Button logout;
	Button enter_pic;
	
	Text win_message;
	Text loss_message;
	
	//highscores
	Text highscore1_proxy;
	Text highscore2_proxy;
	Text highscore3_proxy;
	//player score
	
	Image* top_pic; //only accepts .jpg or .gif
	string pic_file;
	
	In_box pic_in;
	
	void enter_pic_pressed();
	
	int play_again_pressed();
	
	void exit_button_pressed();
	
	int logout_pressed();
	
	static void cb_play_again(Address, Address);
	static void cb_exit_button(Address, Address);
	static void cb_logout(Address, Address);
	static void cb_enter_pic(Address, Address);
	
};

#endif