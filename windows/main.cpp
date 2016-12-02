/*This will be the actual main we use for the program*/

#include "login_window.h"
#include "h_Person.h"
#include "h_dictionary.h"
#include <vector>
// #include "game_window.h"

using namespace std;

int main(){
	vector<string> words;
	vector<Person> people;

	//input_data(words);

	input_people(people);

	try{
		login_window win(Point(100,100), 400, 200, "login", people);
		return gui_main();
	}
	catch(...){
		cout << "Something went wrong\n";
		return 1;
	};

}