/*Brockway, Khatri, Tiner
Final Project
Last update: 11-21-16
Purpose: function and class definitons for end window--third window in a gui sequence*/

#include "end_window.h"

using namespace Graph_lib;
using namespace std;

//tests if the file inputted is actually a picture of gif (helper function)
bool is_pic(string pic){
	if(pic.length()<5){
		return 0;
	}
	if(pic.substr(pic.length()-4,4)==".jpg" || pic.substr(pic.length()-4,4)==".gif"){
		return 1;
	}
	return 0;
}

//tests if the file inputted actually exits in the folder (helper function)
bool is_open_pic(string pic){
	ifstream is{pic};
	if(!is){
		return 0;
	}
	return 1;
}

//gets the name of the places to display on the end window (helper function)
string get_place_name(vector<Person> peeps, int gametype, int place){
	vector<Person> topvec;
	vector<string> places;
	//gets the index of the person with the highest score
	for(int i = 0; i<3 & peeps.size() > 0; i++){
		topvec.push_back(peeps[topIndex(peeps, gametype)]);
		peeps.erase(peeps.begin() + topIndex(peeps, gametype));
	}
	for(int i = 0; i<topvec.size(); i++){
		string str_name = topvec[i].getName();
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

//the end window constructor
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

//highscores text initializations
highscore1_proxy(Point(100,230), getPlace(peeps,game_type,1)),
highscore2_proxy(Point(100,245), getPlace(peeps,game_type,2)),
highscore3_proxy(Point(100,260), getPlace(peeps,game_type,3)),
high_scores_msg(Point(90,215), game_string(game_type) + "High Scores"),
top_msg(Point(110,90),"Top Player: "),

//input box for the picture file initializations
pic_in(Point(x_max()-170, y_max()/2 - 25), 100, 25, ""),

//enter picture text initializations
enter_pic_msg1(Point(x_max()-170, y_max()/2 + 20), "Enter the picture file"),
enter_pic_msg2(Point(x_max()-170, y_max()/2 + 35), "(*.jpg or *.gif, 100x100pp)"),

//error text initializations
ext_error(Point(x_max()-170, y_max()/2 + 20), "Try *.jpg or *.gif"),
file_error(Point(x_max()-170, y_max()/2 + 20), "File not found")

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
			the_player.setPic("default.jpg");
		}
	}
	else{
		pic_file = "default.jpg";
		the_player.setPic("default.jpg");
	}

	//actuall sets the new image that will be displayed to the pic file
	Image* proxy = new Image(Point(100,100), pic_file);
	top_pic = proxy;

	//attachs buttons, the image, and a the top message
	attach(play_again);
	attach(logout);
	top_pic->set_mask(Point(0,0),100,100);
	attach(*top_pic);
	attach(top_msg);

	//desides what type of message to display based on what place they were in
	//if they finished first, then they also have the ability to enter a photo
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

	//attaches all the high scores, the exit button, the the score message
	attach(score_msg);
	attach(highscore1_proxy);
	attach(highscore2_proxy);
	attach(highscore3_proxy);
	attach(high_scores_msg);
	attach(exit_button);
}

//outputs the game type name depending the the type of game played
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

//the definition of the function that runs when the picture is attempted to be entered
void end_window::enter_pic_pressed(){
	//this desides if the picture they tried to enter actually exits, and if is a picture
	pic_file = pic_in.get_string();
	if(is_pic(pic_file)){ //tests if the picture is able to be a picture of gif
		if(is_open_pic(pic_file)){ //tests if the picture exits in the folder
		Image* new_pic = new Image(Point(100,100), pic_file);
		top_pic = new_pic;
		attach(*top_pic);
		
		the_player.setPic(pic_file);
		enter_pic.hide();
		pic_in.hide();
		detach(enter_pic_msg1);
		detach(enter_pic_msg2);
		detach(file_error);
		detach(ext_error);
		redraw();
		}
		else{
			detach(enter_pic_msg1); //shows the proper errors if the picture doesnt exits
			detach(enter_pic_msg2);
			detach(file_error);
			detach(ext_error);
			attach(file_error);
			redraw();
		}
	}
	else{
		detach(enter_pic_msg1); //shows the proper erros if the picture file couldn't be a picture
		detach(enter_pic_msg2);
		detach(file_error);
		detach(ext_error);
		attach(ext_error);
		redraw();
	}
}

//is the function if the play again button is pressed, keeps the same user and launches a new game window
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

//outputs the data to the text file, and closes all windows
void end_window::exit_button_pressed(){
	output_people(peeps);
	hide();
} 

//logouts the user, and launches another login window
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

//callback functions -------------------------------------------------------------------------
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

//person function defenitions ----------------------------------------------------------------

//outputs the vector of people to a file which contains all information of the person
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

//returns a persons picture
string Person::getPic(){ return pic;}

//sets a person picture to the entered picture, or possibly the default
void Person::setPic(string i_pic){ pic = i_pic;}

//returns a person object
Person &getPerson(string name, vector<Person> &peeps){
	for(int i = 0; i<peeps.size(); i++){
		if (peeps[i].getName().find(name) != string::npos) {
			return peeps[i];
		}
	}
}	

