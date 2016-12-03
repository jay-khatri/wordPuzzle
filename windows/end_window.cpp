/*Brockway, Khatri, Tiner
Final Project
Last update: 11-21-16
Purpose: function and class definitons for end window--third window in a gui sequence*/

#include "end_window.h"

using namespace Graph_lib;
using namespace std;

bool is_pic(string pic){
	if(pic.substr(pic.length()-4,4)==".jpg" || pic.substr(pic.length()-4,4)==".gif"){
		return 1;
	}
	return 0;
}

bool is_open_pic(string pic){
	ifstream is{pic};
	if(!is){
		return 0;
	}
	return 1;
}

string get_place_name(vector<Person> peeps, int gametype, int place){
	vector<Person> topvec;
	vector<string> places;
	//gets the index of the person with the highest score
	for(int i = 0; i<3 & peeps.size() > 0; i++){
		topvec.push_back(peeps[topIndex(peeps, gametype)]);
		peeps.erase(peeps.begin() + topIndex(peeps, gametype));
	}
	for(int i = 0; i<topvec.size(); i++){
		// string str_place = to_string(i+1);
		// string str_score = to_string(topvec[i].getScores(gametype)[2]);
		string str_name = topvec[i].getName();
		// string fin_string = str_name;
		places.push_back(str_name);
	}
	if (place > 0 && place < 4 && gametype > 2 && gametype < 6){
		//size is 2, place is 1,2,3 (3 should fail)
		if(topvec.size()>=place){ 
			return places[place-1];
		}
		else{
			return "Score DNE";
		}
	}else{
		return "You doing something wrong";
	}
}

end_window::end_window(Point xy, int w, int h, const string& title, vector<Person>& people, Person& pp, int score, int gt, int winner): 
Window(xy, w, h, title), peeps(people), the_player(pp), 
final_score(score), game_type(gt),

//button initializations
play_again(Point(x_max()/2 - 130,y_max() - 50), 120, 40, "play again?", cb_play_again),
logout(Point(x_max()/2 + 10, y_max() - 50), 120, 40, "logout", cb_logout),
enter_pic(Point(x_max()-60, y_max()/2 - 25), 50, 25, "enter", cb_enter_pic),
exit_button(Point(x_max()-35, 0), 35, 20, "exit", cb_exit_button),

//Text initializations
win_message(Point(90, 50), "Congratulations! You got the highest score!"),
loss_message(Point(90, 50), "Well, better luck next time. Play again?"),
placed_message(Point(120, 50), "Nice. You got a high score."),
score_msg(Point(x_max()-150, 100), "Final Score: "+ to_string(final_score)),

// high1_str(getPlace(peeps,game_type,1)),
highscore1_proxy(Point(100,230), getPlace(peeps,game_type,1)),
// high2_str(getPlace(peeps,game_type,2)),
highscore2_proxy(Point(100,245), getPlace(peeps,game_type,2)),
// high3_str(getPlace(peeps,game_type,3)),
highscore3_proxy(Point(100,260), getPlace(peeps,game_type,3)),

pic_in(Point(x_max()-170, y_max()/2 - 25), 100, 25, ""),
top_msg(Point(110,90),"Top Player: "),
high_scores_msg(Point(90,215), game_string(game_type) + "High Scores"),

enter_pic_msg1(Point(x_max()-170, y_max()/2 + 20), "Enter the picture file"),
enter_pic_msg2(Point(x_max()-170, y_max()/2 + 35), "   (*.jpg or *.gif)")

