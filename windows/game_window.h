//Brookway, Khatri, Tiner
//CSCE 121 Final Project
//game window for project
//this is the h file

#ifndef GAME_GUARD
#define GAME_GUARD 

#include <iostream>
#include <sstream>     
#include "Graph.h"     
#include "GUI.h"
#include "Window.h"
#include <cstdlib>
#include <ctime>
#include <string>

using namespace Graph_lib;
using namespace std;

bool is_entered(string s, vector<string> entered);

struct Game_window : Graph_lib::Window{
	//constructor
	Game_window(Point xy,
		int w,
		int h,
		const string& title);

private:
	//vector of all the words
	vector<string> words;
	//holds all the letters
	vector<string> letters;
	//the current word string the user is adding to
	string the_word;
	//all the entered words in a string
	string all_words;
	//all the words in a vector
	vector<string> entered_words;
	//the game_type the user chooses
	int game_type;
	//the score of the game
	int game_score = 0;
	//text for if the word doesn't exist
	Out_box none_word_message;
	//-----------------------------------------------------------------
	//the twenty five buttons
	Button but1;
	Button but2;
	Button but3;
	Button but4;
	Button but5;
	Button but6;
	Button but7;
	Button but8;
	Button but9;
	Button but10;
	Button but11;
	Button but12;
	Button but13;
	Button but14;
	Button but15;
	Button but16;
	Button but17;
	Button but18;
	Button but19;
	Button but20;
	Button but21;
	Button but22;
	Button but23;
	Button but24;
	Button but25;
	//------------------------------------------------------------------

	//both pages buttons
	Button logout_button;

	//Home page text
	Out_box home_choice;
	Out_box text_3_high;
	Out_box text_4_high;
	Out_box text_5_high;
	Out_box high_scores_3_1;
	Out_box high_scores_3_2;
	Out_box high_scores_3_3;
	Out_box high_scores_4_1;
	Out_box high_scores_4_2;
	Out_box high_scores_4_3;
	Out_box high_scores_5_1;
	Out_box high_scores_5_2;
	Out_box high_scores_5_3;
	Out_box player_scores_3;
	Out_box player_scores_4;
	Out_box player_scores_5;
	Out_box user_name;
	//Home page buttons
	Button play_3;
	Button play_4;
	Button play_5;

	//game page text
	Out_box words_accepted;
	Out_box current_score;
	Out_box instructions;
	Out_box current_word;

	//Game page buttons
	Button clear_word;
	Button finish_game;
	Button enter_word;

	int quit();

	//when the transition from the home page to the window page
	void home_to_game();
	//whos the buttons depending on the game type
	void show_buttons();
	//used to randomize the game buttons letter
	void randomize_buttons();

	//the three game type buttons
	void three_game();
	void four_game();
	void five_game();

	//if they spell something wrong
	void clear();

	int finish();

	//when a word is entered, the score, total words, and current word will change
	void enter();

	//------------------------------------------------------------------
	//all the push buttons functions
	void button_push1();
	void button_push2();
	void button_push3();
	void button_push4();
	void button_push5();
	void button_push6();
	void button_push7();
	void button_push8();
	void button_push9();
	void button_push10();
	void button_push11();
	void button_push12();
	void button_push13();
	void button_push14();
	void button_push15();
	void button_push16();
	void button_push17();
	void button_push18();
	void button_push19();
	void button_push20();
	void button_push21();
	void button_push22();
	void button_push23();
	void button_push24();
	void button_push25();

	//-------------------------------------------------------------------------
	//All the call back functions
	static void cd_logout_button(Address, Address);

	static void cd_play_3(Address, Address);
	static void cd_play_4(Address, Address);
	static void cd_play_5(Address, Address);

	static void cd_clear_word(Address, Address);
	static void cd_finish_game(Address, Address);
	static void cd_enter_word(Address, Address);

	static void cd_but1(Address, Address);
	static void cd_but2(Address, Address);
	static void cd_but3(Address, Address);
	static void cd_but4(Address, Address);
	static void cd_but5(Address, Address);
	static void cd_but6(Address, Address);
	static void cd_but7(Address, Address);
	static void cd_but8(Address, Address);
	static void cd_but9(Address, Address);
	static void cd_but10(Address, Address);
	static void cd_but11(Address, Address);
	static void cd_but12(Address, Address);
	static void cd_but13(Address, Address);
	static void cd_but14(Address, Address);
	static void cd_but15(Address, Address);
	static void cd_but16(Address, Address);
	static void cd_but17(Address, Address);
	static void cd_but18(Address, Address);
	static void cd_but19(Address, Address);
	static void cd_but20(Address, Address);
	static void cd_but21(Address, Address);
	static void cd_but22(Address, Address);
	static void cd_but23(Address, Address);
	static void cd_but24(Address, Address);
	static void cd_but25(Address, Address);
};

#endif