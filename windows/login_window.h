/*Brockway, Khatiri, Tiner
Final Project
Last update: 11-14-16
Purpose: header file for login window--first window in the gui design*/

#include <iostream>
#include <sstream>
#include <vector>
#include "Graph.h"
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

struct login_window: Graph_lib::Window
{
	login_window(Point xy, int w, int h, const string& title);// pass in vector of players too?
	Button exit; //quit
	Button login;
	Button new_user;
	Button enter_user;
	Button enter_login;
	Button back;
	
	Text login_message;
	Text new_message;
	Text dne_message;//for telling the user that a name doesn't exist when trying to loging
	Text exist_message;//for telling the user that a name already exists when creating a username
	
	In_box name_in;
	
	void quit_pressed();
	
	void login_pressed();
	
	void new_user_pressed();
	
	int enter_pressed(int i); //changed to int, so matched cpp file
	
	void back_pressed();
	
	
	static void cb_quit(Address, Address);
	static void cb_login(Address, Address);
	static void cb_new_user(Address, Address);
	static void cb_enter_user(Address, Address);
	static void cb_enter_login(Address, Address);
	static void cb_back(Address, Address);
	
};