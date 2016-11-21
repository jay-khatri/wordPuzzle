/*This will be the actual main we use for the program*/

#include "login_window.h"
#include "game_window.h"

void run_login(){
	try{
		login_window win(Point(100,100), 400, 200, "login");
		return gui_main();
	}
	catch(...){
		cout << "Something went wrong\n";
		return;
	}
}

void run_game(){
	try{
		Game_window win2(Point(100,100), 600, 400, "gameplay");
		return gui_main();
	}
	catch(...){
		cout << "Something went wrong\n";
		return;
	}
}

int main(){
	
	run_login();

	run_game();

}