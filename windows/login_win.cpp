/*Brockway, Khatiri, Tiner
Final Project
Last update: 11-14-16
Purpose: header file for login window--first window in the gui design*/

#include "std_lib_facilities_4.h"

#include <iostream>
#include <sstream>
#include <vector>
#include "Graph.h"
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

struct Log_window: Graph_lib::Window
{
	Log_window(Point xy, int w, int h, const string& title);// pass in vector of players too?
	Button exit; //quit
	Button login;
	Button new_user;
	Button enter;
	Button back;
	
	Text login_message;
	Text new_message;
	
	In_box name_in;
	
	void quit_pressed(){
		quit();//need to create callback for
	}
	
	void login_pressed(){
		back.show();
		login.hide();
		new_user.hide();
		enter.show();
		name_in.show();
		attach(login_message);
	}
	
	void new_user_pressed(){
		back.show();
		login.hide();
		new_user.hide();
		enter.show();
		name_in.show();
		attach(new_message);
	}
	
	void enter_pressed(){
		cout << name_in.get_string() << '\n';
		back_pressed();
	}
	
	void back_pressed(){
		back.hide();
		enter.hide();
		name_in.hide();
		detach(login_message);
		detach(new_message);
		login.show();
		new_user.show();
	}
	
	void quit(){
		hide();
	}
	
	static void cb_quit(Address, Address);
	static void cb_login(Address, Address);
	static void cb_new_user(Address, Address);
	static void cb_enter(Address, Address);
	static void cb_back(Address, Address);
	
};

Log_window::Log_window(Point xy, int w, int h, const string& title):// pass in vector of players too?
Window(xy, w, h, title),

//button initializations

exit(Point(x_max()-40, 0), 35, 20, "quit", cb_quit),

login(Point(x_max()/2-35, y_max()/2-20), 70, 30, "login", cb_login),

new_user(Point(x_max()/2-35, y_max()/2+20), 70, 30, "new user", cb_new_user),

enter(Point(x_max()/2-35, y_max()/2 + 40), 70, 30, "Enter", cb_enter),

back(Point(0, 0), 35, 20, "back", cb_back),

//box initializations

login_message(Point(x_max()/2-50, y_max()/2 - 30), "Enter username"),

new_message(Point(x_max()/2-50, y_max()/2 - 30), "Create username"),

name_in(Point(x_max()/2-30, y_max()/2 - 20), 60, 30, "")

{
	attach(exit);
	attach(login);
	attach(new_user);
	attach(enter);
	attach(back);
	enter.hide();
	back.hide();
	attach(name_in);
	name_in.hide();
	
}

void Log_window::cb_quit(Address, Address pw) {
	reference_to<Log_window>(pw).quit_pressed();
}

void Log_window::cb_login(Address, Address pw) {
	reference_to<Log_window>(pw).login_pressed();
}

void Log_window::cb_new_user(Address, Address pw) {
	reference_to<Log_window>(pw).new_user_pressed();
}

void Log_window::cb_back(Address, Address pw) {
	reference_to<Log_window>(pw).back_pressed();
}

void Log_window::cb_enter(Address, Address pw) {
	reference_to<Log_window>(pw).enter_pressed();
}

int main(){
	try{
		Log_window win(Point(100,100), 200, 200, "login");
		return gui_main();
	}
	catch(...){
		cout << "You done messed up\n";
		return 1;
	}
}