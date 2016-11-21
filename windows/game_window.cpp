//Brookway, Khatri, Tiner
//CSCE 121 Final Project
//game window for project
//this is the cpp file

//#include "std_lib_facilities_4.h"
// #include <iostream>
// #include <sstream>     
// #include "Graph.h"     
// #include "GUI.h"
// #include "Window.h"
// #include <cstdlib>
// #include <ctime>
// #include <string>
#include "game_window.h"

using namespace Graph_lib;
using namespace std;

//function for is the word has already been entered
bool is_entered(string s, vector<string> entered){
	for(int i=0; i<entered.size(), ++i){
		if(entered[i]==string){
			return 0; //if the word has already been entered
		}
	}
	return 1; //if the word is not in the list
}

//when the transition from the home page to the window page
void Game_window::home_to_game(){
	home_choice.hide();
	high_scores_3_1.hide();
	high_scores_3_2.hide();
	high_scores_3_3.hide();
	high_scores_4_1.hide();
	high_scores_4_2.hide();
	high_scores_4_3.hide();
	high_scores_5_1.hide();
	high_scores_5_2.hide();
	high_scores_5_3.hide();
	player_scores_3.hide();
	player_scores_4.hide();
	player_scores_5.hide();
	text_3_high.hide();
	text_4_high.hide();
	text_5_high.hide();
	user_name.hide();
	play_3.hide();
	play_4.hide();
	play_5.hide();

	words_accepted.show();
	current_score.show();
	current_score.put("0");
	instructions.show();
	current_word.show();

	clear_word.show();
	finish_game.show();
	enter_word.show();
}
//whos the buttons depending on the game type
void Game_window::show_buttons(){
	if((game_type == 3) || (game_type == 4) || (game_type == 5)){
		but1.show();
		but2.show();
		but3.show();
		but6.show();
		but7.show();
		but8.show();
		but11.show();
		but12.show();
		but13.show();
	}
	if((game_type == 4) || (game_type==5)){
		but4.show();
		but9.show();
		but14.show();
		but16.show();
		but17.show();
		but18.show();
		but19.show();
	}
	if(game_type == 5){
		but5.show();
		but10.show();
		but15.show();
		but20.show();
		but21.show();
		but22.show();
		but23.show();
		but24.show();
		but25.show();
	}
}
//used to randomize the game buttons letter
//it is 35, instead of 25 because there are 3 of each
//vowel in the letters vector so that vowels are more likely
//to appear since vowels are usually 36% of an average english word
void Game_window::randomize_buttons(){
	if((game_type == 3) || (game_type == 4) || (game_type == 5)){
		but1.label = letters[rand()% 35];
		but2.label = letters[rand()% 35];
		but3.label = letters[rand()% 35];
		but6.label = letters[rand()% 35];
		but7.label = letters[rand()% 35];
		but8.label = letters[rand()% 35];
		but11.label = letters[rand()% 35];
		but12.label = letters[rand()% 35];
		but13.label = letters[rand()% 35];
	}
	if((game_type == 4) || (game_type==5)){
		but4.label = letters[rand()% 35];
		but9.label = letters[rand()% 35];
		but14.label = letters[rand()% 35];
		but16.label = letters[rand()% 35];
		but17.label = letters[rand()% 35];
		but18.label = letters[rand()% 35];
		but19.label = letters[rand()% 35]; 
	}
	if(game_type == 5){
		but5.label = letters[rand()% 35];
		but10.label = letters[rand()% 35];
		but15.label = letters[rand()% 35];
		but20.label = letters[rand()% 35];
		but21.label = letters[rand()% 35];
		but22.label = letters[rand()% 35];
		but23.label = letters[rand()% 35];
		but24.label = letters[rand()% 35];
		but25.label = letters[rand()% 35];
	}
}

//the three game type buttons
void Game_window::three_game(){
	game_type = 3;
	home_to_game();

	randomize_buttons();
	show_buttons();
}
void Game_window::four_game(){
	game_type = 4;
	home_to_game();

	randomize_buttons();
	show_buttons();
}
void Game_window::five_game(){
	game_type = 5;
	home_to_game();

	randomize_buttons();
	show_buttons();
}

//if they spell something wrong
void Game_window::clear(){
	current_word.put("");
	the_word = "";

	show_buttons();
}

//void finish();

//when a word is entered, the score, total words, and current word will change
void Game_window::enter(){
	// if (isword(words, the_word) && is_ented(the_word, entered_words)){
		detach(none_word_message);
		entered_words.push_back(the_word);
		all_words = the_word + " " + all_words;
		words_accepted.put(all_words);

		game_score = game_score + the_word.length(); //adds the score
		stringstream ss;
		ss << game_score;
		current_score.put(ss.str());
	// }
	// else{
	// 	attach(none_word_message);
	// }

	current_word.put(""); //will be done whether that is a word or not
	the_word = ""; 
	show_buttons();
}

