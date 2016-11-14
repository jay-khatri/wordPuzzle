/*Brockway, Khatiri, Tiner
Final Project
Last update: 11-14-16
Purpose: header file for login window--first window in the gui design*/

#include "Window.h"
#include "GUI.h"

class login_window{
	Button exit;
	Button login;
	Button new_player;
	Button enter;
	
	Out_box name_message;
	
	In_box name;
	
	void exit_pressed(){
		quit();//need to create callback for
	}
	
	void login_pressed(){
		player_login();
	}
	
	void new_ply_pressed(){
		new_login();
	}
	
	void enter_pressed(){
		cout << name.get_string() << '\n';
	}
	
}