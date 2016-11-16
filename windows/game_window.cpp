//game window for project

#include "std_lib_facilities_4.h"
#include <iostream>
#include <sstream>     
#include "Graph.h"     
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

class Game_window : Graph_lib::window{
	//constructor
	Game_window(Point xy,
		int w,
		int h,
		const string& title);

private:
	//both pages buttons
	Button logout_button;

	//Home page text
	Out_box high_scores_3;
	Out_box high_scores_4;
	Out_box high_scores_5;
	Out_box player_scores;
	Out_box user_name;
	//Home page buttons
	Button play_3;
	Button play_4;
	Button play_5;

	//game page text
	Out_box words_accepted;
	Out_box current_score;
	Out_box instructions;

	//Game page buttons
	Button clear_word;
	Button finish_game;
	Button enter_word;

	void logout();

	static void cd_logout_button(Address, Address);

	static void cd_play_3(Address, Address);
	static void cd_play_4(Address, Address);
	static void cd_play_5(Address, Address);

	static void cd_clear_word(Address, Address);
	static void cd_finish_game(Address, Address);
	static void cd_enter_word(Address, Address);

};

//constructor
Game_window::Game_window(Point xy,int w,int h,const string& title) :
	Window(xy, w, h, title),
	//universal logout 
	logout_button(Point(x_max(),0),
		70, 20, "logout", cd_logout_button),

	//play buttons
	play_3(Point(30, 60),
		80, 50, "3X3", cd_play_3),
	play_4(Point(30, 120),
		80, 50, "3X3", cd_play_3),
	play_5(Point(30, 180),
		80, 50, "3X3", cd_play_3),

	//high scores for home page
	high_scores_3(Point(150, 60),
		80, 50, "High Scores"),
	high_scores_4(Point(150, 120),
		80, 50, "High Scores"),
	high_scores_5(Point(150, 180),
		80, 50, "High Scores"),
	player_scores(Point(150, 240),
		80, 50, "Player Scores"),
	//displays on home page
	user_name(Point(30, 240),
		70, 20, "User: "),

	//Buttons for the game page
	clear_word(Point(10,y_max()-10),
		70, 20, "Clear Word", cd_clear_word),
	enter_word(Point(10, y_max-40),
		70, 20, "Enter Word", cd_enter_word),
	finish_game(Point(x_max()-10,y_max()-10),
		70, 20, "Finish", cd_finish_game),
	//Output for the game page
	current_score(Point(300, 300),
		100, 30, "Current Word: ");
	words_accepted(Point(x_max()-80, 70),
		70, 150, "Words Entered: ");
	instructions(Poitn(10, 10),
		100, 30, "Instructions: ")

{
	//should never need to hide
	attach(logout_button);
	//play buttons
	attach(play_3);
	attach(play_4);
	attach(play_5);
	//score outboxs
	attach(high_scores_3);
	attach(high_scores_4);
	attach(high_scores_5);
	attach(player_scores);
	attach(user_name);
	//user_name.put(   ) //need to get their username and put it here
	//will also need to put all the scores here as well

	//game buttons
	attach(clear_word);
	attach(enter_word);
	attach(finish_game);
	//game outboxes
	attach(current_score);
	attach(words_accepted);
	attach(instructions);
	//hie the game page
	clear_word.hide();
	enter_word.hide();
	finish_game.hide();
	current_score.hide();
	words_accepted.hide();
	instructions.hide();
}

// All the callbacks


