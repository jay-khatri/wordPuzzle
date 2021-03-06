/*Brockway, Khatri, Tiner
Final Project
Last update: 12-2-16
Purpose: function and class desrciptions for 
login window -- first window in the gui design and its function definitions*/

#include "login_window.h"

void login_window::quit_pressed(){
	output_people(peeps);
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
	string n = name_in.get_string(); //user input
	
	switch (i){
		case 0:{ //Login:
			if (!isPerson(n,peeps)){ // didn't find player (bad)
				detach(dne_message);
				attach(dne_message);				
				redraw();
			}
			else{ //player exists in vector peeps		
				quit_pressed();
				try{
					Game_window win2(Point(100,100), 600, 400, "gameplay", peeps, getPerson(n,peeps));
					return gui_main();
				}
				catch(...){
					cout << "Something went wrong\n";
					return 1;
				}
			}
			break;
		}
		case 1:{ //New user:
			if (isPerson(n,peeps)){ // found player (bad)
				detach(exist_message);
				detach(name_error);
				attach(exist_message);
				redraw();
			}
			else{
				if(n!="" && n!=" " && n.size()>2){ //name format checking
					Person p(n,"");
					peeps.push_back(p);

					quit_pressed();
					try{
						Game_window win2(Point(100,100), 600, 400, "gameplay", peeps, getPerson(n,peeps));
						return gui_main();
					}
					catch(...){
						cout << "Something went wrong\n";
						return 1;
					}
				}
				else{ //name was ill-formatted
					detach(exist_message);
					detach(name_error);
					attach(name_error);
					redraw();
				}
		
			}
			break;
		}
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
	detach(name_error);
	login.show();
	new_user.show();
}

login_window::login_window(Point xy, int w, int h, const string& title, vector<Person>&pp):
Window(xy, w, h, title), peeps(pp),

//button initializations

exit(Point(x_max()-40, 0), 35, 20, "quit", cb_quit),

login(Point(x_max()/2-35, y_max()/2-20), 70, 30, "login", cb_login),

new_user(Point(x_max()/2-35, y_max()/2+20), 70, 30, "new user", cb_new_user),

enter_user(Point(x_max()/2-35, y_max()/2 + 40), 70, 30, "Enter", cb_enter_user),

enter_login(Point(x_max()/2-35, y_max()/2 + 40), 70, 30, "Enter", cb_enter_login),

back(Point(0, 0), 35, 20, "back", cb_back),

//Text message initializations

login_message(Point(x_max()/2-50, y_max()/2 - 30), "Enter username"),

new_message(Point(x_max()/2-50, y_max()/2 - 30), "Create username"),

dne_message(Point(x_max()/2 - 65, y_max()/2+30), "Username not found"),

exist_message(Point(x_max()/2 - 73, y_max()/2+30), "Username already exists"),

name_error(Point(75, y_max()/2+30), "Invalid username (must be at least 3 chars)"),

//box initializations

name_in(Point(x_max()/2-60, y_max()/2 - 20), 120, 30, "")

{	
	//attaching/hide widgets----------------------------
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

//call back functions ---------------------------------------
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
