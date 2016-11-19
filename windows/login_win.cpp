/*Brockway, Khatiri, Tiner
Final Project
Last update: 11-14-16
Purpose: header file for login window--first window in the gui design*/

#include "Window.h"
#include "GUI.h"
#include <ostream>
#include <sstream>
#incluse <vector>

using namespace Graph_lib;
using namespace std;


class login_window: Graph_lib:: Window{
	public:
		login_window(Point xy, int w, int h, const string& title);// pass in vector of players too?
	
	Button exit; //quit
	Button login;
	Button new_player;
	Button enter;
	Button back;
	
	Out_box login_message;
	Out_box new_message;
	
	In_box name_in;
	
	void quit_pressed(){
		quit();//need to create callback for
	}
	
	void login_pressed(){
		back.show();
		login.hide();
		new_player.hide();
		enter.show();
		name_in.show();
		login_message.show();
	}
	
	void new_ply_pressed(){
		back.show();
		login.hide();
		new_player.hide();
		enter.show();
		name_in.show();
		new_message.show();
	}
	
	void enter_pressed(){
		cout << name_in.get_string() << '\n';
		back_pressed();
	}
	
	void back_pressed(){
		back.hide();
		name_in.hide();
		login_message.hide();
		new_message.hide();
		login.show();
		new_player.show();
	}
	
	void quit(){
		hide();
	}
	
	static void cb_quit(Address, Address);
	static void cb_login(Address, Address);
	static void cb_new_user(Address, Address);
	static void cb_enter(Address, Address);
	static void cb_back(Address, Address);
	
}

login_window::login_window(Point xy, int w, int h, const string& title):// pass in vector of players too?
Window(xy, w, h, title),

//button initializations

exit(Point(x_max()-30, 0), 30, 15, "quit", cb_quit),

login(Point(x_max()/2-30, y_max()/2 - 40), 60, 30, "login", cb_login),

new_user(Point(x_max()/2+30, y_max()/2 + 40), 60, 30, "Create Login", cb_new_user),

enter(Point(x_max()/2+30, y_max()/2 + 40), 60, 30, "Enter", cb_enter),

back(Point(0, 0), 30, 15, "back", cb_back),

//box initializations

login_message(Point(x_max()/2-30, y_max()/2 - 70), 60, 30, "Enter username"),

new_user_message(Point(x_max()/2-30, y_max()/2 - 70), 60, 30, "Create username"),

name_in(Point(x_max()/2-30, y_max()/2 - 40), 60, 30, ""),

{
	attach(exit);
	attach(login);
	attach(new_user);
	attach(enter);
	attach(back);
	enter.hide();
	back.hide();
	login_message.attach();
	login_message.hide();
	new_user_message.attach();
	new_user_message.hide();
	name_in.attach();
	name_in.hide();
	
}

void login_window::cb_quit(Address, Address pw){
	reference_to<login_window>(pw).quit();
}
void login_window::cb_login(Address, Address pw){
	reference_to<login_window>(pw).login_pressed();
}
void login_window::cb_new_user(Address, Address pw){
	reference_to<login_window>(pw).new_ply_pressed();
}
void login_window::cb_enter(Address, Address pw){
	reference_to<login_window>(pw).enter_pressed();
}
void login_window::cb_back(Address, Address pw) {
	reference_to<login_window>(pw).back_pressed();
}

int main(){
	try{
		login_window win(Point(100,100), 200, 200, "login");
		return gui_main();
	}
	catch(...){
		cout << "You done messed up\n";
		return 1;
	}
}