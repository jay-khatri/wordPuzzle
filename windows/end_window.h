/*Brockway, Khatri, Tiner
Final Project
Last update: 11-21-16
Purpose: header file for end window--third window in a gui sequence*/

#ifndef END_GUARD
#define END_GUARD

#include "game_window.h"
#include "login_window.h"
#include "h_Person.h"

#include <iostream>
#include <sstream>
#include <vector>
#include "Graph.h"
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

struct end_window: Graph_lib::Window {
	
	end_window(Point xy, int w, int h, const string& title, vector<Person>& people, Person& pp, int score, int gt, int winner);
	vector<Person>& peeps; //the vector that holds all the current players
	Person& the_player; //the user who is playing
	int final_score; //the final score with which they finished
	int game_type; //the type of game that was played
	
	//the buttons
	Button play_again;
	Button exit_button;
	Button logout;
	Button enter_pic;
	//text for the type of winner message given
	Text win_message;
	Text loss_message;
	Text placed_message;
	//text for the scores messages
	Text score_msg;
	Text high_scores_msg;
	Text top_msg;
	//text for enter pic operations
	Text enter_pic_msg1;
	Text enter_pic_msg2;
	Text ext_error;
	Text file_error;
	//highscores
	Text highscore1_proxy;
	string high1_str;
	Text highscore2_proxy;
	string high2_str;
	Text highscore3_proxy;
	string high3_str;
	
	Image* top_pic; //only accepts .jpg or .gif
	string pic_file;
	//inbox to enter the picture file name
	In_box pic_in;
	
	//the definitions of all the buttons pressed operations----------------------------------------------------
	//the definition of the function that runs when the picture is attempted to be entered
	void enter_pic_pressed();
	
	//is the function if the play again button is pressed, keeps the same user and launches a new game window
	int play_again_pressed();

	//outputs the data to the text file, and closes all windows
	void exit_button_pressed();
	
	//logouts the user, and launches another login window
	int logout_pressed();
	
	//the callback functions for the buttons-------------------------------------------------------------------
	static void cb_play_again(Address, Address);
	static void cb_exit_button(Address, Address);
	static void cb_logout(Address, Address);
	static void cb_enter_pic(Address, Address);
	
};

//outputs the game type name depending the the type of game played
string game_string(int i);

#endif