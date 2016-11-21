/*This will be the actual main we use for the program*/

#include "login_window.h"
#include "game_window.h"

int main(){
	
	try{
		login_window win(Point(100,100), 400, 200, "login");
		return gui_main();
	}
	catch(...){
		cout << "Something went wrong\n";
		return;
	}();

}