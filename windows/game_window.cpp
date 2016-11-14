//game window for project

#include "std_lib_facilities_4.h"
#include <iostream>
#include <sstream>     
#include "Graph.h"     
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

class Game_window : Graph_lib::window{
	//constructor
	Game_window(Point xy,
		int x,
		int y,
		const string& title);

private:
	Out_box high_scores;
	Out_box player_scores;
	Out_box words_accepetd;
	Out_box current_score;
	Out_box Instructions;
	



public:


}


int main(){
	
}