//------------------------------------------------------------------
//all the push buttons functions
void Game_window::button_push1(){
	the_word = the_word + but1.label;
	current_word.put(the_word);
	but1.hide();
}
void Game_window::button_push2(){
	the_word = the_word + but2.label;
	current_word.put(the_word);
	but2.hide();
}
void Game_window::button_push3(){
	the_word = the_word + but3.label;
	current_word.put(the_word);
	but3.hide();
}
void Game_window::button_push4(){
	the_word = the_word + but4.label;
	current_word.put(the_word);
	but4.hide();
}
void Game_window::button_push5(){
	the_word = the_word + but5.label;
	current_word.put(the_word);
	but5.hide();
}
void Game_window::button_push6(){
	the_word = the_word + but6.label;
	current_word.put(the_word);
	but6.hide();
}
void Game_window::button_push7(){
	the_word = the_word + but7.label;
	current_word.put(the_word);
	but7.hide();
}
void Game_window::button_push8(){
	the_word = the_word + but8.label;
	current_word.put(the_word);
	but8.hide();
}
void Game_window::button_push9(){
	the_word = the_word + but9.label;
	current_word.put(the_word);
	but9.hide();
}
void Game_window::button_push10(){
	the_word = the_word + but10.label;
	current_word.put(the_word);
	but10.hide();
}
void Game_window::button_push11(){
	the_word = the_word + but11.label;
	current_word.put(the_word);
	but11.hide();
}
void Game_window::button_push12(){
	the_word = the_word + but12.label;
	current_word.put(the_word);
	but12.hide();
}
void Game_window::button_push13(){
	the_word = the_word + but13.label;
	current_word.put(the_word);
	but13.hide();
}
void Game_window::button_push14(){
	the_word = the_word + but14.label;
	current_word.put(the_word);
	but14.hide();
}
void Game_window::button_push15(){
	the_word = the_word + but15.label;
	current_word.put(the_word);
	but15.hide();
}
void Game_window::button_push16(){
	the_word = the_word + but16.label;
	current_word.put(the_word);
	but16.hide();
}
void Game_window::button_push17(){
	the_word = the_word + but17.label;
	current_word.put(the_word);
	but17.hide();
}
void Game_window::button_push18(){
	the_word = the_word + but18.label;
	current_word.put(the_word);
	but18.hide();
}
void Game_window::button_push19(){
	the_word = the_word + but19.label;
	current_word.put(the_word);
	but19.hide();
}
void Game_window::button_push20(){
	the_word = the_word + but20.label;
	current_word.put(the_word);
	but20.hide();
}
void Game_window::button_push21(){
	the_word = the_word + but21.label;
	current_word.put(the_word);
	but21.hide();
}
void Game_window::button_push22(){
	the_word = the_word + but22.label;
	current_word.put(the_word);
	but22.hide();
}
void Game_window::button_push23(){
	the_word = the_word + but23.label;
	current_word.put(the_word);
	but23.hide();
}
void Game_window::button_push24(){
	the_word = the_word + but24.label;
	current_word.put(the_word);
	but24.hide();
}
void Game_window::button_push25(){
	the_word = the_word + but25.label;
	current_word.put(the_word);
	but25.hide();
}
//-----------------------------------------------------------------------