{

	//if statement getting the already top player's pic and reassigning the Image.
	string top_in = get_place_name(peeps, game_type, 1);
	pic_file = getPerson(top_in, peeps).getPic();

	if(is_pic(pic_file)){
		if(is_open_pic(pic_file)){
			//the pic is fine if reaches here
		}
		else{
			pic_file = "default.jpg";
		}
	}
	else{
		pic_file = "default.jpg";
	}
	
	Image* proxy = new Image(Point(100,100), pic_file);
	top_pic = proxy;

	for(int i=0; i<the_player.getScores(game_type).size();++i){
		cout << the_player.getScores(game_type)[i] << endl;
	}
	cout << peeps.size() << endl;
	cout << getPlace(peeps, game_type, 1) << endl;

	
	
	attach(play_again);
	attach(logout);
	top_pic->set_mask(Point(0,0),100,100);
	attach(*top_pic);
	attach(top_msg);

	if(winner==1){
		attach(enter_pic);
		attach(win_message);
		attach(pic_in);
		attach(enter_pic_msg1);
		attach(enter_pic_msg2);
	}
	if(winner==2){
		attach(placed_message);
	}
	if(winner==3){
		attach(loss_message);
	}

	attach(score_msg);
	attach(highscore1_proxy);
	attach(highscore2_proxy);
	attach(highscore3_proxy);
	attach(high_scores_msg);
	attach(exit_button);
	
	//depending on score attach win or loss message
	//also will need different logic for how the player's score is getting passed in for beating highscores...

}

string game_string(int i){
	switch(i){
		case 3:{
			return "(3x3) ";
			break;
		}
		case 4:{
			return "(4x4) ";
			break;
		}
		case 5:{
			return "(5x5) ";
			break;
		}
		default:{
			return "ERROR: ";
		}
	}
}

void end_window::enter_pic_pressed(){
	//cout << pic_in.get_string() << '\n';//test for pic entry and add it to the current person object

	pic_file = pic_in.get_string();
	if(is_pic(pic_file)){
		if(is_open_pic(pic_file)){
		Image* new_pic = new Image(Point(100,100), pic_file);
		top_pic = new_pic;
		attach(*top_pic);
		redraw();
		
		the_player.setPic(pic_file);
		enter_pic.hide();
		pic_in.hide();
		detach(enter_pic_msg1);
		detach(enter_pic_msg2);
		//detach the image not found message
		}
		else{
			//attach a bad image message
		}
	}
	else{
		//attach a bad image message
	}
}

int end_window::play_again_pressed(){
	exit_button_pressed();
	try{
		Game_window win2(Point(100,100), 600, 400, "gameplay", peeps, the_player);
		return gui_main();
	}
	catch(...){
		cout << "Something went wrong\n";
		return 1;
	}
}

void end_window::exit_button_pressed(){
	output_people(peeps);
	hide();
} 

int end_window::logout_pressed(){
	exit_button_pressed();
	try{
	login_window win(Point(100,100), 400, 200, "Login", peeps);
		return gui_main();
	}
	catch(...){
		cout << "Something went wrong\n";
		return 1;
	}
}

void end_window::cb_play_again(Address, Address pw){
	reference_to<end_window>(pw).play_again_pressed();
}

void end_window::cb_exit_button(Address, Address pw){
	reference_to<end_window>(pw).exit_button_pressed();
}

void end_window::cb_logout(Address, Address pw){
	reference_to<end_window>(pw).logout_pressed();
}

void end_window::cb_enter_pic(Address, Address pw){
	reference_to<end_window>(pw).enter_pic_pressed();
}

//person function defenitions ---------------------------------------------
void output_people(vector<Person> input) {
	ofstream ofs("personData.txt");
	for (int s = 0; s<input.size(); s++) {
		ofs << input[s].getName() << endl << input[s].getPic() << endl;
		for(auto i: input[s].getScores(3)){
			ofs << i << " ";
		}
		ofs << endl;
		for(auto i: input[s].getScores(4)){
			ofs << i << " ";
		}
		ofs << endl;
		for(auto i: input[s].getScores(5)){
			ofs << i << " ";
		}
		ofs << endl;
		if(s != input.size()-1){
			ofs << endl;
		}
	}
}

string Person::getPic(){ return pic;}

void Person::setPic(string i_pic){ pic = i_pic;}

Person &getPerson(string name, vector<Person> &peeps){
	for(int i = 0; i<peeps.size(); i++){
		if (peeps[i].getName().find(name) != string::npos) {
			return peeps[i];
		}
	}
}	

