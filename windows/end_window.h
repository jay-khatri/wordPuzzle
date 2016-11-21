/*Brockway, Khatiri, Tiner
Final Project
Last update: 11-21-16
Purpose: function and class desrciptions for 
login window--third window in a gui sequence*/

#include "login_window.h"
#include "game_window.h"

struct end_window{
	
	end_window(Point xy, int w, int h, const& string& title);//will need to pass in player vector and unique player
	
	Button play_again;
	Button exit_button;
	Button logout;
	Button enter_pic;
	
	Text win_message;
	Text loss_message;
	
	//highscores
	
	Image top_player;
	
	In_box pic_in;
	
	void enter_pic_pressed();
	
	int play_again_pressed();
	
	void exit_button_pressed();
	
	int logout_pressed();
	
	static void cb_play_again(Address, Address);
	static void cb_exit_button(Address, Address);
	static void cb_logout(Address, Address);
	static void cb_enter_pic(Address, Address);
	
}