//constructor
Game_window::Game_window(Point xy,int w,int h,const string& title) :
	Window(xy, w, h, title),
	//universal logout 
	logout_button(Point(x_max()-80,20),
		70, 20, "logout", cd_logout_button),

	//play buttons
	play_3(Point(30, 60),
		90, 60, "3X3", cd_play_3),
	play_4(Point(30, 140),
		90, 60, "4X4", cd_play_4),
	play_5(Point(30, 220),
		90, 60, "5X5", cd_play_5),

	//high scores for home page, and text boxes
	home_choice(Point(30, 20),
		350, 20, ""),
	text_3_high(Point(135,80),
		115, 20, ""),
	text_4_high(Point(135,160),
		115, 20, ""),
	text_5_high(Point(135,240),
		115, 20, ""),
	high_scores_3_1(Point(300, 60),
		80, 20, "1st:"),
	high_scores_3_2(Point(300, 80),
		80, 20, "2nd:"),
	high_scores_3_3(Point(300, 100),
		80, 20, "3rd:"),
	high_scores_4_1(Point(300, 140),
		80, 20, "1st:"),
	high_scores_4_2(Point(300, 160),
		80, 20, "2nd:"),
	high_scores_4_3(Point(300, 180),
		80, 20, "3rd:"),
	high_scores_5_1(Point(300, 220),
		80, 20, "1st:"),
	high_scores_5_2(Point(300, 240),
		80, 20, "2nd:"),
	high_scores_5_3(Point(300, 260),
		80, 20, "3rd:"),
	player_scores_3(Point(300, 300),
		80, 20, "1st:"),
	player_scores_4(Point(300, 320),
		80, 20, "2nd:"),
	player_scores_5(Point(300, 340),
		80, 20, "3rd:"),
	//displays on home page
	user_name(Point(72, 300),
		115, 30, "User: "),

	//test for the game page
	none_word_message(Point(300,350),
		"Word doesn't exist!"),
	//Buttons for the game page
	clear_word(Point(10,y_max()-30),
		80, 20, "Clear Word", cd_clear_word),
	enter_word(Point(10, y_max()-60),
		80, 20, "Enter Word", cd_enter_word),
	finish_game(Point(x_max()-85,y_max()-25),
		80, 20, "Finish", cd_finish_game),
	//Output for the game page
	current_score(Point(85, 50),
		100, 30, "Score: "),
	words_accepted(Point(200, y_max()-40),
		300, 30, "Words Entered: "),
	instructions(Point(85, 10),
		350, 30, "Instructions: "),
	current_word(Point(300,320),
		80, 30, "Current Word: "),

//--------Defining the game buttons------------------------------------------------------------
	but1(Point(200,100),
		40,40,"1",cd_but1),
	but2(Point(200,140),
		40,40,"2",cd_but2),
	but3(Point(200,180),
		40,40,"3",cd_but3),
	but4(Point(200,220),
		40,40,"4",cd_but4),
	but5(Point(200,260),
		40,40,"5",cd_but5),

	but6(Point(240,100),
		40,40,"6",cd_but6),
	but7(Point(240,140),
		40,40,"7",cd_but7),
	but8(Point(240,180),
		40,40,"8",cd_but8),
	but9(Point(240,220),
		40,40,"9",cd_but9),
	but10(Point(240,260),
		40,40,"10",cd_but10),

	but11(Point(280,100),
		40,40,"11",cd_but11),
	but12(Point(280,140),
		40,40,"12",cd_but12),
	but13(Point(280,180),
		40,40,"13",cd_but13),
	but14(Point(280,220),
		40,40,"14",cd_but14),
	but15(Point(280,260),
		40,40,"15",cd_but15),

	but16(Point(320,100),
		40,40,"16",cd_but16),
	but17(Point(320,140),
		40,40,"17",cd_but17),
	but18(Point(320,180),
		40,40,"18",cd_but18),
	but19(Point(320,220),
		40,40,"19",cd_but19),
	but20(Point(320,260),
		40,40,"20",cd_but20),

	but21(Point(360,100),
		40,40,"21",cd_but21),
	but22(Point(360,140),
		40,40,"22",cd_but22),
	but23(Point(360,180),
		40,40,"23",cd_but23),
	but24(Point(360,220),
		40,40,"24",cd_but24),
	but25(Point(360,260),
		40,40,"25",cd_but25)

