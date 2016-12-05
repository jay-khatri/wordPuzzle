/*Brockway, Khatiri, Tiner
Final Project
Last update: 11-14-16
Purpose: header file for login window--first window in the gui design and the class/function declarations*/
#ifndef LOGIN_GUARD
#define LOGIN_GUARD

#include "game_window.h"

#include <iostream>
#include <sstream>
#include <vector>
#include "Graph.h"
#include "GUI.h"
#include "Window.h"
#include "h_Person.h"

using namespace Graph_lib;
using namespace std;

struct login_window: Graph_lib::Window
{
	login_window(Point xy, int w, int h, const string& title, vector<Person>& pp); //window contructor
	vector<Person>& peeps; //player container for referencing a pushing back players
	
	Button exit; //quit
	Button login;
	Button new_user;
	Button enter_user;
	Button enter_login;
	Button back;
	
	Text login_message;
	Text new_message;
	Text dne_message; //for telling the user that a name does not exist when trying to log-in
	Text exist_message; //for telling the user that a name already exists when creating a username
	Text name_error; //for telling the user that their username is ill-formatted
	
	In_box name_in;
	
	void quit_pressed(); //when exit pressed function
	
	void login_pressed(); //when a user wants to login to the game
	
	void new_user_pressed(); //when the user wants to create a new user login
	
	int enter_pressed(int i); //when user enters their username (int depends on whether the user is logining or creating a username)
	
	void back_pressed(); //when user wants to go back to main login window
	
	//----------- call back definitions -------------
	static void cb_quit(Address, Address);
	static void cb_login(Address, Address);
	static void cb_new_user(Address, Address);
	static void cb_enter_user(Address, Address);
	static void cb_enter_login(Address, Address);
	static void cb_back(Address, Address);
	
};

#endif
