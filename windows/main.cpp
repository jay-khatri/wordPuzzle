/*Brockway, Khatri, Tiner
Final Project
Last update: 12-2-16
Purpose: This will be the actual main we use for the program*/

#include "login_window.h"
#include "h_Person.h"
#include <vector>

using namespace std;

int main(){
	vector<Person> people; //main persistent data

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
