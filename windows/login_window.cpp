/*Brockway, Khatiri, Tiner
Final Project
Last update: 11-14-16
Purpose: function and class desrciptions for 
login window--first window in the gui design*/

#include "login_window.h"
#include "game_window.h"

void login_window::quit_pressed(){
	hide();
}

void login_window::login_pressed(){
	back.show();
	login.hide();
	new_user.hide();
	enter_login.show();
	name_in.show();
	attach(login_message);
}

void login_window::new_user_pressed(){
	back.show();
	login.hide();
	new_user.hide();
	enter_user.show();
	name_in.show();
	attach(new_message);
}

int login_window::enter_pressed(int i){
	string n = name_in.get_string();
	//check/make a player here:
	if (n=="nate" && i==0){//bool function for checking name
		attach(dne_message);
		cout << "found name: " << n << ".\n";//test messages
		redraw();
	}
	else if (n=="nick" && i==1){
		attach(exist_message);
		cout << "found name: " << n << ".\n";//test messages
		redraw();
	}
	else{
		cout << name_in.get_string() << '\n';//in actual program push back player here.
		quit_pressed();
		try{
			Game_window win2(Point(100,100), 600, 400, "gameplay");
			return gui_main();
		}
		catch(...){
			cout << "Something went wrong\n";
			return 1;
		}//in actual program call game_window here
	}

}

void login_window::back_pressed(){
	back.hide();
	enter_user.hide();
	enter_login.hide();
	name_in.hide();
	detach(login_message);
	detach(new_message);
	detach(dne_message);
	detach(exist_message);
	login.show();
	new_user.show();
}

login_window::login_window(Point xy, int w, int h, const string& title, vector<Person>pp):
Window(xy, w, h, title), peeps(pp),

//button initializations

exit(Point(x_max()-40, 0), 35, 20, "quit", cb_quit),

login(Point(x_max()/2-35, y_max()/2-20), 70, 30, "login", cb_login),

new_user(Point(x_max()/2-35, y_max()/2+20), 70, 30, "new user", cb_new_user),

enter_user(Point(x_max()/2-35, y_max()/2 + 40), 70, 30, "Enter", cb_enter_user),

enter_login(Point(x_max()/2-35, y_max()/2 + 40), 70, 30, "Enter", cb_enter_login),

back(Point(0, 0), 35, 20, "back", cb_back),

//box initializations

login_message(Point(x_max()/2-50, y_max()/2 - 30), "Enter username"),

new_message(Point(x_max()/2-50, y_max()/2 - 30), "Create username"),

dne_message(Point(x_max()/2 - 65, y_max()/2+30), "Username not found"),

exist_message(Point(x_max()/2 - 73, y_max()/2+30), "Username already exists"),

name_in(Point(x_max()/2-60, y_max()/2 - 20), 120, 30, "")

{
	attach(exit);
	attach(login);
	attach(new_user);
	attach(enter_user);
	attach(enter_login);
	attach(back);
	enter_user.hide();
	enter_login.hide();
	back.hide();
	attach(name_in);
	name_in.hide();
}

void login_window::cb_quit(Address, Address pw) {
	reference_to<login_window>(pw).quit_pressed();
}

void login_window::cb_login(Address, Address pw) {
	reference_to<login_window>(pw).login_pressed();
}

void login_window::cb_new_user(Address, Address pw) {
	reference_to<login_window>(pw).new_user_pressed();
}

void login_window::cb_back(Address, Address pw) {
	reference_to<login_window>(pw).back_pressed();
}

void login_window::cb_enter_user(Address, Address pw) {
	reference_to<login_window>(pw).enter_pressed(1);
}

void login_window::cb_enter_login(Address, Address pw) {
	reference_to<login_window>(pw).enter_pressed(0);
}
