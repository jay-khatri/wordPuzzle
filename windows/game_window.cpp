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
		int x,
		int y,
		const string& title);

private:
	//both pages buttons
	Button logout;

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
	Out_box words_accepetd;
	Out_box current_score;
	Out_box Instructions;

	//Game page buttons
	Button clear_word;
	Button finish_game;
	Button enter_word;

	static void cd_logout(Address, Address);
	static void cd_


public:


}

