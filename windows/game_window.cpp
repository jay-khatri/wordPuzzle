//game window for project

#include "std_lib_facilities_4.h"
#include <iostream>
#include <sstream>     
#include "Graph.h"     
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

struct Game_window : Graph_lib::Window{
	//constructor
	Game_window(Point xy,
		int w,
		int h,
		const string& title);

private:
	Button but1; //the twenty five buttons
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
	Out_box current_word;

	//Game page buttons
	Button clear_word;
	Button finish_game;
	Button enter_word;

	void quit();

	void three_game(){
		high_scores_3.hide();
		high_scores_4.hide();
		high_scores_5.hide();
		player_scores.hide();
		user_name.hide();
		play_3.hide();
		play_4.hide();
		play_5.hide();

		words_accepted.show();
		current_score.show();
		instructions.show();
		current_word.show();

		clear_word.show();
		finish_game.show();
		enter_word.show();
	}
	void four_game(){
		high_scores_3.hide();
		high_scores_4.hide();
		high_scores_5.hide();
		player_scores.hide();
		user_name.hide();
		play_3.hide();
		play_4.hide();
		play_5.hide();

		words_accepted.show();
		current_score.show();
		instructions.show();
		current_word.show();

		clear_word.show();
		finish_game.show();
		enter_word.show();
	}
	void five_game(){
		high_scores_3.hide();
		high_scores_4.hide();
		high_scores_5.hide();
		player_scores.hide();
		user_name.hide();
		play_3.hide();
		play_4.hide();
		play_5.hide();

		words_accepted.show();
		current_score.show();
		instructions.show();
		current_word.show();

		clear_word.show();
		finish_game.show();
		enter_word.show();
	}

	void clear(){
		current_word.put(""); //clear the word, need to add the functionality of this probabily later
	}
	//void finish();
	void enter(){
		string word = current_word.value; //look here later
		current_word.put("");
		words_accepted.put(word); //will need to change for multiple words
	}

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

//constructor
Game_window::Game_window(Point xy,int w,int h,const string& title) :
	Window(xy, w, h, title),
	//universal logout 
	logout_button(Point(x_max()-80,20),
		70, 20, "logout", cd_logout_button),

	//play buttons
	play_3(Point(30, 60),
		80, 50, "3X3", cd_play_3),
	play_4(Point(30, 120),
		80, 50, "4X4", cd_play_4),
	play_5(Point(30, 180),
		80, 50, "5X5", cd_play_5),

	//high scores for home page
	high_scores_3(Point(200, 60),
		80, 50, "High Scores"),
	high_scores_4(Point(200, 120),
		80, 50, "High Scores"),
	high_scores_5(Point(200, 180),
		80, 50, "High Scores"),
	player_scores(Point(300, 240),
		80, 50, "Player Scores"),
	//displays on home page
	user_name(Point(100, 240),
		70, 20, "User: "),

	//Buttons for the game page
	clear_word(Point(10,y_max()-30),
		80, 20, "Clear Word", cd_clear_word),
	enter_word(Point(10, y_max()-60),
		80, 20, "Enter Word", cd_enter_word),
	finish_game(Point(x_max()-85,y_max()-25),
		80, 20, "Finish", cd_finish_game),
	//Output for the game page
	current_score(Point(100, 50),
		100, 30, "Current Score: "),
	words_accepted(Point(x_max()-70, 70),
		60, 150, "Words Entered: "),
	instructions(Point(100, 10),
		100, 30, "Instructions: "),
	current_word(Point(300,300),
		80, 30, "Current Word: "),

	but1(Point(200,200),
		20,20,'1',cd_but1),
	but2(Point(200,220),
		20,20,'2',cd_but2),
	but3(Point(200,240),
		20,20,'3',cd_but3),
	but4(Point(200,260),
		20,20,'4',cd_but4),
	but5(Point(200,280),
		20,20,'5',cd_but5),

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
	attach(current_word);
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
	current_word.hide();
}

// All the callbacks

void Game_window::cd_logout_button(Address, Address pw){
	reference_to<Game_window>(pw).quit();
}
void Game_window::quit(){
	hide();
}

void Game_window::cd_play_3(Address, Address pw){
	reference_to<Game_window>(pw).three_game();
}

void Game_window::cd_play_4(Address, Address pw){
	reference_to<Game_window>(pw).four_game();
}

void Game_window::cd_play_5(Address, Address pw){
	reference_to<Game_window>(pw).five_game();
}

void Game_window::cd_clear_word(Address, Address pw){
	reference_to<Game_window>(pw).clear();
}

void Game_window::cd_finish_game(Address, Address pw){
	reference_to<Game_window>(pw).quit(); //will probably need to change to finish function
}

void Game_window::cd_enter_word(Address, Address pw){
	reference_to<Game_window>(pw).enter();
}

int main() 
  try {
    // construct the GUI window
    Game_window win(Point(100,100),600,400,"shapes");
    return gui_main();  // inherited from Window; calls FLTK's run
  }
  catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
  }
  catch(...) {
    cerr << "some exception\n";
    return 2;
  }