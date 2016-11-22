/*Brockway, Khatiri, Tiner
Final Project
Last update: 11-21-16
Purpose: function and class definitons for end window--third window in a gui sequence*/

#include "login_window.h"
#include "game_window.h"
#include "end_window.h"

using namespace Graph_lib; //i added this nathan otherwise it wouldn't compile
using namespace std;

end_window::end_window(Point xy, int w, int h, const string& title): 
Window(xy, w, h, title),

//button initializations
play_again(Point(x_max()/2 - 130,y_max() - 50), 120, 40, "play again?", cb_play_again),
logout(Point(x_max()/2 + 10, y_max() - 50), 120, 40, "logout", cb_logout),
enter_pic(Point(x_max()-60, y_max()/2 - 25), 50, 25, "enter", cb_enter_pic),
exit_button(Point(x_max()-35, 0), 35, 20, "exit", cb_exit_button),

//box initializations
//need highscores
//need player score
win_message(Point(x_max()/2, 50), "Congratulations! You beat a highscore!"),
loss_message(Point(x_max()/2, 50), "Well, better luck next time. Play again?"),
pic_in(Point(x_max()-170, y_max()/2 - 25), 100, 25, "")
{
	attach(play_again);
	attach(logout);
	attach(enter_pic);
	attach(exit_button);
	attach(pic_in);
	
	//depending on score attach win or loss message
}

void end_window::enter_pic_pressed(){
	cout << pic_in.get_string() << '\n';//test for pic entry and add it to the current person object
	
	enter_pic.hide();
	pic_in.hide();
	//picture entry message?
}

int end_window::play_again_pressed(){
	exit_button_pressed();
	try{
		Game_window win2(Point(100,100), 600, 400, "gameplay");
		return gui_main();
	}
	catch(...){
		cout << "Something went wrong\n";
		return 1;
	}
}

void end_window::exit_button_pressed(){
	hide();
} 

int end_window::logout_pressed(){
	exit_button_pressed();
	try{
	login_window win(Point(100,100), 400, 200, "gameplay");
		return gui_main();
	}
	catch(...){
		cout << "Something went wrong\n";
		return 1;
	}
}

void end_window::cb_play_again(Address, Address pw){
	reference_to<end_window>(pw).play_again_pressed();
}

void end_window::cb_exit_button(Address, Address pw){
	reference_to<end_window>(pw).exit_button_pressed();
}

void end_window::cb_logout(Address, Address pw){
	reference_to<end_window>(pw).logout_pressed();
}

void end_window::cb_enter_pic(Address, Address pw){
	reference_to<end_window>(pw).enter_pic_pressed();
}