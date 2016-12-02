/*Brockway, Khatri, Tiner
Final Project
Last update: 11-21-16
Purpose: function and class definitons for end window--third window in a gui sequence*/

#include "end_window.h"

using namespace Graph_lib;
using namespace std;

end_window::end_window(Point xy, int w, int h, const string& title, vector<Person>& people, Person& pp, int score, int gt): 
Window(xy, w, h, title), peeps(people), the_player(pp), 
final_score(score), game_type(gt),

//button initializations
play_again(Point(x_max()/2 - 130,y_max() - 50), 120, 40, "play again?", cb_play_again),
logout(Point(x_max()/2 + 10, y_max() - 50), 120, 40, "logout", cb_logout),
enter_pic(Point(x_max()-60, y_max()/2 - 25), 50, 25, "enter", cb_enter_pic),
exit_button(Point(x_max()-35, 0), 35, 20, "exit", cb_exit_button),

//Text initializations
win_message(Point(x_max()/2, 50), "Congratulations! You beat a highscore!"),
loss_message(Point(x_max()/2, 50), "Well, better luck next time. Play again?"),
pic_in(Point(x_max()-170, y_max()/2 - 25), 100, 25, ""),
top_msg(Point(105,85),"Top Player: "),
enter_pic_msg1(Point(x_max()-170, y_max()/2 + 20), "Enter the picture file"),
enter_pic_msg2(Point(x_max()-170, y_max()/2 + 35), "   (*.jpg or *.gif)"),
high_scores_msg(Point(95,215), game_string(game_type) + "High Scores"),
//other initializations
pic_file("default.jpg")
{
	the_player.addScore(gt, score);
	highscore1_proxy{Point(100,230), getPlace(peeps,game_type,1)};
	highscore2_proxy{Point(100,245), getPlace(peeps,game_type,2)};
	highscore3_proxy{Point(100,260), getPlace(peeps,game_type,3)};
	//if statement getting the already top player's pic and reassigning the Image.
	
	Image* proxy = new Image(Point(100,100), pic_file);
	top_pic = proxy;//ugh...^
	
	attach(play_again);
	attach(logout);
	attach(enter_pic);
	top_pic->set_mask(Point(0,0),100,100);
	attach(*top_pic);
	attach(top_msg);
	attach(highscore1_proxy);
	attach(highscore2_proxy);
	attach(highscore3_proxy);
	attach(enter_pic_msg1);
	attach(enter_pic_msg2);
	attach(high_scores_msg);
	attach(exit_button);
	attach(pic_in);
	
	//depending on score attach win or loss message
	//also will need different logic for how the player's score is getting passed in for beating highscores...

}

string game_string(int i){
	switch(i){
		case 3:{
			return "(3x3) ";
			break;
		}
		case 4:{
			return "(4x4) ";
			break;
		}
		case 5:{
			return "(5x5) ";
			break;
		}
		default:{
			return "ERROR: ";
		}
	}
}

void end_window::enter_pic_pressed(){
	cout << pic_in.get_string() << '\n';//test for pic entry and add it to the current person object
	pic_file = pic_in.get_string();
	Image* new_pic = new Image(Point(100,100), pic_file);
	top_pic = new_pic;
	attach(*top_pic);
	redraw();
	
	enter_pic.hide();
	pic_in.hide();
	//picture entry message?
}

int end_window::play_again_pressed(){
	exit_button_pressed();
	try{
		Game_window win2(Point(100,100), 600, 400, "gameplay", peeps, the_player);
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
	login_window win(Point(100,100), 400, 200, "Login", peeps);
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