//------Constructor continued------------------------------------------------------------
{
	//should never need to hide
	attach(logout_button);
	//play buttons
	attach(play_3);
	attach(play_4);
	attach(play_5);
	//test outboxes
	attach(home_choice);
	home_choice.put("Choose the size word search you would like to play.");
	attach(text_3_high);
	text_3_high.put("3X3 High Scores");
	attach(text_4_high);
	text_4_high.put("4X4 High Scores");
	attach(text_5_high);
	text_5_high.put("5X5 High Scores");
	//score outboxs
	attach(high_scores_3_1); //---------------------------------------
	attach(high_scores_3_2); //need to put stuff from person call here
	attach(high_scores_3_3); //---------------------------------------
	attach(high_scores_4_1);
	attach(high_scores_4_2);
	attach(high_scores_4_3);
	attach(high_scores_5_1);
	attach(high_scores_5_2);
	attach(high_scores_5_3);
	attach(player_scores_3);
	attach(player_scores_4);
	attach(player_scores_5);
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
	instructions.put("Spell words by clicking on the buttons to make a word. Click enter when a word is spelled, and finish when you are done with your game.");
	instructions.hide();
	current_word.hide();

	//-------------------------------------------------------------------
	//attaching hiding the game buttons
	attach(but1);
	attach(but2);
	attach(but3);
	attach(but4);
	attach(but5);
	attach(but6);
	attach(but7);
	attach(but8);
	attach(but9);
	attach(but10);
	attach(but11);
	attach(but12);
	attach(but13);
	attach(but14);
	attach(but15);
	attach(but16);
	attach(but17);
	attach(but18);
	attach(but19);
	attach(but20);
	attach(but21);
	attach(but22);
	attach(but23);
	attach(but24);
	attach(but25);
	but1.hide();
	but2.hide();
	but3.hide();
	but4.hide();
	but5.hide();
	but6.hide();
	but7.hide();
	but8.hide();
	but9.hide();
	but10.hide();
	but11.hide();
	but12.hide();
	but13.hide();
	but14.hide();
	but15.hide();
	but16.hide();
	but17.hide();
	but18.hide();
	but19.hide();
	but20.hide();
	but21.hide();
	but22.hide();
	but23.hide();
	but24.hide();
	but25.hide();

	//-----Letter Vector---------------------------------------------------------
	letters.push_back("a");
	letters.push_back("b");
	letters.push_back("c");
	letters.push_back("d");
	letters.push_back("e");
	letters.push_back("f");
	letters.push_back("g");
	letters.push_back("h");
	letters.push_back("i");
	letters.push_back("j");
	letters.push_back("k");
	letters.push_back("l");
	letters.push_back("m");
	letters.push_back("n");
	letters.push_back("o");
	letters.push_back("p");
	letters.push_back("q");
	letters.push_back("r");
	letters.push_back("s");
	letters.push_back("t");
	letters.push_back("u");
	letters.push_back("v");
	letters.push_back("w");
	letters.push_back("x");
	letters.push_back("y");
	letters.push_back("z");
	letters.push_back("a"); //increases the likelyhood of a vowel to about 36%
	letters.push_back("a");
	letters.push_back("e");
	letters.push_back("e");
	letters.push_back("i");
	letters.push_back("i");
	letters.push_back("o");
	letters.push_back("o");
	letters.push_back("u");
	letters.push_back("u");
}

//------------------------------------------------------------------------
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

//----------------------------------------------------------------------
//the game buttons callbacks

void Game_window::cd_but1(Address, Address pw){
	reference_to<Game_window>(pw).button_push1();
}
void Game_window::cd_but2(Address, Address pw){
	reference_to<Game_window>(pw).button_push2();
}
void Game_window::cd_but3(Address, Address pw){
	reference_to<Game_window>(pw).button_push3();
}
void Game_window::cd_but4(Address, Address pw){
	reference_to<Game_window>(pw).button_push4();
}
void Game_window::cd_but5(Address, Address pw){
	reference_to<Game_window>(pw).button_push5();
}
void Game_window::cd_but6(Address, Address pw){
	reference_to<Game_window>(pw).button_push6();
}
void Game_window::cd_but7(Address, Address pw){
	reference_to<Game_window>(pw).button_push7();
}
void Game_window::cd_but8(Address, Address pw){
	reference_to<Game_window>(pw).button_push8();
}
void Game_window::cd_but9(Address, Address pw){
	reference_to<Game_window>(pw).button_push9();
}
void Game_window::cd_but10(Address, Address pw){
	reference_to<Game_window>(pw).button_push10();
}
void Game_window::cd_but11(Address, Address pw){
	reference_to<Game_window>(pw).button_push11();
}
void Game_window::cd_but12(Address, Address pw){
	reference_to<Game_window>(pw).button_push12();
}
void Game_window::cd_but13(Address, Address pw){
	reference_to<Game_window>(pw).button_push13();
}
void Game_window::cd_but14(Address, Address pw){
	reference_to<Game_window>(pw).button_push14();
}
void Game_window::cd_but15(Address, Address pw){
	reference_to<Game_window>(pw).button_push15();
}
void Game_window::cd_but16(Address, Address pw){
	reference_to<Game_window>(pw).button_push16();
}
void Game_window::cd_but17(Address, Address pw){
	reference_to<Game_window>(pw).button_push17();
}
void Game_window::cd_but18(Address, Address pw){
	reference_to<Game_window>(pw).button_push18();
}
void Game_window::cd_but19(Address, Address pw){
	reference_to<Game_window>(pw).button_push19();
}
void Game_window::cd_but20(Address, Address pw){
	reference_to<Game_window>(pw).button_push20();
}
void Game_window::cd_but21(Address, Address pw){
	reference_to<Game_window>(pw).button_push21();
}
void Game_window::cd_but22(Address, Address pw){
	reference_to<Game_window>(pw).button_push22();
}
void Game_window::cd_but23(Address, Address pw){
	reference_to<Game_window>(pw).button_push23();
}
void Game_window::cd_but24(Address, Address pw){
	reference_to<Game_window>(pw).button_push24();
}
void Game_window::cd_but25(Address, Address pw){
	reference_to<Game_window>(pw).button_push25();
}
//---------------------------------------------------------------------------
